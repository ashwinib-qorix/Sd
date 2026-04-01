/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name     : Sd_Cfg_C.xtend
 *
 * Description   : It Provides template for generating configuration for Sd_Cfg.c file
 *
 * Prev.Safety compliant AUTOSAR release version:R23-11
 *
 * Prev.Safety compliant AUTOSAR SW version: 1.0.0
 * 
 * Design ID     : SD_SDD_0341
 */

/*
 * Revision History:
 * Date            Changed By             Description
 * 07-July-2025    Samarth Golwalker  Migration Release R24-11.
 * 08-Aug-2025     Gourav Purohit     Version Updated to 0.2.0.
 * 01-Sep-2025     Gourav Purohit     Version Updated to 0.3.0.

 */


package com.kpit.c4k.bsw.sd.codegen

import com.kpit.c4k.bsw.extensions.ctypes.CStruct
import com.kpit.c4k.bsw.extensions.ctypes.Member
import com.kpit.c4k.bsw.templates.Cfg_C_Template
import com.kpit.c4k.core.workflow.annotations.WorkflowComponent
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Dem
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdBlocklistedVersions
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdConsumedEventGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdEventHandler
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdServiceGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdRoutingGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdSocketConnectionGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.TcpIp
import java.util.ArrayList
import java.util.HashMap
import java.util.List
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdServiceGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdBlocklistedVersions
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig
import static com.kpit.c4k.bsw.sd.codegen.Sd_Cfg_H.*
import java.util.Arrays
import java.lang.reflect.Array
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdGeneral

/*
 * Provides template for generating configuration for Sd C source file.
 * To be extended by the class providing content to be generated.
 */

@WorkflowComponent
class Sd_Cfg_C extends Cfg_C_Template <Sd> {

  extension Sd_Cfg_H = Sd_Cfg_H.EXTENSION_CFG_H
 


  var Sd_Gserverstructinst = 0
  var Sd_Gclientstructinst = 0
  var Soad_Gcon_grps = 0
  var Sd_Ginst_cnt = 0
  var Sd_Gclienttimer_cnt = 0
  var Sd_GEveHandlerstructinst = 0
  var ServertimerIdx = 0
  var ddRxUnicastSoConId = 0
  var ddRxMulticastSoConId = 0
  var baseSocketConIndex = 0
  var no_of_sockets = 0
  var act_server_routing_grp = new HashMap<String, String>()
  var act_client_routing_grp = new HashMap<String, String>()
  var act_consumed_eve_routing_grp = new HashMap<String, String>()
  var act_eve_hand_udp_routing_grp = new HashMap<String, String>()
  var act_eve_hand_tcp_routing_grp = new HashMap<String, String>()
  var act_eve_hand_routing_grp =  new HashMap<String, String>()
  var sd_con_eve_tcp_ref_arr = new HashMap<String, String>()
  var sd_con_eve_udp_ref_arr = new HashMap<String, String>()
  var sd_eve_handler_tcp_ref_arr = new HashMap<String, String>()
  var sd_eve_handler_udp_ref_arr = new HashMap<String, String>()
  var sd_eve_hand_multi_soc_con = new HashMap<String, String>()
  
  
  var client_timer_cnt = 0
  var Sd_GConsumedEvstructinst = 0
  Double Sd_main_func_period
  Integer IpAddrSoConId = null
  Integer DemErrorMalformedId = null
  Integer DemErrorOutOfResId = null
  Integer DemErrorSubEventgroupNacId = null
  SoAd _soad
  Sd _Sd
  Dem _dem
  SdBlocklistedVersions BL
  
  /*create hash map and store values*/
  HashMap<String, List<Integer>> soc_con_path_ids_hash = new HashMap<String, List<Integer>>()
  var sd_con_eve_grp_hash = new HashMap<String, HashMap<Integer, ArrayList<String>>>()
  HashMap<String, Integer> soad_connections = new HashMap<String,Integer>()
  HashMap<String, Integer> soad_tx_pduref_hash = new HashMap<String,Integer>()
  HashMap<String, Integer> dem_eve_parm_hash = new HashMap<String,Integer>()
  HashMap<String, Integer> soad_connectionGroups = new HashMap<String,Integer>()
  HashMap<String, Integer> soAdRoutingGroups_hash = new HashMap<String, Integer>()
  var soc_con_ids = new ArrayList<Integer>()
  var server_service_arr = new ArrayList<String>()
  var client_soc_congrp_arr = new ArrayList<String>()
  var Soad_cnt_arr = new ArrayList<String>()
  var Sd_grp_arr = new ArrayList<String>()
  var inst_uni_multicast_rx_pdu = new ArrayList<Integer>()
  var server_handle_ids = new ArrayList<Integer>()
  var client_handle_ids = new ArrayList<Integer>()
  var consumed_eve_grp_id_hash = new HashMap<String, ArrayList<HashMap<String, Integer>>>()
  var soAdRoutingGroups_arr = new ArrayList<String>()
  var server_service_cnt = new ArrayList<String>()
  var client_service_cnt = new ArrayList<String>()
  var consumed_eve_grp_cnt = new ArrayList<String>()
  var eve_hand_cnt = new ArrayList<String>()
  var no_of_Instances = new ArrayList<String>()
  var soad_soc_con_grps = new ArrayList<String>()
  var Soad_client_con_ev_grp = new ArrayList<String>()
  var sort_used_soc_con_grp_arr = new ArrayList<String>()
   var sort_used_ser_grp_arr = new ArrayList<String>()
  var con_eve_grp_handle_ids = new ArrayList<Integer>()
    List<SdServiceGroup> sdServiceGroups 
  List<SdInstance> sdInstances
  List<SoAdRoutingGroup> soad_rout_grps
  List<SdGeneral> Sd_KPIT
 
  var cstruct = new ArrayList<CStruct>
  var cstruct3 = new ArrayList<CStruct>
   var cstruct2 = new ArrayList<CStruct>
  var ramstruct = new ArrayList<CStruct>
    var ramstruct3 = new ArrayList<CStruct>
      var ramstruct4 = new ArrayList<CStruct>
        var cstruct5 = new ArrayList<CStruct>
  
   var ramstruct2 = new ArrayList<CStruct>
  var config_opt_inst_hstnm_hash = get_config_opt_inst_hstnm_index()
  var server_timer_arr = get_server_timer_arr()  
   
  /*
  * Returns Module Name
  */
  override protected getModuleClass() {
  return Sd
  }

  /*
   * Returns current template version
   */
  override protected getTemplateVersion() {
  return "0.3.0"
  }

   /*
   * Generates include section in the output file.
   *
   * @param None.
   * @return Nothing.
   */
  override protected writeIncludeSection() {
  super.writeIncludeSection()
  write('''
         /*******************************************************************************
         **                   MISRA-C:2012 violations Section                          **
         *******************************************************************************/
         /**
         * #page misra_violations MISRA-C:2012 violations
         *
         * #section Sd_Cfg_C_REF_1
         * Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be
         * preceded by preprocessor directives or comments
         *
         * #section Sd_Cfg_C_REF_2
         * Violates MISRA 2012 Required Dir-1.1, [L] Number of macro definitions exceeds
         * 4095 - program does not conform strictly to ISO:C99.
         **/
         /*#violates #ref Sd_Cfg_C_REF_1 Violates MISRA 2012 Required Rule 20.1*/
         /*PRQA S 5087 EOF */
         /* violates #ref Sd_Cfg_C_REF_2 Violates MISRA 2012 Dir-1.1 */
         /* PRQA S 0380 EOF */
         
         /** #section Sd_Cfg_C_REF_1
             * Violates MISRA 2012 Advisory Rule 20.1,
             * #include directives should only be preceded by preprocessor directives or
             * comments.
             *
             **/
             
            /**
              *
              * #section Sd_Cfg_C_REF_1
              * Violates MISRA 2012 Advisory Rule 1.1,
              * Number of Macro definitions exceed 1024.
              *
              **/
              
            /* Violates #ref Sd_Cgf_C_REF_1 Violates MISRA 2012 Required Rule 20.1 */
            /* PRQA S 5087 EOF */
                #include "Sd_Cfg.h"
            /* Violates #ref Sd_Cfg_C_REF_1 Violates MISRA 2012 Required Rule 1.1 */
            /* PRQA S 0857 EOF */
	        /* Violates #ref Sd_Cfg_C_REF_2 Violates INT02 Msg(qac-10.1.0-1290) */
            /*PRQA S 1290 EOF*/
			/* Violates #ref Sd_Cfg_C_REF_2 Violates INT02 DCL06,EXP07 Msg(qac-10.1.0-3132) */
			/*PRQA S 3132 EOF*/
			/* #Violates #ref SD_Cfg_C_REF_2 PRE08 Msg(certccm-2.1.0-5002)  */
            /*PRQA S 5002 EOF*/
			/* #Violates #ref SD_Cfg_REF_2 CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
           
      /* #Violates #ref SD_Cfg_REF_2 CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
             /*PRQA S 4810 EOF */
	/*#Violates #ref SD_Cfg_REF_2 CMN-0:CMN-0.1,CMN-0.1   M3CM-2:Rule-9.3 Msg(qac-10.1.0-0686)*/
         /*PRQA S 0686 EOF */
         
         
         /******************************************************************************/
             #include "Sd.h"
             #include "Sd_IntTypes.h"
             #include "Sd_Internal.h"
             #include "Sd_Version.h"
         
  ''')
  }

  override protected writeInitializationStructure() {
  super.writeInitializationStructure()

  var modulePrefix = modulePrefix
  Sd_main_func_period = module?.sdGeneral?.sdMainFunctionCycleTime

  _soad = findModule(SoAd)
  _dem = findModule(Dem)
  findModule(TcpIp)

  var config_opt_event_handler = get_config_opt_eve_handler()
  var config_opt_serv_cap_rec = get_config_opt_serv_cap_rec()
  var config_opt_sd_inst_hstname = get_config_opt_inst_hstname()
  var config_opt_total_length = get_config_opt_total_length()
  var config_opt_client_cap_rec = get_config_opt_client_cap_rec()
  var config_opt_consumed_eve = get_config_opt_consumed_eve()
  server_service_arr = get_server_service_arr()
  client_soc_congrp_arr = get_client_soc_congrp_arr()
  sd_con_eve_tcp_ref_arr = get_sd_con_eve_tcp_ref()
  sd_con_eve_udp_ref_arr = get_sd_con_eve_udp_ref()
  sd_eve_handler_tcp_ref_arr = get_sd_eve_handler_tcp_ref_arr()
  sd_eve_handler_udp_ref_arr = get_sd_eve_handler_udp_ref_arr()
  server_service_cnt = get_server_services_cnt()
  client_service_cnt = get_client_services_cnt()
  consumed_eve_grp_cnt = get_consumed_eve_grp_cnt()
  eve_hand_cnt = get_eve_handler_cnt()
  no_of_Instances = get_no_of_Instances()
  inst_uni_multicast_rx_pdu = get_inst_uni_multicast_rx_pdu()
  act_client_routing_grp = get_act_cl_routing_grp()
  act_server_routing_grp = get_act_ser_routing_grp()
  act_consumed_eve_routing_grp = get_act_consumed_eve_routing_grp()
  act_eve_hand_udp_routing_grp = get_act_eve_handler_udp_routing_grp()
  act_eve_hand_tcp_routing_grp = get_act_eve_handler_tcp_routing_grp()
  act_eve_hand_routing_grp = get_act_eve_handler_routing_grp()
  sd_eve_hand_multi_soc_con = get_sd_eve_handler_multi_soc_con()
  client_timer_cnt = get_client_timer_cnt()
  Soad_client_con_ev_grp = get_Soad_client_con_ev_grp()
  sd_con_eve_grp_hash = get_sd_con_eve_grp_hash()
  consumed_eve_grp_id_hash = get_consumed_eve_grp_id_hash()
  con_eve_grp_handle_ids = get_con_eve_grp_handle_ids()
  Soad_cnt_arr = get_Soad_cnt_arr()
  server_handle_ids = get_server_handle_ids()
  client_handle_ids = get_client_handle_ids()
  sdServiceGroups =  module.sdConfig.sdServiceGroups_PB
  sdInstances = module.sdConfig.sdInstances 
 // Sd_KPIT =  module.sdGeneral
  sort_used_ser_grp_arr = get_service_grp_arr1() 
  fill_soad_con_array()
  fill_soad_details()
  get_used_soc_con_grp_arr()

  write('''
    
    #if (SD_RAM_BLOCK == STD_ON)
    #define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #include "Sd_MemMap.h"
    Sd_ProviderConsumerListType Sd_GaaClient_Server_List[SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER];
    #define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #include "Sd_MemMap.h"
    #endif
    «««.........................Start For Sd_GaaServerHandleMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF server_handle_ids.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaServerHandleMapArray */
    const Sd_ServicesType Sd_GaaServerHandleMapArray[«server_handle_ids.size»] = {
         «var Lserver_hand_ids = get_serv_handlemaparray()»
         «FOR index : Lserver_hand_ids»
         «index»«IF index == Lserver_hand_ids.last»«ELSE»,«ENDIF»
         «ENDFOR»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

    «««.........................Start For Sd_GaaClientHandleMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF client_handle_ids.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaClientHandleMapArray */
    const Sd_ServicesType Sd_GaaClientHandleMapArray[«client_handle_ids.size»] = {
      «var Lcli_hand_ids = get_cli_handlemaparray()»
      «FOR index : Lcli_hand_ids»
      «index»«IF index == Lcli_hand_ids.last»«ELSE»,«ENDIF»
      «ENDFOR»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

    «««.........................Start For Sd_GaaConEvGrpHandleMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF con_eve_grp_handle_ids.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaConEvGrpHandleMapArray */
    const Sd_ServicesType Sd_GaaConEvGrpHandleMapArray[«con_eve_grp_handle_ids.size»] = {
      «var Lconseve_hand_ids = get_conEvGrpHandleMapArray()»
      «FOR index : Lconseve_hand_ids»
      «index»«IF index == Lconseve_hand_ids.last»«ELSE»,«ENDIF»
      «ENDFOR»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

    «««.........................Start For Sd_GaaRxPduMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF no_of_Instances.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaRxPduMapArray */
    const Sd_ServicesType Sd_GaaRxPduMapArray[«(no_of_Instances.size)*2»] = {
    «get_rxpdumaparray()»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

    «««.........................Start For Sd_GSaaConfigurationOption Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    
    «IF config_opt_total_length > 0»
    #define «modulePrefix»_START_SEC_CONFIG_DATA_8
    #include "Sd_MemMap.h"
    «/* Design ID : SD_SDD_0055  */»
    /* Sd_GSaaConfigurationOption */
    static const uint8 Sd_GSaaConfigurationOption[«config_opt_total_length»] = {
    	
    «IF config_opt_serv_cap_rec.size > 0»
    «FOR conf_options: config_opt_serv_cap_rec»
      «conf_options»,
      «ENDFOR»
    «ENDIF»
    «IF config_opt_event_handler.size > 0»
    «FOR conf_options: config_opt_event_handler»
      «conf_options»,
      «ENDFOR»
     «ENDIF»
    «IF config_opt_client_cap_rec.size > 0»
    «FOR conf_options: config_opt_client_cap_rec»
      «conf_options»,
      «ENDFOR»
      «ENDIF»
    «IF config_opt_consumed_eve.size > 0»
    «FOR conf_options: config_opt_consumed_eve»
      «conf_options»,
      «ENDFOR»
      «ENDIF»
    «IF config_opt_sd_inst_hstname.size > 0»
    «FOR conf_options: config_opt_sd_inst_hstname»
      «conf_options»,
      «ENDFOR»
      «ENDIF»
    };
    #define «modulePrefix»_STOP_SEC_CONFIG_DATA_8
    #include "Sd_MemMap.h"
    «ENDIF»

     «««.........................Start For Sd_GaaSoConId Array............................»»
    «/* Design ID : SD_SDD_0055 */»
    «IF soc_con_ids.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaSoConId */
    const SoAd_SoConIdType Sd_GaaSoConId[«soc_con_ids.size»] = 
    {
      «FOR ids : soc_con_ids»
      «ids»«IF ids != soc_con_ids.last»,«ELSE»«ENDIF»«ENDFOR»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

    «««.........................Start For Sd_GaaMulticastSoConGrpIndex Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF Soad_client_con_ev_grp.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaMulticastSoConGrpIndex */
    const SoAd_SoConIdType Sd_GaaMulticastSoConGrpIndex[«Soad_client_con_ev_grp.size»] = {
    «multicast_soc_con_ind()»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»

     «««.........................Start For Sd_GSaaServerTimerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF sdInstances.map[sdServerTimers].flatten.size > 0»
    «Sd_GSaaServerTimerStatic»
    «ENDIF»

    «««.........................Start For Sd_GaaServerServiceStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF server_service_cnt.size > 0»
    «Sd_GaaServerServiceStatic»
    «ENDIF»

    «««.........................Start For Sd_GaaEvHandlerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF eve_hand_cnt.size > 0»
    «Sd_GaaEvHandlerStatic»
    «ENDIF»

        «««.........................Start For Sd_GSaaClientTimerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF client_timer_cnt > 0»
    «Sd_GSaaClientTimerStatic»
    
    «ENDIF»

    «««.........................Start For Sd_GaaClientServiceStatic Array............................»»
    «/* Design ID : SD_SDD_0055 */»
    «IF client_service_cnt.size > 0»
      «Sd_GaaClientServiceStatic»   
    «ENDIF»

    «««.........................Start For Sd_GaaConsumedEvGrpStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF consumed_eve_grp_cnt.size > 0»
    «Sd_GaaConsumedEvGrpStatic»
    «ENDIF»

    «««.........................Start For Sd_GaaSoConGroupStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF sort_used_soc_con_grp_arr.size > 0»
      «Sd_GaaSoConGroupStatic»
    «ENDIF»

    «««.........................Start For Sd_GaaInstanceStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF sdInstances.size > 0»
     «Sd_GaaInstanceStatic»   
    «ENDIF»
    
    «««.........................Start For Sd_GaaServicegroupStatic Array............................»»
     «Sd_GaaServicegroupStatic()»
   
 «««.............   /* «Sd_GaaClientProviderAddress()»*/......................»» 
                  «IF (module?.sdGeneral?.sdEnableAclPolicyCheck) == true»
                     «Sd_GaaClientProviderAddress()»
 «««.............   /* «Sd_GaaServerConsumerAddress()»*/......................»»                    
                     «Sd_GaaServerConsumerAddress()»
                  «ENDIF»
     «««.........................Start For Sd_GaaServicegroupClientArray Array............................»» 
   «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
   «Sd_GaaServicegroupClientArray(module)»
   «ENDIF»
       
      «««.........................Start For Sd_GaaServicegroupServerArray Array............................»» 
      «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdServerServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
      «Sd_GaaServicegroupServerArray(module)»
      «ENDIF»
      «««.........................Start For Sd_GaaServicegroupClientStatic Array............................»» 
      «IF((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
      «Sd_GaaServicegroupClientStatic()»
      «ENDIF»
      «««.........................Start For Sd_GaaServicegroupServertStatic Array............................»» 
      «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdServerServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten?.size>0))»
      «Sd_GaaServicegroupServertStatic()»
      «ENDIF»
      
   
  «/* Design ID : SD_SDD_0444,SD_SDD_0446,SD_SDD_6022,SD_SDD_6023,SD_SDD_6024  */»
  «/* Design ID : SD_SDD_6025,SD_SDD_6020,SD_SDD_6021,SD_SDD_0560,SD_SDD_0562 */»
  «/* Design ID : SD_SDD_0561,SD_SDD_6026,SD_SDD_0564,SD_SDD_6027,SD_SDD_0563 */»
  «/* Design ID : SD_SDD_6028,SD_SDD_6029,SD_SDD_0565,SD_SDD_0557,SD_SDD_0556 */»
  «/* Design ID : SD_SDD_60331,SD_SDD_0559,SD_SDD_0558,SD_SDD_0444 */»
  «/* Design ID : SD_SDD_0446,SD_SDD_513,SD_SDD_6030,SD_SDD_0571,SD_SDD_0570 */»
  «/* Design ID : SD_SDD_0573,SD_SDD_0572,SD_SDD_0575,SD_SDD_0574,SD_SDD_0577*/»
  «/* Design ID : SD_SDD_0576,SD_SDD_0568,SD_SDD_0600,SD_SDD_0567,SD_SDD_0569*/»   
 
    «IF (module?.sdConfig?.sdAclCheckBlockDescriptorRef?.nvMNvBlockLength !== null) || (module.sdGeneral.sdEnableAclPolicyCheck.booleanValue == true)»
      «Sd_GaaSd_NvMRomBlockData()»
      «ENDIF»
    «IF (module?.sdConfig?.sdAclCheckBlockDescriptorRef?.nvMNvBlockLength !== null) »
    «Sd_GaaSd_NvMRamBlockData()»
    «ENDIF»
      
    
            
    ''')

  }

 def addComm(ArrayList<String> rxpdu_id)
 {
  var ret_val = ''
  var count = 0
    for(index : rxpdu_id)
    {
      count++
      if(count < rxpdu_id.size)
      {
      ret_val += index+",\n"
      }
      else
      {
       ret_val += index
      }
     }
    return ret_val
 }

   /*
   * Collecting ServerServiceHandleId
   * @param None
   * @return array
   */
  def get_serv_handlemaparray()
  {
    var array = new ArrayList<Integer>()
    var arr_ids = new ArrayList<Integer>()

    arr_ids = server_handle_ids

    for(ids: arr_ids.sort)
  {
    if(server_handle_ids.contains(ids))
    {
      array.add(server_handle_ids.indexOf(ids))
    }
  }
    return array
  }

   /*
   * Collecting ClientServiceHandleId
   * @param None
   * @return array
   */
  def get_cli_handlemaparray()
  {
    var array = new ArrayList<Integer>()
    var arr_ids = new ArrayList<Integer>()

    arr_ids = client_handle_ids

    for(ids: arr_ids.sort)
  {
    if(client_handle_ids.contains(ids))
    {
      array.add(client_handle_ids.indexOf(ids))
    }
  }
    return array
  }

   /*
   * Collecting ConsumedEventGroupHandleId
   * @param None
   * @return array
   */
  def get_conEvGrpHandleMapArray()
  {
    var array = new ArrayList<Integer>()
    var arr_ids = new ArrayList<Integer>()

    arr_ids = con_eve_grp_handle_ids

    for(ids: arr_ids.sort)
  {
    if(con_eve_grp_handle_ids.contains(ids))
    {
      array.add(con_eve_grp_handle_ids.indexOf(ids))
    }
  }
    return array
  }

  /*
   *
   * @param None
   * @return array
   */
  def get_rxpdumaparray()
  {
  var ind = 0
    var str = ''

    inst_uni_multicast_rx_pdu.sort
  for(ind = 0; ind < inst_uni_multicast_rx_pdu.size; ind++)
  {
    for(inst : sdInstances)
    {
      if(inst_uni_multicast_rx_pdu?.sort.get(ind) == inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
      {

        str += no_of_Instances.indexOf(inst?.shortNamePath?.toString).toString+","
      }
      if(inst_uni_multicast_rx_pdu?.sort.get(ind) == inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
      {

        str += no_of_Instances.indexOf(inst?.shortNamePath?.toString).toString+","
      }
    }
  }
  str = str.substring(0,str.length()-1)
  str = str.replace(",",",\n")
    return str
  }

   /*
   *
   * @param None
   * @return None
   */
  def fill_soad_details()
  {
    soad_rout_grps = _soad?.soAdConfig?.soAdRoutingGroups
    if(!(_soad?.soAdConfig?.soAdPduRoutes.nullOrEmpty))
    {
      for(soad_pdu_routes: _soad?.soAdConfig?.soAdPduRoutes)
      {
        soad_pdu_routes?.soAdPduRouteDests
        for(soad_tx_pduref : soad_pdu_routes?.soAdTxPduRef_PB)
        {
          soad_tx_pduref_hash.put(soad_tx_pduref?.reference?.shortNamePath?.toString, soad_pdu_routes?.soAdTxPduId)
        }
      }
    }
    for(soad_rout_grp : soad_rout_grps)
    {
      soAdRoutingGroups_arr.add(soad_rout_grp?.shortNamePath?.toString)
      soAdRoutingGroups_hash.put(soad_rout_grp?.shortNamePath?.toString, soad_rout_grp?.soAdRoutingGroupId)
    }
  }

  /*
   *
   * @param None
   * @return None
   */
  def fill_soad_con_array()
  {
    soc_con_ids = new ArrayList<Integer>
    var con_ids = new ArrayList<Integer>
    for(iter1:_soad?.soAdConfig?.soAdSocketConnectionGroups)
    {
      soad_soc_con_grps.add((iter1?.shortNamePath)?.toString)
      if(server_service_arr.contains((iter1?.shortNamePath)?.toString) == true)
      {
        con_ids = new ArrayList<Integer>
        for(iter2 : iter1?.soAdSocketConnections)
        {
          soad_connections.put(iter2?.shortNamePath?.toString, iter2.soAdSocketId)
          if(!soad_connectionGroups.containsKey(iter1?.shortNamePath?.toString))
          {
            soad_connectionGroups.put(iter1?.shortNamePath?.toString,iter2.soAdSocketId)
          }
          if(!soc_con_ids.contains(iter2?.soAdSocketId))
          {
            soc_con_ids.add(iter2?.soAdSocketId)
          }
          con_ids.add(iter2.soAdSocketId)
          soc_con_path_ids_hash.put(iter1?.shortNamePath?.toString, con_ids)
        }
      }
       if(client_soc_congrp_arr.contains((iter1?.shortNamePath)?.toString) == true)
       {
         con_ids = new ArrayList<Integer>
         for(iter2 : iter1?.soAdSocketConnections)
         {
          soad_connections.put(iter2?.shortNamePath?.toString, iter2?.soAdSocketId)
          if(!soad_connectionGroups.containsKey(iter1?.shortNamePath?.toString))
          {
          soad_connectionGroups.put(iter1?.shortNamePath?.toString, iter2.soAdSocketId)
          }
          if(!soc_con_ids.contains(iter2?.soAdSocketId))
          {
            soc_con_ids.add(iter2?.soAdSocketId)
          }
          con_ids.add(iter2?.soAdSocketId)
          soc_con_path_ids_hash.put(iter1?.shortNamePath?.toString, con_ids)
         }
       }
       if(server_service_arr.contains((iter1?.shortNamePath)?.toString) == false
         || client_soc_congrp_arr.contains((iter1?.shortNamePath)?.toString) == false
         )
       {
         for(iter2 : iter1.soAdSocketConnections)
         {
           soad_connections.put(iter2?.shortNamePath?.toString, iter2?.soAdSocketId)
          if(!soad_connectionGroups.containsKey(iter1?.shortNamePath?.toString))
          {
         
           soad_connectionGroups.put(iter1?.shortNamePath?.toString, iter2.soAdSocketId)
          }

         }
       }

    }
  }

   /*
   *
   * @param None
   * @return None
   */

  def Sd_GSaaServerTimerStatic(){
  cstruct.clear
       val str = '''
    #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h"
    static const Sd_ServerTimerStaticType Sd_GSaaServerTimerStatic[«(sdInstances.map[get_server_timer_arr1]
    	.flatten.size
    )»] =
    {'''
       val stp =
    '''};
 #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
 #include "Sd_MemMap.h" '''
 
 
 server_timer_static()
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
}
  

  def server_timer_static()
  {
     for (sd_inst : sdInstances)
    {
      var Timer = get_server_timer_arr1 /*sdInstances.map[get_server_timer_arr1].flatten.size*/
      
      for (Server_Timer : Timer)
      {
      	cstruct += new CStruct()=>
      	[
      		comment = '''Sd_GSaaServerTimerStatic_«ServertimerIdx++» - «sd_inst?.shortName»_«Server_Timer.shortName»'''
      	    members += new Member()=>
      	    [
      	    	comment = '''ulServerTimerTtlsec'''
      	    	for (serv_timer_ttl : Server_Timer.sdServerTimerTTL_PB)
      	    	{
      	    		value = '''«serv_timer_ttl?.integerValue?.toHex+'U'»'''
      	    	}
      	    ]
      	    members += new Member()=>
      	    [
      	    	comment = '''ulInitialOfferDelayMax'''
      	    	if (!(Server_Timer.sdServerTimerInitialOfferDelayMax_PB.nullOrEmpty))
      	    	{
      	    	   for (serv_time_del_max : Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.toList)
      	    	   {
      	    	   		if(serv_time_del_max.floatValue !==null)
	      	    	   	{
	      	    	   		value = ''' «(serv_time_del_max?.floatValue/Sd_main_func_period).intValue.toHex»'''
	      	    	   	}
	      	    	   	else
		      	    	{
		      	    		value = "SD_TIMER_UNUSED"
		      	    	}
      	    	   }
      	    	}
      	    	else
      	    	{
      	    		value = "SD_TIMER_UNUSED"
      	    	}
      	    ]
      	    
      	    members += new Member()=>
      	    [
      	    	 comment = '''ulInitialOfferDelayMin'''
      	    	 if (!(Server_Timer.sdServerTimerInitialOfferDelayMin_PB.nullOrEmpty))
      	    	 {
      	    	 	for(serv_time_del_min : Server_Timer.sdServerTimerInitialOfferDelayMin_PB?.toList)
      	    	 	{
      	    	 		value = '''«(serv_time_del_min?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	}
      	    	 }
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	comment = '''ulInitialOfferRepetitionBaseDelay'''
      	    	if (!(Server_Timer.sdServerTimerInitialOfferRepetitionBaseDelay_PB.nullOrEmpty))
      	        {
      	    	   for (serv_time_rep_base_delay : Server_Timer.sdServerTimerInitialOfferRepetitionBaseDelay_PB?.toList) 
      	    	   {
      	    	   	 value = '''«(serv_time_rep_base_delay?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	   }
      	        }
      	        else 
      	        {
      	        	value = "SD_TIMER_UNUSED"
      	        }    
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulTimerOfferCyclicDelay'''
      	    	 if (!(Server_Timer.sdServerTimerOfferCyclicDelay_PB.nullOrEmpty))
      	    	 {
      	    	 	for(serv_time_cyclic_delay : Server_Timer.sdServerTimerOfferCyclicDelay_PB?.toList)
      	    	 	{
      	    	 		value = '''«(serv_time_cyclic_delay?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	}
      	    	 }
      	    	 
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulRequestResponseMaxDelay'''
      	    	 if (!(Server_Timer.sdServerTimerRequestResponseMaxDelay_PB.nullOrEmpty))
      	    	 {
      	    	 	 for (serv_time_reqresp_maxdelay : Server_Timer.sdServerTimerRequestResponseMaxDelay_PB)
      	    	 	 {
      	    	 	 	value = '''«(serv_time_reqresp_maxdelay?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	 }
      	    	 }
      	    	 
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }   
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulRequestResponseMinDelay'''
      	    	 if (!(Server_Timer.sdServerTimerRequestResponseMinDelay_PB.nullOrEmpty))
      	    	 {
      	    	 	for (serv_time_reqresp_mindelay : Server_Timer.sdServerTimerRequestResponseMinDelay_PB)
      	    	 	{
      	    	 		value = ''' «(serv_time_reqresp_mindelay?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	}
      	    	 }
      	    	 else
      	    	 {
      	    	 	 value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = ''' ucInitialOfferRepetitionsMax '''
      	    	 if (!(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB.nullOrEmpty))
      	    	 {
      	    	 	 for (serv_time_reqresp_rep_max : Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.toList)
      	    	 	 {
      	    	 	 	if(serv_time_reqresp_rep_max?.integerValue !== null)
      	    	 	 	{
      	    	 	 		value = ''' «(serv_time_reqresp_rep_max?.integerValue).toHex»'''
      	    	 	 	}
      	    	 	 	else
		      	    	{
		      	    	 	value = "SD_TIMER_UNUSED"
		      	    	}
      	    	 	 	
      	    	 	 }
      	    	 }
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]      	      	
      	]
      	}    	
      }
      return cstruct
    }


	def getSdServerTimerTTL_PB(Integer integer) {
		throw new UnsupportedOperationException("TODO: auto-generated method stub")
	}
	
	def getShortName(Integer integer) {
		throw new UnsupportedOperationException("TODO: auto-generated method stub")
	}
  

   /*
   *
   * @param None
   * @return None
   */
  def Sd_GaaInstanceStatic() {
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_InstanceStaticType Sd_GaaInstanceStatic[«Sd_Cfg_H.Sd_GInstances_arr.size»] =
  {'''
       val stp =
    '''};
    
   #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #include "Sd_MemMap.h" ''' 
   
 instancestatic()
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
 }      
 
  def instancestatic()
  {
     for (sd_inst : sdInstances)
     {
     	cstruct += new CStruct()=>
     	[
     	  comment = '''Sd_GaaInstanceStatic : «Sd_Ginst_cnt++» - «sd_inst?.shortName»'''
     	  members += new Member ()=>
     	  [
     	  	 comment = '''pConfigOption'''
     	  	 if (config_opt_inst_hstnm_hash.size > 0 &&
             config_opt_inst_hstnm_hash.containsKey(sd_inst?.shortNamePath?.toString))
             {
    	        value = '''&Sd_GSaaConfigurationOption[«config_opt_inst_hstnm_hash.get(sd_inst?.shortNamePath?.
    	        	toString
    	        )»]'''
             }
             else
             {
               value = "NULL_PTR"
             }
     	  ]
     	    
     	    members += new Member ()=>
     	    [
     	       comment = '''usBaseServerServiceIndex'''
     	       if (server_service_cnt.size > 0 && sd_inst?.sdServerServices.size > 0 &&
                server_service_cnt.contains(sd_inst?.sdServerServices?.get(0)?.shortNamePath?.toString))
               {
                value = '''«(server_service_cnt.indexOf(sd_inst?.sdServerServices?.get(0)?.shortNamePath?.toString))
                .toHex»'''
               }             
               else
               {
               	  value = '''«0.toHex»'''
               }
     	    ] 
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usNoOfServerServices'''
     	    	if (sd_inst?.sdServerServices.size > 0)
     	    	{
     	    		value = '''«sd_inst?.sdServerServices.size.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		value = '''«0.toHex»'''
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usBaseClientServiceIndex '''
     	    	if (client_service_cnt.size > 0 && sd_inst?.sdClientServices.size > 0 &&
                 client_service_cnt.contains(sd_inst?.sdClientServices?.get(0)?.shortNamePath?.toString))
                 {
                 	value = '''«(client_service_cnt.indexOf(sd_inst?.sdClientServices?.get(0)?.shortNamePath?.toString))
                 	.toHex»'''
                 }
                else
                {
                	value = '''«0.toHex»'''
                }
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usNoOfClientServices'''
     	    	if (sd_inst?.sdClientServices.size > 0)
     	    	{
     	    		value = '''«sd_inst?.sdClientServices.size.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		value = '''«0.toHex» '''
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddTxPduId'''
     	    	if (soad_tx_pduref_hash.size > 0 && sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB.size > 0)
     	    	{
     	    	   for(txpdu: sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB)
     	    	   {
     	    	   	  value = '''«soad_tx_pduref_hash?.get(txpdu?.reference?.shortNamePath?.toString).toHex»'''
     	    	   }
     	    	}
     	    	else
     	    	{
     	    		value = "SD_WRONG_CONFIG"
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddUnicastRxPduId'''
     	    	if (!(sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB.nullOrEmpty))
     	    	{
     	    		for (l1 : sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB)
     	    		{
     	    			value = '''«l1?.integerValue.toHex»'''
     	    		}
     	    	} 	
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddMulticastRxPduId'''
     	    	if (!(sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB.nullOrEmpty))
     	    	{
     	    		for(l1 : sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB)
     	    		{
     	    			value = '''«l1?.integerValue.toHex»'''
     	    		}
     	    	} 	
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddIpAddrSoConId'''
     	    	value = '''«get_IpAddrSoConId(sd_inst)»'''
     	    	if (IpAddrSoConId !== null)
     	    	{
     	    		value = '''«IpAddrSoConId.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		value = "NULL_PTR"
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddRxUnicastSoConId'''
     	    	if (sd_inst?.sdInstanceUnicastRxPdu !== null)
     	    	{
     	    		value = '''«get_uni_cast_socid(sd_inst?.sdInstanceUnicastRxPdu)»'''
     	    		value = '''«ddRxUnicastSoConId.toHex»'''
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddRxMulticastSoConId'''
     	    	if (sd_inst?.sdInstanceMulticastRxPdu !== null)
     	    	{
     	    		value = '''«get_multi_cast_socid(sd_inst?.sdInstanceMulticastRxPdu)»'''
     	    		value = '''«ddRxMulticastSoConId.toHex»'''
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usDemErrorMalformedId'''
     	    	if (_dem?.demConfigSet?.demEventParameters !== null)
     	    	{
     	    		value = '''«get_sd_dem(sd_inst)»'''
     	    	}
     	    	
     	    	if ((DemErrorMalformedId !== null) &&(DemErrorMalformedId != 0XFFFF))
     	    	{
     	    		value = '''«DemErrorMalformedId.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		value = "SD_DEM_INVALID"
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usDemErrorOutOfResId'''
     	    	if ((DemErrorOutOfResId !== null) &&(DemErrorOutOfResId != 0XFFFF))
     	    	{
     	    		value = '''«DemErrorOutOfResId.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		value = "SD_DEM_INVALID"
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usDemErrorSubEventgroupNacId'''
     	    	if ((DemErrorSubEventgroupNacId !== null) &&(DemErrorSubEventgroupNacId != 0XFFFF))
     	    	{
     	    		value = '''«DemErrorSubEventgroupNacId.toHex»'''
     	    	}
     	    	
     	    	else
     	    	{
     	    		value = "SD_DEM_INVALID"
     	    	}    	    	
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ucInstanceSelfIndex'''
     	    	value = '''«sdInstances.indexOf(sd_inst).toHex»'''
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''blDomainIpv4'''
     	    	var domain_type_hash = domain_type_ipv4()
     	    	if (domain_type_hash.get(sd_inst.shortNamePath.toString) == "TCPIP_AF_INET")
     	    	{
     	    		value = "(boolean)SD_TRUE"
     	    	}
     	    	
     	    	else
     	    	{
     	    		value = "(boolean)SD_FALSE"
     	    	}	    	
     	    ]
     	    
     	   members += new Member =>
     	    [
     	    	comment = '''usSdInstanceLocalAdressCheckLength'''
     	    	if(!sd_inst?.sdInstanceLocalAdressCheckLength_PB?.map[it.integerValue].filterNull.empty)
     	    	{
     	    		
     	    		value = '''«sd_inst?.sdInstanceLocalAdressCheckLength_PB?.head?.integerValue?.toHex»'''   
     	    		
     	    		 	
     	       }
     	       else
     	       {
     	       	value = '''SD_INVALID'''   
     	       	
     	       }
     	    	
     	    ]   
     	    
     	]
     }
     return cstruct
   }


   /*
   *
   * @param sd_inst SdInstance type
   * @return None
   */
  def get_sd_dem(SdInstance sd_inst)
  {
    DemErrorMalformedId = 0XFFFF
    DemErrorOutOfResId = 0XFFFF
    DemErrorSubEventgroupNacId = 0XFFFF
    for(dem_eve_prm : _dem?.demConfigSet?.demEventParameters)
    {
      dem_eve_parm_hash.put(dem_eve_prm?.shortNamePath?.toString, dem_eve_prm?.demEventId)
    }

    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_MALFORMED_MSG_PB.nullOrEmpty))
    {
      for(malform_msg : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_MALFORMED_MSG_PB)
      {
        if(dem_eve_parm_hash.containsKey(malform_msg?.reference?.shortNamePath?.toString))
        {
          DemErrorMalformedId = dem_eve_parm_hash?.get(malform_msg?.reference?.shortNamePath?.toString)
        }
      }
    }
    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_OUT_OF_RES_PB.nullOrEmpty))
    {
      for(out_of_res : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_OUT_OF_RES_PB)
      {
        if(dem_eve_parm_hash.containsKey(out_of_res?.reference?.shortNamePath?.toString))
        {
          DemErrorOutOfResId = dem_eve_parm_hash?.get(out_of_res?.reference?.shortNamePath?.toString)
        }
      }
    }

    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_SUBSCR_NACK_RECV_PB.nullOrEmpty))
    {
      for(out_of_res : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_SUBSCR_NACK_RECV_PB)
      {
        if(dem_eve_parm_hash.containsKey(out_of_res?.reference?.shortNamePath?.toString))
        {
          DemErrorSubEventgroupNacId = dem_eve_parm_hash?.get(out_of_res?.reference?.shortNamePath?.toString)
        }
      }
    }
  }

   /*
   *
   * @param sd_inst SdInstance type
   * @return None
   */
  def get_IpAddrSoConId(SdInstance sd_inst)
    {
      for(sdTxPduRef : sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB)
      {

        for(pduroutes : _soad?.soAdConfig?.soAdPduRoutes)
        {
          if(pduroutes !== null)
          {
          for(soAdTxPduRef : pduroutes?.soAdTxPduRef_PB)
            {
              if(sdTxPduRef?.reference?.shortNamePath?.toString == soAdTxPduRef?.reference?.shortNamePath?.toString)
              {
                for(pduroutes_dest : pduroutes?.soAdPduRouteDests)
                {
                  for(bundleref : pduroutes_dest?.soAdTxSocketConnOrSocketConnBundleRef_PB)
                  {
                    if(soad_connections.containsKey(bundleref?.reference?.shortNamePath?.toString))
                    {
                      IpAddrSoConId = soad_connections?.get(bundleref?.reference?.shortNamePath?.toString)
                    }
                    else
                    {
                      if(soad_connectionGroups.containsKey(bundleref?.reference?.shortNamePath?.toString))
                      {
                        IpAddrSoConId = soad_connectionGroups?.get(bundleref?.reference?.shortNamePath?.toString)
                      }
                    }
                  }
                }
             }
           }
         }
       }
      }
    }


   /*
   *
   * @param sdInstanceUnicastRxPdu
   * @return None
   */
  def get_uni_cast_socid(Sd.SdConfig.SdInstance.SdInstanceUnicastRxPdu sdInstanceUnicastRxPdu)
  {
    for(sd_rxpdu : sdInstanceUnicastRxPdu?.sdRxPduRef_PB)
    {
      for(SoAdSocketRoute : _soad?.soAdConfig?.soAdSocketRoutes)
      {
        for(soc_dest : SoAdSocketRoute?.soAdSocketRouteDests?.head.soAdRxPduRef_PB)
        {
          if(sd_rxpdu?.reference?.shortNamePath?.toString == soc_dest?.reference?.shortNamePath?.toString)
          {
            var bundleref = SoAdSocketRoute?.soAdRxSocketConnOrSocketConnBundleRef_PB.map[reference].head
            if(bundleref instanceof SoAdSocketConnectionGroup)
            {
              var ref = SoAdSocketRoute?.soAdRxSocketConnOrSocketConnBundleRef_PB.head.reference as 
                SoAdSocketConnectionGroup
              ddRxUnicastSoConId = soad_connections.get(ref.soAdSocketConnections.head.shortNamePath?.toString)
            }
            else
            {
              ddRxUnicastSoConId = soad_connections.get(bundleref.shortNamePath?.toString)
            }
          }
        }
      }
    }
  }

   /*
   *
   * @param sdInstanceMulticastRxPdu
   * @return None
   */
  def get_multi_cast_socid(Sd.SdConfig.SdInstance.SdInstanceMulticastRxPdu sdInstanceMulticastRxPdu)
  {
    for(sd_rxpdu : sdInstanceMulticastRxPdu?.sdRxPduRef_PB)
    {
      for(SoAdSocketRoute : _soad.soAdConfig?.soAdSocketRoutes)
      {
        for(soc_dest : SoAdSocketRoute?.soAdSocketRouteDests?.head.soAdRxPduRef_PB)
        {
          if(sd_rxpdu?.reference?.shortNamePath?.toString == soc_dest?.reference?.shortNamePath?.toString)
          {
            var bundleref = SoAdSocketRoute?.soAdRxSocketConnOrSocketConnBundleRef_PB.map[reference].head
            if(bundleref instanceof SoAdSocketConnectionGroup)
            {
              var ref = SoAdSocketRoute?.soAdRxSocketConnOrSocketConnBundleRef_PB.head.reference as 
                          SoAdSocketConnectionGroup
              ddRxMulticastSoConId = soad_connections.get(ref.soAdSocketConnections.head.shortNamePath?.toString)
            }
            else
            {
              ddRxMulticastSoConId = soad_connections.get(bundleref.shortNamePath?.toString)
            }

          }
        }
      }
    }
  }

   /*
   *
   * @param None
   * @return None
   */
   
  
  def Sd_GaaServerServiceStatic() {
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ServerServiceStaticType Sd_GaaServerServiceStatic[«Sd_Cfg_H.server_services_cnt.size»] =
  {'''
       val stp =
    '''};
    
   #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #include "Sd_MemMap.h" ''' 
   
 serverServiceStatic()
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
 }   
     
  def serverServiceStatic()
  {
    for (sd_inst : sdInstances){
    
    
    for (server_service : sd_inst?.sdServerServices ) {
      cstruct += new CStruct()=>
      [
      	comment = '''Sd_GaaServerServiceStatic : «Sd_Gserverstructinst++» - «sd_inst?.shortName+'_'+server_service?.
      	shortName»'''
        members += new Member =>
        [
        	comment = '''ulMinorVersion'''
        	for(ser_service : server_service?.sdServerServiceMinorVersion_PB)
        	{
        		value = '''«ser_service?.integerValue.toHex+'U'»'''
        	}     	
         ]
      
         
 
        members += new Member =>
        [
         	comment = '''pTcpSoConGrp'''
         	if(server_service?.sdServerServiceTcpRef_PB?.size > 0)
         	{
         	   for (tcp : server_service?.sdServerServiceTcpRef_PB?.toList)
         	   {
         	   	  if (sort_used_soc_con_grp_arr.contains(tcp?.reference?.shortNamePath?.toString))
         	   	  {
         	   	  	 value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.indexOf(tcp?.
         	   	  	 	reference?.shortNamePath?.toString
         	   	  	 )+']'»'''
         	   	  }
         	   	  else
         	   	  {
         	   	  	 value = "NULL_PTR" 
         	   	  }
         	   }        	   
         	}
         	else
         	{
         		value = "NULL_PTR"
         	}
        ]
 
        members += new Member =>
        [
        	comment = '''pUdpSoConGrp'''
        	if (server_service?.sdServerServiceUdpRef_PB?.size > 0)
            {
        		for (udp : server_service?.sdServerServiceUdpRef_PB?.toList)
        		{
        		   if(sort_used_soc_con_grp_arr.contains(udp?.reference?.shortNamePath?.toString))
        		   {
        		   	  value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
                      indexOf(udp?.reference?.shortNamePath?.toString)+']'»'''
        		   }
        		   else
        		   {
        		   	  value = "NULL_PTR"
        		   }
        		}
            }
            else
            {
            	value = "NULL_PTR"
            }       	
        ]
        
        
        members += new Member =>
        [
        	comment = '''pServerTimer'''
        	for (timer : server_service?.sdServerServiceTimerRef_PB)
        	{
        		value = '''&Sd_GSaaServerTimerStatic[«server_timer_arr.indexOf(timer?.reference?.
        			shortNamePath?.toString
        		)»]'''
        	}
        ]
        
       
        members += new Member =>
        [
            comment = '''pConfigOption'''	
            var config_opt_serv_cap_rec_index = get_config_opt_serv_cap_rec_index()
            if (config_opt_serv_cap_rec_index.size > 0 &&
               config_opt_serv_cap_rec_index.containsKey(server_service?.shortNamePath?.toString))
            {
      	        value = '''«'&Sd_GSaaConfigurationOption['+config_opt_serv_cap_rec_index.get(server_service?.
      	        	shortNamePath?.toString
      	        )+']'»'''
            }
            else
            {
            	value = "NULL_PTR"
            }         
        ]
        
        members += new Member =>
        [
        	comment = ''' usHandleId'''
        	value = '''«server_service?.sdServerServiceHandleId?.toHex»'''
        ]
        
       members += new Member =>
       [
       	   comment = '''usServiceId'''
       	   for (service_id : server_service?.sdServerServiceId_PB)
       	   {
       	       value = '''«service_id?.integerValue?.toHex+'U'»'''      	   
       	   }
       ]
       
       members += new Member =>
       [
       	    comment = '''usInstanceId'''
       	    for (service_inst_id : server_service?.sdServerServiceInstanceId_PB)
       	    {
       	    	value = '''«service_inst_id?.integerValue?.toHex»'''
       	    }      	    
       ]
       
       members += new Member =>
       [
       	   comment = '''usOtherservKeyIndex'''
       	   var otherservKeyIndex = get_otherservKeyIndex()
           if(otherservKeyIndex.containsKey(server_service?.shortNamePath?.toString))
           {
           	   value = '''«otherservKeyIndex?.get(server_service?.shortNamePath?.toString)?.get("OtherservKeyIndex").
           	   toHex»'''
           }
           else
           {
           	    value = '''«0.toHex»'''
           }
       ]
       
       members += new Member =>
       [
       	    comment = '''usOtherservKeyLength'''
       	    var otherservKeyIndex = get_otherservKeyIndex()
       	    if (otherservKeyIndex.containsKey(server_service?.shortNamePath?.toString))
       	    {
       	    	value = '''«otherservKeyIndex?.get(server_service?.shortNamePath?.toString)?.get("OtherservKeyLength").
       	    	toHex»'''
       	    }
       	    else
       	    {
       	    	value = '''«0.toHex»'''
       	    }
       ]
       
       members += new Member =>
       [
       	    comment = '''ddActivationRoGrpId'''
       	    val act_server_grp_id = get_act_server_grp_id(server_service?.shortNamePath?.toString)
       	    if (!(act_server_grp_id.nullOrEmpty))
       	    {
       	    	value = '''«act_server_grp_id»'''
       	    }   	    
       	    else
       	    {
       	    	value = '''«0.toHex»'''
       	    }
       ]
       
       members += new Member =>
       [
       	    comment = '''usBaseEvHandlerIndex'''
       	    if(eve_hand_cnt.size > 0 && server_service?.sdEventHandlers.size > 0 &&
               eve_hand_cnt.contains(server_service?.sdEventHandlers?.get(0)?.shortNamePath?.toString))
            {
               	value = '''«(eve_hand_cnt.indexOf(server_service?.sdEventHandlers?.get(0)?.shortNamePath?.toString)).
               	toHex»'''
            }
            else
            {
            	value = '''«0.toHex»'''
            }
       ]
       
       members += new Member =>
       [
       	   comment = '''usNoOfEvHandlers'''
       	   if(server_service?.sdEventHandlers.size > 0)
       	   {
       	   	   value = '''«server_service?.sdEventHandlers.size.toHex»'''
       	   }
       	   else
       	   {
       	   	    value = '''«0.toHex»'''
       	   }     	   
       ]
       
       members += new Member =>
       [
       	   comment = '''usServerSelfIndex'''
       	   if(server_service_cnt.size > 0)
       	   {
       	   	   value = '''«(server_service_cnt.indexOf(server_service?.shortNamePath?.toString)).toHex»'''
       	   }
       	   else
       	   {
       	   	    value = '''«0.toHex»'''
       	   }    	   
       ]
       
       members += new Member =>
       [
       	   comment = '''ucSdInstanceIndex'''
       	   if(no_of_Instances.size > 0)
       	   {
       	   	   value = '''«no_of_Instances.indexOf(sd_inst?.shortNamePath?.toString).toHex»'''
       	   }   	   
       	   else
       	   {
       	   	   value = '''«0.toHex»'''
       	   }     	   
        ]
        
        members += new Member =>
        [
        	comment = ''' ucMajorVersion'''
        	for (maj_ver : server_service?.sdServerServiceMajorVersion_PB)
        	{
        		value = '''«maj_ver?.integerValue.toHex»'''
        	}
        ]
       
         members += new Member =>
    	 [
    	    comment = '''stServerStaticFlag'''
    	    value = '''«stServerStaticFlag(server_service).head»'''
    	 ] 
    	 
    	   members += new Member =>
    	 [
    	    comment = '''usMaxNumOfIpAddressesInAcl'''
    	  if((server_service ).sdMaxNumOfIpAddressesInAcl != null )
    	    {
    	    value = '''«(server_service).sdMaxNumOfIpAddressesInAcl »'''
    	    
    	    }
    	    else
    	    {
    	    	value = '''0'''
    	    }
    	
    
    	 ] 
    	  members += new Member =>
    	  [
    	    comment = '''blAclEnable_Disable_Check'''
    	     if((server_service ).sdServerServiceAllowedConsumerss_PB?.head !== null )
    	    {
    	    value = '''SD_TRUE'''
    	    
    	    }
    	    else
    	    {
    	    	value = '''SD_FALSE'''
    	    }
    	  
    	  
    	 ]
    	 
    	 members += new Member =>
        [
        	comment = '''pServiceGroupRef'''
        	  
        	 if(server_service?.sdServiceGroupRefs_PB?.size>0){
        	for (Sd_Ser_grp_Ref : server_service?.sdServiceGroupRefs_PB?.toList)
        	{   
         if(sort_used_ser_grp_arr.contains(Sd_Ser_grp_Ref?.reference?.shortNamePath?.toString))
        	 {
        		    value = '''&Sd_GaaServicegroupStatic[«sort_used_ser_grp_arr.indexOf(Sd_Ser_grp_Ref?.reference?.shortNamePath?.toString)»]'''
        		
        		}
             else
        		{
        			value = "NULL_PTR"
        			
        		}
        		
        		
        		
        		
        	}
        	}
        	else
        	{
        		value = "NULL_PTR"
        	}
        	
        ]
        
    	   
       ]
      }    
     }
     return cstruct
   }
	


    def stServerStaticFlag(SdServerService service) {
    var cstruct = new ArrayList<CStruct>	
    cstruct += new CStruct()=>
    [
    	members += new Member =>
      [
        comment = '''blAutoAvaliable'''
        for (auto_available_flg : service?.sdServerServiceAutoAvailable_PB)
        {
          if (auto_available_flg?.booleanValue == true)
          {
            value = "1"
          }
          else
          {
            value = "0"
          }
        }
    	] 
    	
    	members += new Member =>
    	[
    	 	comment = '''blActivationRoGrpIdPresent'''  	 
    	 	val act_server_grp_id = get_act_server_grp_id(service?.shortNamePath?.toString)	
    	 	if (!(act_server_grp_id.nullOrEmpty))
    	 	{
    	 		value = "1"
    	 	}
    	 	else
    	 	{
    	 		value = "0"
    	 	}	
    	]
    		 
        members += new Member =>
        [
    	    comment = '''ucReserved '''
    	 	value = "0"
    	] 
    ]
 return cstruct
}
      

   /*
   *
   * @param clientservice String type
   * @return String
   */
  def get_act_client_grp_id(String clientservice)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_client_routing_grp.get(clientservice) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param con_eve_path String type
   * @return String
   */
  def get_act_consumed_eve_grp_id(String con_eve_path)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_consumed_eve_routing_grp?.get(con_eve_path) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param serverservice String type
   * @return String
   */
  def get_act_server_grp_id(String serverservice)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_server_routing_grp?.get(serverservice) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param eve_handler String type
   * @return String
   */
  def get_act_eve_handler_grp_id(String eve_handler)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_eve_hand_routing_grp?.get(eve_handler) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param eve_handler String type
   * @return String
   */
  def get_act_eve_handler_udp_grp_id(String udp_ref)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_eve_hand_udp_routing_grp?.get(udp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param tcp_ref String type
   * @return String
   */
  def get_act_eve_handler_tcp_grp_id(String tcp_ref)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(act_eve_hand_tcp_routing_grp?.get(tcp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param tcp_ref String type
   * @return String
   */
  def get_con_eve_tcp_act_id(String con_eve_ref)
  {
      for(soad_rout_grps : _soad?.soAdConfig?.soAdRoutingGroups)
      {
        if(sd_con_eve_tcp_ref_arr?.get(con_eve_ref) == soad_rout_grps?.shortNamePath?.toString)
        {
          return (soad_rout_grps?.soAdRoutingGroupId_Desc?.integerValue?.toHex)?.toString
        }
      }
  }

   /*
   *
   * @param con_eve_ref String type
   * @return String
   */
  def get_con_eve_udp_act_id(String con_eve_ref)
  {
      for(soad_rout_grps : _soad?.soAdConfig?.soAdRoutingGroups)
      {
        if(sd_con_eve_udp_ref_arr?.get(con_eve_ref) == soad_rout_grps?.shortNamePath?.toString)
        {
          return (soad_rout_grps?.soAdRoutingGroupId_Desc?.integerValue?.toHex)?.toString
        }
      }
  }

   /*
   *
   * @param udp_ref String type
   * @return String
   */
  def get_eve_hand_udp_act_id(String udp_ref)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(sd_eve_handler_udp_ref_arr?.get(udp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param tcp_ref String type
   * @return String
   */
  def get_eve_hand_tcp_act_id(String tcp_ref)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      if(sd_eve_handler_tcp_ref_arr?.get(tcp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.soAdRoutingGroupId?.toHex)?.toString
      }
    }
  }

   /*
   *
   * @param eve_handler String type
   * @return None
   */
  def get_multi_eve_soc_con_id(String eve_handler)
  {
    return ((soad_connections?.get(sd_eve_hand_multi_soc_con?.get(eve_handler)))?.toHex)?.toString
  }
  
  def Sd_GaaClientServiceStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ClientServiceStaticType Sd_GaaClientServiceStatic[«Sd_Cfg_H.client_services_cnt.size»] =
  {'''
       val stp =
   '''};
    
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" ''' 
   
 clientServiceStatic()
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
 } 
  
  def clientServiceStatic()
  {
     for(sd_inst : sdInstances){
     
     
     for (client_service : sd_inst?.sdClientServices){
     cstruct += new CStruct()=>
     [
     	comment = '''Sd_GaaClientServiceStatic : «Sd_Gclientstructinst++» - «sd_inst?.shortName+'_'+client_service?.
     	shortName»'''
     	members += new Member()=>
     	[
     		comment = '''usHandleId '''
     		value = '''«client_service?.sdClientServiceHandleId?.toHex»'''
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usServiceId'''
     		for (client_id : client_service?.sdClientServiceId_PB)
     		{
     			value = '''«client_id?.integerValue?.toHex+'U'»'''
     		} 		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usInstanceId'''
     		for (service_inst_id : client_service?.sdClientServiceInstanceId_PB)
     		{
     			value = '''«service_inst_id?.integerValue?.toHex+'U'»'''
     		}
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ucMajorVersion'''
     		for (maj_ver : client_service?.sdClientServiceMajorVersion_PB)
     		{
     			value = '''«maj_ver?.integerValue.toHex»'''
     		}
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ulMinorVersion'''
     		for (cli_service : client_service?.sdClientServiceMinorVersion_PB)
     		{
     			value = '''«cli_service?.integerValue.toHex+'U'»'''
     		}
     	]
     
     	members += new Member()=>
     	[
     		comment = '''pTcpSoConGrp'''
     		if(client_service?.sdClientServiceTcpRef_PB?.size>0)
     		{
     			for(tcp : client_service?.sdClientServiceTcpRef_PB?.toList)
     			{
     				if(soad_soc_con_grps.contains(tcp?.reference?.shortNamePath?.toString))
     				{
     					value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
                            indexOf(tcp?.reference?.shortNamePath?.toString)+']'»'''
     				}
     				else
     				{
     					value = "NULL_PTR"
     				}
     			}
     		 }
     		 else
     		 {
     		 	value = "NULL_PTR"
     		 }
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''pUdpSoConGrp'''
     		if(client_service?.sdClientServiceUdpRef_PB?.size > 0)
     		{
     			for (udp : client_service?.sdClientServiceUdpRef_PB?.toList)
     			{
     				if(soad_soc_con_grps.contains(udp?.reference?.shortNamePath?.toString))
     				{
     					value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
      indexOf(udp?.reference?.shortNamePath?.toString)+']'»'''
     				}
     				else
     				{
     					value = "NULL_PTR "
     				}
     			}
     		} 		
     		else
     		{
     			value = "NULL_PTR"
     		} 		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''pClientTimer'''
     		for (timer : client_service?.sdClientServiceTimerRef_PB)
     		{
     			var client_timer_arr = get_client_timer_arr()
     			value = '''&Sd_GSaaClientTimerStatic[«client_timer_arr.indexOf(timer?.reference?.shortNamePath?.
     				toString
     			)»]'''
     		}
     	]
     	
     	members += new Member ()=>
     	[
     		comment = '''pConfigOption'''
     		var conf_opt_client_rec_index = get_config_opt_client_cap_rec_index()
     		if (conf_opt_client_rec_index.size > 0 &&
      conf_opt_client_rec_index.containsKey(client_service?.shortNamePath?.toString))
            {
      	        value = '''«'&Sd_GSaaConfigurationOption['+conf_opt_client_rec_index.get(client_service?.shortNamePath?.
      	        	toString
      	        )+']'»'''
            }
            else
            {
            	value = "NULL_PTR"
            }
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usOtherservKeyIndex'''
     		var otherservKeyIndex = get_otherservKeyIndex()
     		if (otherservKeyIndex.containsKey(client_service?.shortNamePath?.toString))
     		{
     			value = '''«otherservKeyIndex?.get(client_service?.shortNamePath?.toString)?.get("OtherservKeyIndex").
     			toHex»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usOtherservKeyLength'''
     		var otherservKeyIndex = get_otherservKeyIndex()
     		if(otherservKeyIndex.containsKey(client_service?.shortNamePath?.toString))
     		{
     			value = '''«otherservKeyIndex?.get(client_service?.shortNamePath?.toString)?.get("OtherservKeyLength").
     			toHex»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usBaseConEventGrp'''
     		if(consumed_eve_grp_cnt.size > 0 && client_service?.sdConsumedEventGroups.size > 0)
     		{
     			value = '''«(consumed_eve_grp_cnt.indexOf(client_service?.sdConsumedEventGroups?.get(0)?.shortNamePath?.
     				toString
     			)).toHex»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member =>
     	[
     		comment = '''usNoOfConEventGrp'''
     	    if(client_service?.sdConsumedEventGroups.size > 0)
     	    {
     	    	value = '''«client_service?.sdConsumedEventGroups.size.toHex»'''
     	    }
     	    else
     	    {
     	    	value = '''«0.toHex»'''
     	    }
     	]
     	
     	members += new Member =>
     	[
     		comment = '''usClientSelfIndex'''
     		if(client_service_cnt.size > 0)
     		{
     			value = '''«client_service_cnt.indexOf(client_service?.shortNamePath?.toString).toHex»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member =>
     	[
     		comment = '''ddActivationRoGrpId'''
     		val act_client_grp_id = get_act_client_grp_id(client_service?.shortNamePath?.toString)
     		if (!(act_client_grp_id.nullOrEmpty))
     		{
     			value = '''«act_client_grp_id»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member =>
     	[
     		comment = '''ucSdInstanceIndex'''
     		if(no_of_Instances.size > 0)
     		{
     			value = '''«no_of_Instances.indexOf(sd_inst?.shortNamePath?.toString).toHex»'''
     		}
     		else
     		{
     			value = '''«0.toHex»'''
     		}
     	]
     	
     	members += new Member =>
     	[
     		comment = '''stClientStaticFlag'''
     		value = '''«stClientStaticFlag(client_service).head»'''
     	]
    
    members += new Member()=>
[
comment = "EndrivenBehaviour"
if(client_service.sdVersionDrivenFindBehavior_PB.map[it.enumValue].filterNull.empty)
{
value = '''SD_EXACT_OR_ANY_MINOR_VERSION'''
}
else
{
value = '''SD_«client_service.sdVersionDrivenFindBehavior_PB.head.enumValue»'''
}

]

  members += new Member =>
    	 [
    	    comment = '''usMaxNumOfIpAddressesInAcl'''
    	  if ((client_service )?.sdMaxNumOfIpAddressesInAcl != null )
    	    {
    	    value = '''«(client_service ).sdMaxNumOfIpAddressesInAcl »'''
    	    
    	    }
    	    else
    	    {
    	    	value =     ''' 0'''
    	    	
    	    }
    	 
    	 ] 
    	 

  members += new Member =>
    	 [
    	    comment = '''blAclEnable_Disable_Check'''
    	    if ((client_service )?.sdClientServiceAllowedProviders_PB.head !== null )
    	    {
    	    value = '''SD_TRUE'''
    	    
    	    }
    	    else
    	    {
    	    	value =     ''' SD_FALSE'''
    	    	
    	    }
    	    
    	   
    	    	
    	 ] 

 members += new Member =>
        [
        	comment = '''pServiceGroupRef'''
        	var service_grp_arr = get_service_grp_arr()
        	if(client_service?.sdServiceGroupRefs_PB?.size>0){
        	for (Sd_grp_Ref: client_service?.sdServiceGroupRefs_PB?.filterNull?.toList)
        	{
        		if(service_grp_arr.contains(Sd_grp_Ref?.reference?.shortNamePath?.toString))
        		{
        		value = '''&Sd_GaaServicegroupStatic[«service_grp_arr.indexOf(Sd_grp_Ref?.reference?.shortNamePath?.toString)»]'''
        		
        		}
        		else
        		{
        			value = "NULL_PTR"
        		}
        	}
        	
        	}
        	else
        	{
        		value = "NULL_PTR"
        	}
        ]

	members += new Member =>
	
        [  if(client_service.sdBlocklistedVersions_PB.size.intValue != 0 )
        	{
        	 for(ser:client_service.sdBlocklistedVersions_PB)
        	{
        	comment = '''sdBlocklistedMinorVersions'''
        	if(ser?.sdBlocklistedMinorVersionss_PB != null )
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        	value ='''«ser?.sdBlocklistedMinorVersionss_PB.map[integerValue].join(",")»'''
        	
        	}
        	else
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        		value = '''0'''
        	}
        	}
        	}
        	else
        	{
        	    comment = '''sdBlocklistedMinorVersions'''
        		value = '''0'''
        	}
        	
        	
        ]
     	
     ]
    }
    }
    return cstruct
 }

  def stClientStaticFlag(SdClientService service)
  {
       var cstruct = new ArrayList<CStruct>
       cstruct += new CStruct() =>
       [
       	   members += new Member()=>
       	   [
       	  	  comment = '''blAutoRequire'''
       	  	  for (value : service?.sdClientServiceAutoRequire_PB)
       	  	  {
       	  	  	  if (value?.booleanValue == true)
       	  	  	  {
       	  	  	  	  value = "1"
       	  	  	  }
       	  	  	  else
       	  	  	  {
       	  	  	  	  value = "0"
       	  	  	  }
       	  	  }      	  	  
       	    ]
       	    
       	    members += new Member()=>
       	    [
       	    	comment = '''blActivationRoGrpIdPresent'''
       	    	val act_client_grp_id = get_act_client_grp_id(service?.shortNamePath?.toString)
       	    	if (!(act_client_grp_id.nullOrEmpty))
       	    	{
       	    		value = "1"
       	    	}
       	    	else
       	    	{
       	    		value = "0"
       	    	}
       	    ]
       	    
       	    members += new Member ()=>
       	    [
       	    	comment = '''ucReserved'''
       	    	value = "0"
       	    ]
       ]
     return cstruct  
   }
   

    

   /*
   *
   * @param None
   * @return None
   */
   
   /**
    *
    * #section Sd_Cfg_C_REF_1
    * Violates MISRA 2012 Advisory Rule 1.1,
    * Number of Macro definitions exceed 1024.
    *
    **/
   
   /* Violates #ref Sd_Cfg_C_REF_1 Violates MISRA 2012 Required Rule 1.1 */
    /* PRQA S 0857 EOF */
def Sd_GSaaClientTimerStatic(){
cstruct.clear
if (client_timer_cnt > 0)
{
val str = '''
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
 const Sd_ClientTimerStaticType Sd_GSaaClientTimerStatic[«Sd_Cfg_H.client_timer_cnt»] =
{'''
      val stp =
'''};
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h" '''
     
    client_timer_static()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
      }
    }
    
    
  def client_timer_static()
  {   	 
  
    var client_timer_arr = get_client_timer_arr
  	for (itr : 0..< client_timer_arr.size){
  	for (sd_inst : sdInstances){
    for (client_timers : sd_inst?.sdClientTimers){

     if (client_timer_arr.get(itr).contains((client_timers.shortNamePath).toString)){
       cstruct += new CStruct()=>
       [
     		comment = '''Sd_GSaaClientTimerStatic : «Sd_Gclienttimer_cnt++» - «sd_inst?.shortName»_«client_timers?.
     		shortName»'''
            members += new Member()=>
            [
            	comment = '''ulClientTimerTtlsec'''
            	for (ttl : client_timers?.sdClientTimerTTL_PB)
            	{
            		value = '''«(ttl.integerValue.toHex)+'U'»'''
            	}
            ]
            
            members += new Member ()=>
            [
            	 comment = '''ulInitialFindDelayMax'''
            	 if (!(client_timers?.sdClientTimerInitialFindDelayMax_PB.nullOrEmpty))
            	 {
            		 for (init_delay_max : client_timers?.sdClientTimerInitialFindDelayMax_PB?.toList)
            		 {
            			 value = '''«((init_delay_max.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		 }           			
            	  }
            	  else
            	  {
            		   value = "SD_TIMER_UNUSED"
            	  }       		
             ]
               
               members += new Member ()=>
               [
               	   comment = '''ulInitialFindDelayMin'''
               	   if (!(client_timers?.sdClientTimerInitialFindDelayMin_PB.nullOrEmpty))
               	   {
               	   	   for (init_delay_min : client_timers?.sdClientTimerInitialFindDelayMin_PB?.toList)
               	   	   {
               	   	   	   value = '''«((init_delay_min.floatValue/Sd_main_func_period).intValue.toHex)»'''
               	   	   }
               	   }
               	   else
               	   {
               	   	   value = "SD_TIMER_UNUSED"
               	   }              	   	
                ]
                
                members += new Member ()=>
                [
                	comment = '''ulInitialFindRepetitionsBaseDelay'''
                	if (!(client_timers?.sdClientTimerInitialFindRepetitionsBaseDelay_PB.nullOrEmpty))
                	{
                		for(rep_base_delay : client_timers?.sdClientTimerInitialFindRepetitionsBaseDelay_PB?.toList)
                		{
                			value = '''«((rep_base_delay.floatValue/Sd_main_func_period).intValue.toHex)»'''
                		}
                	}
                	else
                	{
                		value = "SD_TIMER_UNUSED"
                	}
                ]
                
                members += new Member ()=>
                [
                	comment = '''ulRequestResponseMaxDelay'''
                	if(!(client_timers?.sdClientTimerRequestResponseMaxDelay_PB.nullOrEmpty))
                	{
                	   for (req_max_delay : client_timers?.sdClientTimerRequestResponseMaxDelay_PB?.toList)
                	   {
                	   	   value = '''«((req_max_delay.floatValue/Sd_main_func_period).intValue.toHex)»'''
                	   }
                	}
                	else
                	{
                	    value = "SD_TIMER_UNUSED"
                	}             	
                ]
                  
                 members += new Member() =>
                 [
                  	 comment = '''ulRequestResponseMinDelay'''
                  	 if (!(client_timers?.sdClientTimerRequestResponseMinDelay_PB.nullOrEmpty))
                  	 {
                  	 	 for(req_min_delay : client_timers?.sdClientTimerRequestResponseMinDelay_PB?.toList)
                  	 	 {
                  	 	 	value = '''«((req_min_delay.floatValue/Sd_main_func_period).intValue.toHex)»'''
                  	 	 } 	 
                  	 }
                  	 else
                  	 {
                  	  	 value = "SD_TIMER_UNUSED"
                  	 } 	
                 ]
                 
                 members += new Member()=>
                 [
                 	comment = '''ucInitialFindRepetitionsMax'''
                 	if(!client_timers?.sdClientTimerInitialFindRepetitionsMax_PB?.map[it.integerValue].filterNull.empty)
                 	
                 	{
                 	    for (rep_max : client_timers?.sdClientTimerInitialFindRepetitionsMax_PB?.toList)
                 	    {
                 	    	value = '''«((rep_max?.integerValue).toHex)»'''
                 	    }        	    
                 	}
                 	else
                 	{
                 		value = "SD_TIMER_UNUSED"
                 	}
                 ] 
                 
                   members += new Member ()=>
            [
            	 comment = '''ulSubscribeEventgroupRetryDelay'''
            	 if(!client_timers?.sdSubscribeEventgroupRetryDelay_PB?.map[it.floatValue].filterNull.empty)
            	 {
            		 for (init_delay_max : client_timers?.sdSubscribeEventgroupRetryDelay_PB?.toList)
            		 {
            			 value = '''«((init_delay_max.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		 }           			
            	  }
            	  else
            	  {
            		   value = "SD_TIMER_UNUSED"
            	  }       		
             ] 
             
                members += new Member()=>
                 [
                 	comment = '''ucSubscribeEventgroupRetryMax'''
					if(!client_timers?.sdSubscribeEventgroupRetryMax_PB?.map[it.integerValue].filterNull.empty)
                 	{
                 	    for (rep_max : client_timers?.sdSubscribeEventgroupRetryMax_PB?.toList)
                 	    {
                 	    	value = '''«((rep_max?.integerValue).toHex)»'''
                 	    }        	    
                 	}
                 	else
                 	{
                 		value = "SD_TIMER_UNUSED"
                 	}
                 ]               
               ]                           
              }
            }
          }
        }
     return cstruct
  }

   /*
   *
   * @param None
   * @return None
   */
  def get_used_soc_con_grp_arr()
  {
    for(sokcongrps : _soad?.soAdConfig?.soAdSocketConnectionGroups)
    {
      if(Soad_cnt_arr.contains(sokcongrps?.shortNamePath?.toString))
      {
        sort_used_soc_con_grp_arr.add(sokcongrps?.shortNamePath?.toString)
      }
    }
  }

   /*
   *
   * @param None
   * @return None
   */
   def Sd_GaaSoConGroupStatic() {
   cstruct.clear
   val str = '''
   #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h"
    const Sd_SoConGroupStaticType Sd_GaaSoConGroupStatic[«Sd_Cfg_H.Soad_cnt_arr.size»] =
    {'''
          val stp =
    '''};
    #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h" '''
   
    socongroupstatic()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
  def socongroupstatic()
  {
    for (sokcongrps : _soad?.soAdConfig?.soAdSocketConnectionGroups)
    {
      if (sort_used_soc_con_grp_arr.contains((sokcongrps?.shortNamePath)?.toString))
      {
      	cstruct += new CStruct() => [
      	comment = ''' Sd_GaaSoConGroupStatic : «Soad_Gcon_grps++» - «sokcongrps?.parent?.shortName+'_'+sokcongrps?.
      	shortName» '''
      	members += new Member() =>[
      		comment = '''usBaseSocketConIndex'''
      		value = '''«get_baseSocketConIndex(sokcongrps)»'''
      		value = '''«baseSocketConIndex»'''
      		]
      		
      		members += new Member ()=>
      		[
      			comment = '''usNoOfSockets'''
      			value = ''' «no_of_sockets.toHex» '''
      		]
      		]
      	}      	
      }
      return cstruct
    }
      
     

   /*
   *
   * @param server_service SdServerService type
   * @return Integer
   */
  def get_server_service_min_ver(SdServerService server_service)
  {
    for(ser_service : server_service?.sdServerServiceMinorVersion_PB)
    {
      return toHex(ser_service.integerValue)
    }
  }

   /*
   *
   * @param None
   * @return None
   */
  def multicast_soc_con_ind()
  {
   var str = ''
     sort_used_soc_con_grp_arr = new ArrayList<String>()
    for(sokcongrps : _soad?.soAdConfig?.soAdSocketConnectionGroups)
    {
      if(Soad_cnt_arr.contains(sokcongrps?.shortNamePath?.toString))
      {
        sort_used_soc_con_grp_arr.add(sokcongrps?.shortNamePath?.toString)
      }
    }
    for(soc_con_grps : Soad_client_con_ev_grp)
    {
      str += sort_used_soc_con_grp_arr.indexOf(soc_con_grps)+","

    }
  str = str.substring(0,str.length()-1)
  str = str.replace(",",",\n")

    return str
  }
  
 
   /*
   *
   * @param None
   * @return None
   */
   
  def Sd_GaaEvHandlerStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_EvHandlerStaticType Sd_GaaEvHandlerStatic[«Sd_Cfg_H.event_handle_ids.size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  event_handler_static()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   } 
   
  def event_handler_static()
  {    
    for (sd_inst : sdInstances){
    for (server_service : sd_inst?.sdServerServices){
    for (eve_handlers : server_service?.sdEventHandlers){
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaEvHandlerStatic : 
    	«Sd_GEveHandlerstructinst++» - «sd_inst?.shortName+'_'+server_service?.shortName+'_'+eve_handlers?.shortName»'''
    	members += new Member ()=>
    	[
    		comment = '''pServerTimer'''
    		for(timer : eve_handlers?.sdEventHandlerTimerRef_PB?.toList)
    		{
    			var server_timer_arr = get_server_timer_arr()
    			value = '''&Sd_GSaaServerTimerStatic[«server_timer_arr.indexOf(timer?.reference?.shortNamePath?.
    				toString
    			)»]'''
    			
    		}		
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''pConfigOption'''
    		var config_opt_event_handler_index = get_config_opt_event_handler_index()
    		if (config_opt_event_handler_index.size > 0 &&
            config_opt_event_handler_index.containsKey(eve_handlers?.shortNamePath?.toString))
            {
      	         value = '''«'&Sd_GSaaConfigurationOption['+config_opt_event_handler_index?.get(eve_handlers?.
      	         	shortNamePath?.toString
      	         )+']'»'''
      	         
      	         
            }
            else
            {
            	value = "NULL_PTR"
            }
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''usHandleId'''
    		value = '''«eve_handlers?.sdEventHandlerHandleId.toHex»'''		
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''usEventGroupId'''
    		value = '''«eve_handlers?.sdEventHandlerEventGroupId.toHex+'U'»'''
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''usMulticastThreshold'''
    	    for(multicast_thr : eve_handlers?.sdEventHandlerMulticastThreshold_PB)
    	    {
    		   value = '''«multicast_thr?.integerValue.toHex»'''
    		}
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''usOtherservKeyIndex'''
    		var otherservKeyIndex = get_otherservKeyIndex()
    	    if(otherservKeyIndex.containsKey(eve_handlers?.shortNamePath?.toString))
    	    {
    	    	value = '''«otherservKeyIndex?.get(eve_handlers?.shortNamePath?.toString)?.get("OtherservKeyIndex").
    	    	toHex»'''
    	    }
    	    else
    	    {
    	    	value = '''«0.toHex»'''
    	    }
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''usOtherservKeyLength'''
    		var otherservKeyIndex = get_otherservKeyIndex()
    		if(otherservKeyIndex.containsKey(eve_handlers?.shortNamePath?.toString))
    		{
    			value = '''«otherservKeyIndex?.get(eve_handlers?.shortNamePath?.toString)?.get("OtherservKeyLength").
    			toHex»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}  		
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddUdpTriggeringRoGrpId'''
    		val act_eve_handler_udp_grp_id = get_act_eve_handler_udp_grp_id(eve_handlers?.shortNamePath?.toString)
    		if(!(act_eve_handler_udp_grp_id.nullOrEmpty))
    		{
    			value = '''«act_eve_handler_udp_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}   		
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddUdpActivationRoGrpId'''
    		val UdpActivationRoGrpId = get_eve_hand_udp_act_id(eve_handlers?.shortNamePath?.toString)
    		if(!(UdpActivationRoGrpId.nullOrEmpty))
    		{
    			value = '''«UdpActivationRoGrpId»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''ddTcpTriggeringRoGrpId'''	
    		val act_eve_handler_tcp_grp_id = get_act_eve_handler_tcp_grp_id(eve_handlers?.shortNamePath?.toString)
    		if(!(act_eve_handler_tcp_grp_id.nullOrEmpty))
    		{
    			value = '''«act_eve_handler_tcp_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member() =>
    	[
    		comment = '''ddTcpActivationRoGrpId'''
    		val TcpActivationRoGrpId = get_eve_hand_tcp_act_id(eve_handlers?.shortNamePath?.toString)
    		if(!(TcpActivationRoGrpId.nullOrEmpty))
    		{
    			value = '''«TcpActivationRoGrpId»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddMulticastActivationRoGrpId'''
    		val act_eve_handler_grp_id = get_act_eve_handler_grp_id(eve_handlers?.shortNamePath?.toString)
    		if(!(act_eve_handler_grp_id.nullOrEmpty))
    		{
    			value = '''«act_eve_handler_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddMulticastEventSoConId'''
    		val sd_eve_hand_multi_soc_con_id = get_multi_eve_soc_con_id(eve_handlers?.shortNamePath?.toString)
    		if(!(sd_eve_hand_multi_soc_con_id.nullOrEmpty))
    		{
    			value = '''«sd_eve_hand_multi_soc_con_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member() =>
    	[
    		comment = '''usServerServiceIndex'''
    		if (server_service_cnt.size > 0)
    		{
    			value = '''«server_service_cnt.indexOf(server_service?.shortNamePath?.toString).toHex»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''usEvHandlerSelfIndex'''
    		if(eve_hand_cnt.size > 0)
    		{
    			value = '''«eve_hand_cnt.indexOf(eve_handlers?.shortNamePath?.toString).toHex»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}   		
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''stEvHandlerStaticFlag'''
    		value = '''«stEvHandlerStaticFlag(eve_handlers).head»'''
    	]
    ]
    }
   }
  }
  return cstruct 
}

def stEvHandlerStaticFlag(SdEventHandler handlers)
{
   var cstruct = new ArrayList<CStruct>
   cstruct += new CStruct()=> 
   [
   	  members += new Member()=>
   	  [
   	  	  comment = '''blUdpTriggeringRoGrpIdPresent'''
   	  	  val act_eve_handler_udp_grp_id = get_act_eve_handler_udp_grp_id(handlers?.shortNamePath?.toString)
   	  	  if(!(act_eve_handler_udp_grp_id.nullOrEmpty))
   	  	  {
   	  	  	  value = "1"
   	  	  }
   	  	  else
   	  	  {
   	  	  	   value = "0"
   	  	  }	  	  
   	  ]
   	  
   	  members += new Member() =>
   	  [
   	  	  comment = '''blUdpActivationRoGrpIdPresent'''
   	  	  val UdpActivationRoGrpId = get_eve_hand_udp_act_id(handlers?.shortNamePath?.toString)
   	  	  if(!(UdpActivationRoGrpId.nullOrEmpty))
   	  	  {
   	  	  	  value = "1"
   	  	  }
   	  	  else
   	  	  {
   	  	  	  value = "0"
   	  	  }
   	  ]
   	  
   	  members += new Member() =>
   	  [
   	  	  comment = '''blTcpTriggeringRoGrpIdPresent'''
   	  	  val act_eve_handler_tcp_grp_id = get_act_eve_handler_tcp_grp_id(handlers?.shortNamePath?.toString)
   	  	  if(!(act_eve_handler_tcp_grp_id.nullOrEmpty))
   	  	  {
   	  	  	  value = "1"
   	  	  }
   	  	  else
   	  	  {
   	  	  	  value = "0"
   	  	  }
   	  ]
   	  
   	  members += new Member() =>
   	  [
   	  	   comment = '''blTcpActivationRoGrpIdPresent'''
   	  	   val TcpActivationRoGrpId = get_eve_hand_tcp_act_id(handlers?.shortNamePath?.toString)
   	  	   if(!(TcpActivationRoGrpId.nullOrEmpty))
   	  	   {
   	  	   	   value = "1"
   	  	   }
   	  	   else
   	  	   {
   	  	   	   value = "0"
   	  	   }
   	  ]
   	  
   	   members += new Member() =>
   	   [
   	   	   comment = '''blMulticastActivationRoGrpIdPresent'''
   	   	   val act_eve_handler_grp_id = get_act_eve_handler_grp_id(handlers?.shortNamePath?.toString)
   	   	   if(!(act_eve_handler_grp_id.nullOrEmpty))
   	   	   {
   	   	   	   value = "1"
   	   	   }
   	   	   else
   	   	   {
   	   	   	   value = "0"
   	   	   }
   	   ]
   	   
   	   members += new Member() =>
   	   [
   	   	   comment = '''blMulticastEventSoConPresent'''
   	   	   val sd_eve_hand_multi_soc_con_id = get_multi_eve_soc_con_id(handlers?.shortNamePath?.toString)
   	   	   if (!(sd_eve_hand_multi_soc_con_id.nullOrEmpty))
   	   	   {
   	   	   	   value = "1"
   	   	   }
   	   	   else
   	   	   {
   	   	   	   value = "0"
   	   	   }  	
   	   ]
   	   
   	   members += new Member()=>
   	   [
   	   	   comment = '''ucReserved'''
   	   	   value = "0"
   	   ]
   ]
   return cstruct
 }   


   /*
   *
   * @param None
   * @return None
   */
  def Sd_GaaConsumedEvGrpStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ConsumedEvGrpStaticType Sd_GaaConsumedEvGrpStatic[«Sd_Cfg_H.consumed_eve_grp_cnt.size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  consumed_eve_grp_static()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   
 
     
  def consumed_eve_grp_static()
  {
    for (sd_inst : sdInstances) {
    for (client_service : sd_inst?.sdClientServices) {
    for (consumed_eve_grp : client_service?.sdConsumedEventGroups){
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaConsumedEvGrpStatic : 
    	«Sd_GConsumedEvstructinst++» - «sd_inst?.shortName+'_'+
    client_service?.shortName+'_'+consumed_eve_grp?.shortName»'''
        
        members += new Member ()=>
        [
        	comment = '''pConfigOption'''
        	var conf_opt_consumed_eve_index = get_config_opt_consumed_eve_index()
            if (conf_opt_consumed_eve_index.size > 0 &&
    conf_opt_consumed_eve_index.containsKey(consumed_eve_grp?.shortNamePath?.toString))
            {
            	value = '''&Sd_GSaaConfigurationOption[«conf_opt_consumed_eve_index.get(consumed_eve_grp?.
            		shortNamePath?.toString )»]'''
            }
            else
            {
            	value = "NULL_PTR"
             }
         ]
         
         members += new Member ()=>
         [
         	  comment = '''pClientTimer'''
         	  for (timer : consumed_eve_grp?.sdConsumedEventGroupTimerRef_PB)
         	  {
         	  	   var client_timer_arr = get_client_timer_arr()
         	  	   value = '''&Sd_GSaaClientTimerStatic[«client_timer_arr.indexOf(timer?.reference?.shortNamePath?.
         	  	   	toString
         	  	   )»]'''     	  	   
         	  }
         ]
         
         members += new Member ()=>
         [
         	  comment = '''usHandleId'''
         	  value = '''«consumed_eve_grp?.sdConsumedEventGroupHandleId.toHex»'''
         ]
         
         members += new Member ()=>
         [
         	comment = '''usEventGroupId'''
         	value = '''«consumed_eve_grp?.sdConsumedEventGroupId.toHex»'''
         ]
         
         members += new Member()=>
         [
         	 comment = '''usOtherservKeyIndex'''
         	 var otherservKeyIndex = get_otherservKeyIndex()
         	 if(otherservKeyIndex.containsKey(consumed_eve_grp?.shortNamePath?.toString))
         	 {
         	 	value = '''«otherservKeyIndex?.get(consumed_eve_grp?.shortNamePath?.toString)?.get("OtherservKeyIndex").
         	 	toHex»'''
         	 }
         	 else
         	 {
         	 	value = '''«0.toHex»'''
         	 }        	 
         ]
         
         members += new Member() =>
         [
         	  comment = '''usOtherservKeyLength'''
         	  var otherservKeyIndex = get_otherservKeyIndex()
         	  if(otherservKeyIndex.containsKey(consumed_eve_grp?.shortNamePath?.toString))
         	  {
         	  	  value = '''«otherservKeyIndex?.get(consumed_eve_grp?.shortNamePath?.toString)?.
         	  	  get("OtherservKeyLength").toHex»'''
         	  }
         	  else
         	  {
         	  	 value = '''«0.toHex»'''
         	  }
          ]
          
          members += new Member()=>
          [
          	  comment = '''ddMulticastActivationRoGrpId'''
          	  val act_consumed_eve_grp_id = get_act_consumed_eve_grp_id(consumed_eve_grp?.shortNamePath?.toString)
              if(!(act_consumed_eve_grp_id.nullOrEmpty))
              {
              	  value = '''«act_consumed_eve_grp_id»'''
              }
              else
              {
               	   value = '''«0.toHex»'''
               }
          ]
          
          members += new Member ()=>
          [
          	   comment = '''ddTcpActivationRoGrpId'''
          	   val TcpActivationRoGrpId = get_con_eve_tcp_act_id(consumed_eve_grp?.shortNamePath?.toString)
          	   if(!(TcpActivationRoGrpId.nullOrEmpty))
          	   {
          	   	   value = '''«TcpActivationRoGrpId»'''
          	   }
          	   else
          	   {
          	   	    value = '''«0.toHex»'''
          	   }
          ]
          
          members += new Member() =>
          [
          	  val UdpActivationRoGrpId = get_con_eve_udp_act_id(consumed_eve_grp?.shortNamePath?.toString)
          	  comment =  '''ddUdpActivationRoGrpId''' 
          	  if(!(UdpActivationRoGrpId.nullOrEmpty))
          	  {
          	  	  value = '''«UdpActivationRoGrpId»'''
          	  }
          	  else
          	  {
          	   	  value = '''«0.toHex»'''
          	   }
          ]
          
          members += new Member() =>
          [
          	  comment = '''ddBaseMulticastSoConGrp'''
              if(sd_con_eve_grp_hash.size > 0 && sd_con_eve_grp_hash.containsKey(consumed_eve_grp?.shortNamePath?.
              	toString
              ))
              {
              	  for(index : sd_con_eve_grp_hash.get(consumed_eve_grp?.shortNamePath?.toString)?.keySet)
              	  {
              	  	  value = '''«index.toHex»'''
              	  }              	  
              }
              else
              {
              	   value = '''«0.toHex»'''
              }
          ]
          members += new Member ()=>
          [
          	  comment = '''ddNoOfMulticastSoConGrp'''
          	  if(sd_con_eve_grp_hash.size > 0 && sd_con_eve_grp_hash.containsKey(consumed_eve_grp?.shortNamePath?.
          	  	toString
          	  ))
          	  {
          	  	  for(index : sd_con_eve_grp_hash.get(consumed_eve_grp?.shortNamePath?.toString)?.values)
          	  	  {
          	  	  	  value = '''«(index.size).toHex»'''
          	  	  }       	  	  
          	  }
          	  else
          	  {
          	  	  value = '''«0.toHex»'''
          	  }
           ]
           
           members += new Member() =>
           [
           	   comment = '''usClientServiceIndex'''
           	   if (client_service_cnt.size > 0)
           	   {
           	   	   value = '''«client_service_cnt.indexOf(client_service?.shortNamePath?.toString).toHex»'''
           	   }
           	   else
           	   {
           	    	value = '''«0.toHex»'''
           	   }   
            ]
            
            members += new Member() =>
            [
            	comment = '''usConEvGrpSelfIndex'''
            	if (consumed_eve_grp_cnt.size > 0)
            	{
            		value = '''«consumed_eve_grp_cnt.indexOf(consumed_eve_grp?.shortNamePath?.toString).toHex»'''
            	}
            	else
            	{
            		value = '''«0.toHex»'''
            	}        		
            ]
            
            members += new Member() =>
            [
            	comment = '''ucCounter'''
                if (consumed_eve_grp_id_hash.size > 0)
                {
                	val uc_count = get_uc_counter(client_service?.shortNamePath?.toString,
                     consumed_eve_grp?.shortNamePath?.toString, consumed_eve_grp?.sdConsumedEventGroupId)
                    value = '''«(uc_count).toHex»'''
                 }
                else
                {
                 	value = '''«0.toHex»'''
                }     
            ]
            
            members += new Member() =>
            [
            	comment = '''stConsumedEvGrpStaticFlag'''
            	value = '''«stConsumedEvGrpStaticFlag(consumed_eve_grp).head»'''
            ]
         ] 
       }
     }
   }
   return cstruct
 }

def stConsumedEvGrpStaticFlag(SdConsumedEventGroup consumed)
{
   var cstruct = new ArrayList<CStruct>
   cstruct += new CStruct()=>
   [
   	  members += new Member()=>
   	  [
   	  	  comment = '''blAutoRequire'''
   	  	  for (value : consumed?.sdConsumedEventGroupAutoRequire_PB)
   	  	  {
   	  	  	  if(value?.toString == 'true')
   	  	  	  {
   	  	  	  	  value = "1"
   	  	  	  }
   	  	  	  else
   	  	  	  {
   	  	  	  	  value = "0"
   	  	  	  }  	  	 
   	  	   }
   	   ]
   	   
   	   members += new Member ()=>
   	   [
   	   	   comment = '''blMulticastActivationRoGrpIdPresent'''
   	   	   val act_consumed_eve_grp_id = get_act_consumed_eve_grp_id(consumed?.shortNamePath?.toString)
   	   	   if (!(act_consumed_eve_grp_id.nullOrEmpty))
   	   	   {
   	   	   	  value = "1"
   	   	   }
   	   	   else
   	   	   {
   	   	   	   value = "0"
   	   	   }
   	   ]
   	   
   	   members += new Member()=>
   	   [
   	   	   comment = '''blTcpActivationRoGrpIdPresent'''
   	   	   val TcpActivationRoGrpId = get_con_eve_tcp_act_id(consumed?.shortNamePath?.toString)
   	   	   if(!(TcpActivationRoGrpId.nullOrEmpty))
   	   	   {
   	   	   	   value = "1"
   	   	   }
   	   	   else
   	   	   {
   	   	   	   value = "0"
   	   	   }
   	   ]
   	   
   	   members += new Member() =>
   	   [
   	   	   comment = '''blUdpActivationRoGrpIdPresent'''
   	   	   val UdpActivationRoGrpId = get_con_eve_udp_act_id(consumed?.shortNamePath?.toString)
   	   	   if(!(UdpActivationRoGrpId.nullOrEmpty))
   	   	   {
   	   	   	   value = "1"
   	   	   }
   	   	   else
   	   	   {
   	   	   	   value = "0"
   	   	   }   	
   	   ]
   	   
   	   members += new Member() =>
   	   [
   	   	   comment = '''ucReserved'''
   	   	   value = "0" 	
   	   ]
   ]
   return cstruct
 }
 

   /*
   *
   * @param consumed_eve_grp String type, coneve_grp_id Integer Type
   * @return None
   */
  def get_uc_counter(String cl_service_path, String consumed_eve_grp, Integer coneve_grp_id)
  {
    var array = new ArrayList<Integer>
    var keyarray = new ArrayList<String>
    var ids = 0
  var uc_counter = 0
  for(hash : consumed_eve_grp_id_hash.get(cl_service_path))
  {
    array.addAll(hash.values)
    keyarray.addAll(hash.keySet)
  }
  for(ids = 0; ids<array.size; ids++)
  {
    if(array.get(ids) == coneve_grp_id)
    {
      if(keyarray.get(ids) == consumed_eve_grp)
      {
      return uc_counter
      }
      else
      {
      uc_counter = uc_counter + 1
      }
    }
  }
  }

   /*
   *
   * @param sokcongrps SoAdSocketConnectionGroup Type
   * @return None
   */

  def get_baseSocketConIndex(SoAdSocketConnectionGroup sokcongrps)
  {
    soc_con_path_ids_hash.forEach
    [p1, p2|
      if(sokcongrps?.shortNamePath?.toString == p1)
      {
        sokcongrps?.soAdSocketConnections?.forEach
        [
          if(p2.get(0) == it?.soAdSocketId && soc_con_ids.contains(p2.get(0)))
          {
            baseSocketConIndex = soc_con_ids.indexOf(p2.get(0))
            no_of_sockets = p2.size
          }
        ]
      }
    ]
  }
  
  /*
   Record Match Callout Name
   */
 
   
   
 /* Sd_Service_group */
 
 def Sd_GaaServicegroupStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ServiceGroupType Sd_GaaServicegroupStatic[«module.sdConfig.sdServiceGroups_PB.sortBy[sdServiceGroupHandleId].size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  servicegroupstatic()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   } 
   

     
  def servicegroupstatic()
  {
    for (sd_inst : sdServiceGroups) {
  

    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupStatic '''
        

         members += new Member ()=>
         [
         	  comment = '''usHandleId'''
         	  value = '''«sd_inst?.sdServiceGroupHandleId.toHex»'''
         ]
         
        
         
        
         ] 
       
    
  }
   return cstruct
 }
 /* Service Group Client Array */
 def Sd_GaaServicegroupClientArray(Sd module){
  '''
  #define «modulePrefix»_START_SEC_CONST_16
  #include "Sd_MemMap.h"
   const uint16 Sd_GaaServicegroupClientArray[«module.sdConfig?.sdServiceGroups_PB.map[sdServiceGroupHandleId]?.filterNull?.size»][«module.sdConfig.sdInstances.map[sdClientServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size»] =
  {
  	
  	«module?.sdConfig?.sdServiceGroups_PB?.toList?.map[servicegroupClientArray(module)].join(",\n")»
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''


   }  
         
 def servicegroupClientArray(SdServiceGroup sdGrp, Sd module)
 {
   
     var clientHandleIds =  module?.sdConfig?.sdInstances?.map[sdClientServices?.filter[sdServiceGroupRefs_PB?.filter[it.reference == sdGrp]?.size > 0]?.filterNull].flatten?.map[sdClientServiceHandleId.intValue]
     

 return ("{"+clientHandleIds.join(",")+"}")
   
  
   
 }  
         
 def Sd_GaaServicegroupServerArray(Sd module){
  '''
  #define «modulePrefix»_START_SEC_CONST_16
  #include "Sd_MemMap.h"
   const uint16 Sd_GaaServicegroupServerArray[«module.sdConfig?.sdServiceGroups_PB.map[sdServiceGroupHandleId]?.filterNull?.size»][«(module.sdConfig?.sdInstances.map[sdServerServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size )»] =
  {
  	«module?.sdConfig?.sdServiceGroups_PB?.toList?.map[servicegroupServerArray(module)]?.join(",\n")»
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''


   } 
         
 def servicegroupServerArray(SdServiceGroup sdGrp, Sd module)
 {
 

var  serverHandleIds = module?.sdConfig?.sdInstances?.map[sdServerServices?.filter[sdServiceGroupRefs_PB?.filter[it.reference == sdGrp]?.size > 0]]?.filterNull?.filterNull?.flatten?.map[sdServerServiceHandleId]
    
return ("{"+serverHandleIds.join(",")+"}")
   
  
   
 } 
  /* Service Group Client Array*/ 
  def Sd_GaaServicegroupClientStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ServicegroupClientArrayType Sd_GaaServicegroupClientStatic[«module.sdConfig.sdServiceGroups_PB.sortBy[sdServiceGroupHandleId].size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  servicegroupClientstatic()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
     def servicegroupClientstatic()
  {
    for (sd_Sgrp : sdServiceGroups) {
  	 
    
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupClienttStatic '''
        
        Sd_Cfg_H.size_Array=0
         members += new Member ()=>
         [
         	for(Sd_inst:sdInstances){
         		for(clientServices:Sd_inst.sdClientServices)
         		if(clientServices?.sdServiceGroupRefs_PB?.filter[it.reference == sd_Sgrp]?.size>0)
         		{
         			
         		Sd_Cfg_H.size_Array	=Sd_Cfg_H.size_Array +1
         	  
         	  }
         	  }
         	  comment = '''usArray_size'''
         	  value = '''«Sd_Cfg_H.size_Array»'''
         ]
         
         
       
    
  ]
  }
  
   return cstruct
 } 
 
 /*Service Group Server Array  */
  def Sd_GaaServicegroupServertStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ServicegroupServerArrayType Sd_GaaServicegroupServerStatic[«module.sdConfig.sdServiceGroups_PB.sortBy[sdServiceGroupHandleId].size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  servicegroupServerstatic()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
     def servicegroupServerstatic()
  {
    for (sd_Sgrp : sdServiceGroups) {
  	 
    
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupServerStatic '''
        
        Sd_Cfg_H.size_Array=0
         members += new Member ()=>
         [
         	for(Sd_inst:sdInstances){
         		for(ServerServices:Sd_inst.sdServerServices)
         		if(ServerServices?.sdServiceGroupRefs_PB?.filter[it.reference == sd_Sgrp]?.size>0)
         		{
         			
         		Sd_Cfg_H.size_Array	=Sd_Cfg_H.size_Array +1
         	  
         	  }
         	  }
         	  comment = '''usArray_size'''
         	  value = '''«Sd_Cfg_H.size_Array»'''
         ]
         
         
       
    
  ]
  }
  
   return cstruct
 } 
 
 
 def Sd_GaaClientProviderAddress(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ProviderConsumerListType Sd_GaaClientServiceAllowedProviderStatic[«sdInstances.map[sdClientServices.map[sdClientServiceAllowedProviders_PB]].flatten.flatten.size»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  clientproviderAddress()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
     def clientproviderAddress()
  {
    for(Sd_inst:sdInstances){
  		for(ServerServices:Sd_inst.sdClientServices){ 
  		 for(ServerServices2 :ServerServices.sdClientServiceAllowedProviders_PB)
  		 {
 

    cstruct += new CStruct()=>
    [
    	
       	  members += new Member()=>
[
comment = "usServiceId"
if(ServerServices?.sdClientServiceId_PB == null)
{
value = '''SD_NULL_PTR'''
}
else
{

value = '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
}

]

  members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]  



    	  members += new Member()=>
[
comment = "SdIpAddressType"
if(ServerServices2.sdIpAddressType == null)
{
value = '''SD_NULL_PTR'''
}
else
{

value = '''«ServerServices2.sdIpAddressType»'''
}

]
  
    
    
    	
    	
    	comment = '''Sd_GaaClientServiceAllowedProviderStatic '''
    	
         members += new Member ()=>
         [
         if(ServerServices2?.sdIpAddressType.toString == "SD_AF_INET"   )
    {
    
           comment = '''AllowedProviderAddress'''
           val array= ServerServices2.sdIpAddress.toString.replace(".",",")
          
              value= '''{«array»}'''
           
    }
          else
    {
    	
            
           	val array= ServerServices2.sdIpAddress.toString.replace(".",",")
          
           	
           	     value= '''{«array»}'''
    }
                    
            
      
         
           
      
                      
           ]
       
       
    
  ]
  
  }
  }
  
  
  }
   return cstruct
 } 
 
 
 def Sd_GaaServerConsumerAddress(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ProviderConsumerListType Sd_GaaServerServiceAllowedConsumerStatic[«sdInstances.map[sdServerServices.map[sdServerServiceAllowedConsumerss_PB]].flatten.flatten.size+'U'»] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  serverconsumerAddress()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
     def  serverconsumerAddress()
  {
  	
    for(Sd_inst:sdInstances){
  		for(ServerServices:Sd_inst.sdServerServices){ 
  		for(ServerServices2:ServerServices.sdServerServiceAllowedConsumerss_PB)
  		 {
 


    cstruct += new CStruct()=>
    [
    	
 
     	  members += new Member()=>
[
comment = "usServiceId"
if(ServerServices?.sdServerServiceId_PB == null)
{
value = '''SD_NULL_PTR'''
}
else
{

value = '''«ServerServices?.sdServerServiceId_PB?.head?.integerValue»'''
}

]  	
     members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]  	
  
    	  members += new Member()=>
[
comment = "SdIpAddressType"
if(ServerServices2.sdIpAddressType == null)
{
value = '''SD_NULL_PTR'''
}
else
{

value = '''«ServerServices2.sdIpAddressType»'''
}

]

  
    	
    	
    	comment = '''Sd_GaaServerServiceAllowedConsumerStatic '''
    	
         members += new Member ()=>
         [
         if(ServerServices2?.sdIpAddressType.toString == "SD_AF_INET"   )
    {
    
           comment = '''AllowedProviderAddress'''
         
           val array= ServerServices2.sdIpAddress.toString.replace(".",",")
          
              value= '''{«array»}'''
           
    }
          else
    {
    	
         
           	val array= ServerServices2.sdIpAddress.toString.replace(".",",")
         
           	     value= '''{«array»}'''
    }
                    
            
      
         
           
      
                      
           ]
       
       
    
  ]
    
  }
  }
  
  
  }
 return cstruct
 } 
 
 def Sd_GaaSd_NvMRamBlockData_Server(){
  ramstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h"
   Sd_ProviderConsumerListType Sd_GaaServerServiceAllowedConsumer[SD_NO_OF_PROVIDED_SERVER_CONSUMER+2]=
  {'''
       val stp = 
  '''};
  #define «modulePrefix»_STOP_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  NvmRamBlockData_Server()
    if (!ramstruct.nullOrEmpty) 
        {
          '''
          «str»
         «ramstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
  def NvmRamBlockData_Server() {
  	ramstruct.clear
  
    for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdServerServices.filter[it.sdServerServiceAllowedConsumerss_PB !== null]) {
            for (ServerServices2 : ServerServices?.sdServerServiceAllowedConsumerss_PB) {
            	
                ramstruct += new CStruct() => [
               
                    members += new Member() => [
                        comment = "usServiceId"
                        if (ServerServices?.sdServerServiceId_PB !== null && ServerServices?.sdServerServiceAllowedConsumerss_PB !== null) {
                            value = '''«ServerServices?.sdServerServiceId_PB?.head?.integerValue»'''
                        }
                    ]
                    
                     members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        if (ServerServices2.sdIpAddressType == null) {
                            value = '''SD_NULL_PTR'''
                        } else {
                            value = '''«ServerServices2.sdIpAddressType»'''
                        }
                    ]
                    members += new Member() => [
                    	comment ='''Server  Services'''
                        if (ServerServices2?.sdIpAddressType.toString == "SD_AF_INET") {
                            comment = '''AllowedProviderAddress'''
                            val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                            value = '''{«array»}'''
                        } else {
                            val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                            value = '''{«array»}'''
                        }
                    ]
                ]
            }
        }
    }
    
   //ramstruct?.toString?.replaceFirst("["," ")
   

    return ramstruct.head
}
 
 
 def Sd_GaaSd_NvMRamBlockData_Client(){
  cstruct2.clear
  val str = '''
  #define «modulePrefix»_START_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h"
   Sd_ProviderConsumerListType Sd_GaaClientServiceAllowedConsumer[SD_NO_OF_ALLOWED_CLIENT_PROVIDER+2]=
  {'''
       val stp = 
  '''};
  #define «modulePrefix»_STOP_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  NvmRamBlockData_Client()
    if (!cstruct2.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct2.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   
   
   def NvmRamBlockData_Client() {
  	
  

   
   

   for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdClientServices) {
            for (ServerServices2 : ServerServices.sdClientServiceAllowedProviders_PB) {
                
                cstruct2 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        value = if (ServerServices?.sdClientServiceId_PB == null) '''SD_NULL_PTR''' else '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
                    ]
                    
                       members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_PROVIDER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        value = if (ServerServices2.sdIpAddressType == null) '''SD_NULL_PTR''' else '''«ServerServices2.sdIpAddressType»'''
                    ]
              
                    members += new Member() => [
                    	comment ='''Client Services'''
                        comment = if (ServerServices2?.sdIpAddressType.toString == "SD_AF_INET") '''AllowedProviderAddress''' else '''AllowedProviderAddress'''
                        val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                        value = '''{«array»}'''
                    ]
                ]
            }
        }
    }
    
    






    return cstruct2
}
  def Sd_GaaSd_NvMRamBlockData_cl(){
  cstruct2.clear
  val str = '''
  #define «modulePrefix»_START_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h"
   Sd_NvMRamBlockData_Server_type Sd_Gaa_NvMRamBlockData_Client[SD_NO_OF_RAM_ALLOWED_CLIENT_PROVIDER]=
  {{{'''
       val stp = 
  '''}}};
  #define «modulePrefix»_STOP_SEC_VAR_INIT_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  NvMRamBlockData_client()
    if (!cstruct2.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct2.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   } 
  def NvMRamBlockData_client()
    {
    	cstruct2.clear
       for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdClientServices) {
            for (ServerServices2 : ServerServices.sdClientServiceAllowedProviders_PB) {
                
                cstruct2 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        value = if (ServerServices?.sdClientServiceId_PB == null) '''SD_NULL_PTR''' else '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        value = if (ServerServices2.sdIpAddressType == null) '''SD_NULL_PTR''' else '''«ServerServices2.sdIpAddressType»'''
                    ]
              
                    members += new Member() => [
                    	comment ='''Client Services'''
                        comment = if (ServerServices2?.sdIpAddressType.toString == "SD_AF_INET") '''AllowedProviderAddress''' else '''AllowedProviderAddress'''
                        val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                        value = '''{«array»}'''
                    ]
                ]
            }
        }
    }
    
    






    return cstruct2.head
           
 
    }
 


 


    

       
  
    
   
   
   
   def Sd_GaaSd_NvMRomBlockData() {
    ramstruct3.clear()
    val str = '''
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    const Sd_NvMRomBlockData_type Sd_Gaa_NvMRomBlockData[1] =
    {
        {
        	
        	'''
    val stp2 = '''
        	,
        	
            {'''
    val stp = '''
            }
        
        

        }
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h" '''
    NvMRomBlockData3()
    NvMRomBlockData1()
    NvMRomBlockData2()
    
    if (!ramstruct3.isEmpty()) {
        '''
        «str»
        «IF  module.sdGeneral.sdEnableAclPolicyCheck == true »
        1,
        0«stp2»
        «ELSE»
        0,
        0«stp2»
        «ENDIF»
        «ramstruct.join("," + System.lineSeparator())+","»
        «ramstruct3.join("," + System.lineSeparator())»
        «stp»
        '''
    }
}

 def NvMRomBlockData3() {

ramstruct2.clear()
                
       ramstruct2 += new CStruct() => [
       	  members += new Member() => [
       	  	comment = "Sd_ACL_PolicyCheck"
       	  value = "SD_FALSE"
       	  	
       	  ]
       	
       	
       ]

  
    }

def NvMRomBlockData1() {
    ramstruct.clear()
    
    for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdServerServices.filter [it.sdServerServiceAllowedConsumerss_PB != null ] ){
            for (ServerServices2 : ServerServices?.sdServerServiceAllowedConsumerss_PB) {
                
                ramstruct += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        if (ServerServices?.sdServerServiceId_PB != null && ServerServices?.sdServerServiceAllowedConsumerss_PB != null) {
                            value = '''«ServerServices?.sdServerServiceId_PB?.head?.integerValue»'''
                        }
                    ]
                      members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        if (ServerServices2.sdIpAddressType == null) {
                            value = '''SD_NULL_PTR'''
                        } else {
                            value = '''«ServerServices2.sdIpAddressType»'''
                        }
                    ]
                    members += new Member() => [
                        comment = '''Server Services'''
                        if (ServerServices2?.sdIpAddressType.toString() == "SD_AF_INET") {
                            comment = '''AllowedProviderAddress'''
                            val array = ServerServices2.sdIpAddress.toString().replace(".", ",")
                            value = '''{«array»}'''
                        } else {
                            val array = ServerServices2.sdIpAddress.toString().replace(".", ",")
                            value = '''{«array»}'''
                        }
                    ]
                ]
            }
        }
    }
}

def NvMRomBlockData2() {
    ramstruct3.clear()
    
     	
       for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdClientServices) {
            for (ServerServices2 : ServerServices.sdClientServiceAllowedProviders_PB) {
                
                ramstruct3 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        value = if (ServerServices?.sdClientServiceId_PB == null) '''SD_NULL_PTR''' else '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
                    ]
                    
                      members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_PROVIDER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        value = if (ServerServices2.sdIpAddressType == null) '''SD_NULL_PTR''' else '''«ServerServices2.sdIpAddressType»'''
                    ]
              
                    members += new Member() => [
                    	comment ='''Client Services'''
                        comment = if (ServerServices2?.sdIpAddressType.toString == "SD_AF_INET") '''AllowedProviderAddress''' else '''AllowedProviderAddress'''
                        val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                        value = '''{«array»}'''
                    ]
                ]
            }
        }
    }
    
    






   
    
         }
         
       def Sd_GaaSd_NvMRamBlockData() {
    ramstruct3.clear()
    cstruct3.clear()
    val str = '''
    #define «modulePrefix»_START_SEC_VAR_INIT_UNSPECIFIED
    #include "Sd_MemMap.h"
   Sd_NvMRamBlockData_type Sd_Gaa_NvMRamBlockData[1] =
    {
      { 
             '''
      val stp3 = '''
              ,
 	 
            
            {'''
    val stp = '''
            }
            
  
    
     
           
       }
    };
    #define «modulePrefix»_STOP_SEC_VAR_INIT_UNSPECIFIED
    #include "Sd_MemMap.h" '''
    NvMRamBlockData3()
    NvMRamBlockData1()
    NvMRamBlockData2()
    NvMRamBlockData4()
    NvMRamBlockData5()
    NvMRamBlockData6()
    
    

    
    if (!ramstruct3.isEmpty() || !ramstruct.isEmpty() ||!ramstruct4.isEmpty() ||!cstruct5.isEmpty() || cstruct3.isEmpty()) {
        '''
      «str»
 
      «IF  module.sdGeneral.sdEnableAclPolicyCheck == true »
      1,
      0«stp3»
      «ELSE»
      0,
      0«stp3»
      «ENDIF»
      «ramstruct.join("," + System.lineSeparator())+","»
      «ramstruct3.join("," + System.lineSeparator())»
      «IF !ramstruct4.isEmpty() »
      «","+ramstruct4.join("," + System.lineSeparator())»
      «ENDIF»
       «IF cstruct5.head != null»
       «","+cstruct5.join("," + System.lineSeparator())»
       «ENDIF»
       
      «IF (cstruct3.head != null)»
      «","+cstruct3.join("," + System.lineSeparator())»
      «ENDIF»
       
   
        
       «stp»
        '''
    }
    else
    {
    	println("Update for I")
    	 '''
    	 «str»
    	 «IF  module.sdGeneral.sdEnableAclPolicyCheck == true »
    	       1,
    	       0«stp3»
    	       «ELSE»
    	       0,
    	       0«stp3»
    	       «ENDIF»
    	       «IF (cstruct3.head != null)»
    	       «cstruct3.join("," + System.lineSeparator())»
    	       «ENDIF»
    	  «stp»
    	 '''
    	
    }
    

    
}
  
 def NvMRamBlockData3() {

ramstruct2.clear()
                
       ramstruct2 += new CStruct() => [
       	  members += new Member() => [
       	  	comment = "Sd_ACL_PolicyCheck"
       	  value = "SD_FALSE"
       	  	
       	  ]
       	
       	
       ]

  
    }
      

    
    
    
        
 
def NvMRamBlockData1() {
    ramstruct.clear()
    
    for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdServerServices.filter [it.sdServerServiceAllowedConsumerss_PB != null ] ){
            for (ServerServices2 : ServerServices?.sdServerServiceAllowedConsumerss_PB) {
                
                ramstruct += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        if (ServerServices?.sdServerServiceId_PB != null && ServerServices?.sdServerServiceAllowedConsumerss_PB != null) {
                            value = '''«ServerServices?.sdServerServiceId_PB?.head?.integerValue»'''
                        }
                    ]
                    
                    members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        if (ServerServices2.sdIpAddressType == null) {
                            value = '''SD_NULL_PTR'''
                        } else {
                            value = '''«ServerServices2.sdIpAddressType»'''
                        }
                    ]
                    members += new Member() => [
                        comment = '''Server Services'''
                        if (ServerServices2?.sdIpAddressType.toString() == "SD_AF_INET") {
                            comment = '''AllowedProviderAddress'''
                            val array = ServerServices2.sdIpAddress.toString().replace(".", ",")
                            value = '''{0,0,«array»}'''
                        } else {
                            val array = ServerServices2.sdIpAddress.toString().replace(".", ",")
                            value = '''{0,0,«array»}'''
                        }
                    ]
                ]
            }
        }
    }
   
}

def NvMRamBlockData4() {
		var int i = 0
    ramstruct4.clear()
    val j = module.get_number6().intValue
    val k = module.get_number7().intValue

    for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdServerServices.filter [it.sdServerServiceAllowedConsumerss_PB != null ] ){
     if(((ServerServices).sdMaxNumOfIpAddressesInAcl !== null)&&((ServerServices ).sdMaxNumOfIpAddressesInAcl.intValue
     	>(ServerServices ).sdServerServiceAllowedConsumerss_PB.size
     ))
     {
     
            while (i < ((ServerServices).sdMaxNumOfIpAddressesInAcl.intValue - (ServerServices).sdServerServiceAllowedConsumerss_PB.size)) {
               
                ramstruct4 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        if (ServerServices?.sdServerServiceId_PB != null && ServerServices?.sdServerServiceAllowedConsumerss_PB != null) {
                            value = '''«ServerServices?.sdServerServiceId_PB?.head?.integerValue»'''
                        }
                    ]
                    
                    members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_CONSUMER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        
                            value = '''SD_WILDCARD_DOMAIN'''
                       
                    ]
                    members += new Member() => [
                        comment = '''Server Services'''
                       
                            comment = '''AllowedProviderAddress'''
                         
                            value = '''{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}'''
                       
                       
                    ]
                ]
             i++
           } 
           }
        }
    }
    return ramstruct4
}


def NvMRamBlockData2() {
    ramstruct3.clear()
    
     	
       for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdClientServices) {
        	
        	
            for (ServerServices2 : ServerServices.sdClientServiceAllowedProviders_PB) 
        
                {    
                	ramstruct3 += new CStruct() => [
              
                    members += new Member() => [
                        comment = "usServiceId"
                        value = if (ServerServices?.sdClientServiceId_PB == null) '''SD_NULL_PTR''' else '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
                    ]
                    
                     members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_PROVIDER_TYPE'''
                    ]
                    
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        value = if (ServerServices2.sdIpAddressType == null) '''SD_NULL_PTR''' else '''«ServerServices2.sdIpAddressType»'''
                    ]
              
                    members += new Member() => [
                    	comment ='''Client Services'''
                        comment = if (ServerServices2?.sdIpAddressType.toString == "SD_AF_INET") '''AllowedProviderAddress''' else '''AllowedProviderAddress'''
                        val array = ServerServices2.sdIpAddress.toString.replace(".", ",")
                        value = '''{0,0,«array»}'''
                    ]
                    
                ]
            
                }
            
            }
        
    }
    
    


        	
        	}

 
def NvMRamBlockData5() {
		var int i = 0
    cstruct5.clear()
    val j = module.get_number5().intValue
    val k = module.get_number8().intValue
   
    for (Sd_inst : sdInstances) {
        for (ServerServices : Sd_inst.sdClientServices.filter [it.sdClientServiceAllowedProviders_PB != null ] ){
     if(((ServerServices ).sdMaxNumOfIpAddressesInAcl !== null)&&((ServerServices ).sdMaxNumOfIpAddressesInAcl.intValue
     	> (ServerServices ).sdClientServiceAllowedProviders_PB.size)
     )
     {
    
            while (i < ((ServerServices ).sdMaxNumOfIpAddressesInAcl.intValue - (ServerServices).sdClientServiceAllowedProviders_PB.size)) {
                
                cstruct5 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        if (ServerServices?.sdClientServiceId_PB != null && ServerServices?.sdClientServiceAllowedProviders_PB != null) {
                            value = '''«ServerServices?.sdClientServiceId_PB?.head?.integerValue»'''
                        }
                    ]
                    
                    members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_PROVIDER_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        
                            value = '''SD_WILDCARD_DOMAIN'''
                       
                    ]
                    members += new Member() => [
                        comment = '''Server Services'''
                       
                            comment = '''AllowedProviderAddress'''
                         
                            value = '''{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}'''
                       
                       
                    ]
                ]
             i++
           } 
           }
        }
    }
}
       
def NvMRamBlockData6() {
		var int i = 0
    cstruct3.clear()
    val j = module. get_number11().intValue
    val k = module.get_number13().intValue+module.get_number12().intValue

   
         if(j!=k)
         {
            while (i < (j - k)) {
                
                cstruct3 += new CStruct() => [
                    members += new Member() => [
                        comment = "usServiceId"
                        value = '''0xFFFF'''
                        
                    ]
                    
                    members += new Member() => [
                    	 comment = "ListMemberType"
                    	 value = '''SD_ANY_TYPE'''
                    ]
                    members += new Member() => [
                        comment = "SdIpAddressType"
                        
                            value = '''SD_WILDCARD_DOMAIN'''
                       
                    ]
                    members += new Member() => [
                        comment = '''Server Services'''
                       
                            comment = '''AllowedProviderAddress'''
                         
                            value = '''{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}'''
                       
                       
                    ]
                ]
             i++
           } 
           
        }
    
}

         
         }
                  
       
       
       
       
       
       

