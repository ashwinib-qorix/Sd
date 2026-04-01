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
import autosar40.genericstructure.varianthandling.PredefinedVariant

import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Dem
import com.kpit.c4k.ecuc.vh.VariantHandlingExtensions
import static com.kpit.c4k.bsw.sd.codegen.Sd_Cfg_PBcfg_H.*
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerTimer
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceAllowedProvider
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdServerServiceHandleId
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdServerServiceAllowedConsumers

/*
 * Provides template for generating configuration for Sd C source file.
 * To be extended by the class providing content to be generated.
 */

@WorkflowComponent
class Sd_Cfg_PBcfg_C extends Cfg_C_Template <Sd> {

  extension Sd_Cfg_PBcfg_H = Sd_Cfg_PBcfg_H.EXTENSION_CFG_H
 
 static extension VariantHandlingExtensions = VariantHandlingExtensions.INSTANCE
  var Iterable <PredefinedVariant> predefinedVariant
  var pbvclist = new ArrayList<PredefinedVariant>
  public static Iterable<PredefinedVariant> Pbvc_list
  var Sd_client_timer_variant = new HashMap<String, Integer>()
  var Sd_server_timer_variant = new HashMap<String, Integer>()
  var Sd_client_timer = new HashMap<String, Integer>()
  var Sd_Instance_variant = new HashMap<String, Integer>()
  var Sd_Instance_variant_pb = new HashMap<String, Integer>()
  var client_timer = new HashMap<String, Integer>()
  var Sd_CE_variant = new HashMap<String, Integer>()
  var Sd_SerEve_variant = new HashMap<String, Integer>()
  var Sd_CliSer_variant = new HashMap<String, Integer>()
  var Sd_Evehdl_variant = new HashMap<String, Integer>()
  var All_cons_variant = new HashMap<String, Integer>()
  var All_prov_variant = new HashMap<String, Integer>()
  var ServiceGrp_variant = new HashMap<String, Integer>()
  var CliSerGrp_variant = new HashMap<String, Integer>()
  var SerSerGrp_variant = new HashMap<String, Integer>()
  var static Hndlindx = 0
  var static CEindx = 0
  var static SerHndlindx = 0
  var static count_0 = 0
  var Sd_Gserverstructinst = 0
  var Sd_Gclientstructinst = 0
  
  var Sd_Ginst_cnt = 0
  var Sd_Gclienttimer_cnt = 0
  var Sd_GEveHandlerstructinst = 0
  var ServertimerIdx = 0
  var ddRxUnicastSoConId = 0
  var ddRxMulticastSoConId = 0
  var baseSocketConIndex = 0
  var no_of_sockets = 0
    var Soad_Gcon_grps = 0
  var ServerTimer_countpb = 0
  var ServerTimer_pb = 0
  var ServiceGrp_count = 0
  var New_ServiceGrp_count = 0
  var New_ServerTimer_countpb = 0
  var ClientTimer_count_vp = 0
  var ClientTimer_count = 0
  var ServerTimer_count = 0
  var ClientTimer_count_pb = 0
  var New_ClientTimer_count = 0
  var New_ServerTimer_count = 0
  var New_ClientTimer_count_pb = 0
  var Instance_count = 0
  var CliSer_count = 0
  var New_Inastance_count = 0
  var Inastance_count_pb = 0
  var New_Inastance_count_pb = 0
  var CE_count = 0
  var New_CE_count = 0
  var SerEve_count = 0
  var New_SerEve_count = 0
  var SerHdlr_count = 0
  var Allcons_count = 0
  var Allprov_count = 0
  var Allowconsumer_count = 0
  var AllowProvid_count = 0
  var New_Allcons_count = 0
  var New_Allprov_count = 0
  var New_CliSdGrpCnt = 0
  var CliSdGrpCnt = 0
  var CliSdGrpCount = 0
  var New_SerSdGrpCnt = 0
  var SerSdGrpCnt = 0
  var New_SerHdlr_count = 0
  var New_CliSer_count = 0
  var act_server_routing_grp = new HashMap<String, String>()
  var act_client_routing_grp = new HashMap<String, String>()
  var act_client_routing_grp_map = new HashMap<String, HashMap<String, String>>()
  var act_server_routing_grp_map = new HashMap<String, HashMap<String, String>>()
  var act_consumed_eve_routing_grp = new HashMap<String, String>()
  var act_consumed_eve_routing_grp_map = new HashMap<String, HashMap<String, String>>()
  var act_eve_hand_udp_routing_grp = new HashMap<String, String>()
  var act_eve_hand_tcp_routing_grp = new HashMap<String, String>()
  var act_eve_hand_routing_grp =  new HashMap<String, String>()
  var act_eve_hand_udp_routing_grp_map = new HashMap<String, HashMap<String, String>>()
  var act_eve_hand_tcp_routing_grp_map = new HashMap<String, HashMap<String, String>>()
  var act_eve_hand_routing_grp_map =  new HashMap<String, HashMap<String, String>>()
  var sd_con_eve_tcp_ref_arr = new HashMap<String, String>()
  var sd_con_eve_tcp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
  var sd_con_eve_udp_ref_arr = new HashMap<String, String>()
  var sd_con_eve_udp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
  var sd_eve_handler_tcp_ref_arr = new HashMap<String, String>()
  var sd_eve_handler_udp_ref_arr = new HashMap<String, String>()
  var sd_eve_hand_multi_soc_con = new HashMap<String, String>()
  var sd_eve_handler_tcp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
  var sd_eve_handler_udp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
  var sd_eve_hand_multi_soc_con_map = new HashMap<String, HashMap<String, String>>()
  var domain_type_hash_vp = new HashMap<String, HashMap<String, String>> 
  var array = new ArrayList<Integer>
  var array1 = new ArrayList<Integer>
  var array2 = new ArrayList<Integer>
  var static client_timer_arr_pb = new ArrayList<String>()
  var client_timer_cnt = 0
  var client_timer_count = 0
  
  var Sd_GConsumedEvstructinst = 0
  Double Sd_main_func_period
  Integer IpAddrSoConId = null
  Integer DemErrorMalformedId = null
  Integer DemErrorOutOfResId = null
  Integer DemErrorSubEventgroupNacId = null
  SoAd _soad
  Sd _Sd
  Dem _dem
  SdBlocklistedVersions _BL
  
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
  
  var inst_uni_multicast_rx_pdu = new ArrayList<Integer>()
  var server_handle_ids = new ArrayList<Integer>()
 
  var SerTimerRef = new ArrayList<String>
  var server_handle_count = new ArrayList<Integer>()
  var sd_timer = new HashMap<String, ArrayList<String>>
  
  var sd_timerref = new ArrayList<String>
  var sd_timercount = new HashMap<String, Integer>()
  var client_handle_ids = new ArrayList<Integer>()
  var SerGrp_handle_ids = new ArrayList<String>()
  var consumed_eve_grp_id_hash = new HashMap<String, ArrayList<HashMap<String, Integer>>>()
  var server_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
  var client_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
  var con_eve_grp_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
  var inst_uni_multicast_rx_pdu_map = new HashMap<String, ArrayList<Integer>>()
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
  List<SdClientServiceAllowedProvider> CliSerAllProv
  
  var cstruct = new ArrayList<CStruct>
  var config_opt_inst_hstnm_hash = get_config_opt_inst_hstnm_index()
   
   
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
	     **                          Parasoft violations Section                       **
		 *******************************************************************************/

		 /* parasoft-begin-suppress MISRAC2012-RULE_20_1-a-4 "Reason: The warning is 
		 * getting reported for the inclusion of 'Sd_MemMap.h', this inclusion can 
		 * not be avoided, so this warning needs to be deviated." */

		 /* parasoft-begin-suppress MISRAC2012-RULE_5_4-c-2 "Reason: The warning is 
		 * getting reported for the memory section declaration which can not be 
		 * avoided, These macros are part of AUTOSAR Specific definitions for
		 * inclusion of memory map files for Code and Global data sections and
		 * configuration Specific macros present in .h, so this warning needs to be
		 * deviated." */

		 /* parasoft-begin-suppress MISRAC2012-RULE_5_4-d-2 "Reason: The warning is 
		 * getting reported for the memory section declaration which can not be avoided,
		 * These macros are part of AUTOSAR Specific definitions for inclusion of 
		 * memory map files for Code and Global data sections and configuration 
		 * Specific macros present in .h, so this warning needs to be deviated ,so 
		 * this warning needs to be deviated." */
		 
		 /* parasoft-begin-suppress MISRAC2012-RULE_1_1-c-2 "Reason: The warning is 
		 * getting reported for the memory section declaration which can not be avoided,
		 * These macros are part of AUTOSAR Specific definitions for inclusion of 
		 * memory map files for Code and Global data sections and configuration 
		 * Specific macros present in .h, so this warning needs to be deviated." */

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
            /*PRQA S 4810 EOF */
		/*#Violates #ref SD_Cfg_REF_2 CMN-0:CMN-0.1,CMN-0.1   M3CM-2:Rule-9.3 Msg(qac-10.1.0-0686)*/
         /*PRQA S 0686 EOF */
         
         /******************************************************************************/
             #include "Sd.h"
             #include "Sd_Cfg.h"
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
  sd_con_eve_tcp_ref_arr_map = get_sd_con_eve_tcp_ref_arr_map()
  sd_con_eve_udp_ref_arr = get_sd_con_eve_udp_ref()
  sd_con_eve_udp_ref_arr_map = get_sd_con_eve_udp_ref_arr_map()
  sd_eve_handler_tcp_ref_arr = get_sd_eve_handler_tcp_ref_arr()
  sd_eve_handler_udp_ref_arr = get_sd_eve_handler_udp_ref_arr()
  sd_eve_handler_tcp_ref_arr_map = get_sd_eve_handler_tcp_ref_arr_map()
  sd_eve_handler_udp_ref_arr_map = get_sd_eve_handler_udp_ref_arr_map()
  server_service_cnt = get_server_services_cnt()
  client_service_cnt = get_client_services_cnt()
  consumed_eve_grp_cnt = get_consumed_eve_grp_cnt()
  
  eve_hand_cnt = get_eve_handler_cnt()
  no_of_Instances = get_no_of_Instances()
  inst_uni_multicast_rx_pdu = get_inst_uni_multicast_rx_pdu()
  inst_uni_multicast_rx_pdu_map = get_inst_uni_multicast_rx_pdu_map()
  act_client_routing_grp = get_act_cl_routing_grp()
  act_client_routing_grp_map = get_act_client_routing_grp_map()
  act_server_routing_grp_map = get_act_server_routing_grp_map()
  act_server_routing_grp = get_act_ser_routing_grp()
  act_consumed_eve_routing_grp = get_act_consumed_eve_routing_grp()
  act_consumed_eve_routing_grp_map = get_act_consumed_eve_routing_grp_map()
  act_eve_hand_udp_routing_grp = get_act_eve_handler_udp_routing_grp()
  act_eve_hand_tcp_routing_grp = get_act_eve_handler_tcp_routing_grp()
  act_eve_hand_routing_grp = get_act_eve_handler_routing_grp()
  sd_eve_hand_multi_soc_con = get_sd_eve_handler_multi_soc_con()
  act_eve_hand_udp_routing_grp_map = get_act_eve_handler_udp_routing_grp_map()
  act_eve_hand_tcp_routing_grp_map = get_act_eve_handler_tcp_routing_grp_map()
  act_eve_hand_routing_grp_map = get_act_eve_handler_routing_grp_map()
  sd_eve_hand_multi_soc_con_map = get_sd_eve_handler_multi_soc_con_map()
  client_timer_cnt = get_client_timer_cnt()
  server_timer_cnt_vp = get_server_timer_cnt_vp()
  SerGrp_handle_ids = get_SerGrp_handle_ids()
  Soad_client_con_ev_grp = get_Soad_client_con_ev_grp()
  sd_con_eve_grp_hash = get_sd_con_eve_grp_hash()
  consumed_eve_grp_id_hash = get_consumed_eve_grp_id_hash()
  server_handle_ids_map = get_server_handle_ids_map()
  client_handle_ids_map = get_client_handle_ids_map()
  con_eve_grp_handle_ids = get_con_eve_grp_handle_ids()
  con_eve_grp_handle_ids_map =  get_con_eve_grp_handle_ids_map()
  domain_type_hash_vp = domain_type_ipv4_vp()
  server_handle_ids = get_server_handle_ids()
  server_handle_count = get_server_handle_count()
  client_handle_ids = get_client_handle_ids()
  Soad_cnt_arr = get_Soad_cnt_arr()
  sdServiceGroups =  module.sdConfig.sdServiceGroups_PB
  sdInstances = module.sdConfig.sdInstances
  sort_used_ser_grp_arr = get_service_grp_arr1()
  fill_soad_con_array()
  fill_soad_details()
  get_used_soc_con_grp_arr()
   if (!module?.getPredefinedVariants.nullOrEmpty)
    {
      Pbvc_list = module?.getPredefinedVariants.sortBy[shortName]
      write('''
	  
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
      «««.........................Start For Sd_GSaaClientTimerStatic Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF client_timer_cnt > 0»
      «Sd_GSaaClientTimerStatic»
      «ENDIF»
      «««.........................Start For Sd_GaaConEvGrpHandleMapArray Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF con_eve_grp_handle_ids.size > 0»
          #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
          #include "Sd_MemMap.h"
          /* Sd_GaaConEvGrpHandleMapArray */
          const Sd_ServicesType Sd_GaaConEvGrpHandleMapArray[«consumed_eve_grp_cnt.size»] = {
          «var Lconseve_hand_ids = get_conEvGrpHandleMapArray()»
          «Lconseve_hand_ids.join(', ')»
          };
          #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
          #include "Sd_MemMap.h"
      «ENDIF»
  «/* Design ID : SD_SDD_0180,SD_SDD_0182,SD_SDD_0181,SD_SDD_0063,SD_SDD_0184,SD_SDD_0183  */»
  «/* Design ID : SD_SDD_0065,SD_SDD_0186,SD_SDD_0064,SD_SDD_0185,SD_SDD_0067,SD_SDD_0066 */»
  «/* Design ID : SD_SDD_0068,SD_SDD_0500,SD_SDD_0072,SD_SDD_0193,SD_SDD_0192,SD_SDD_0195 */»
  «/* Design ID : SD_SDD_0073,SD_SDD_0194,SD_SDD_0197,SD_SDD_0075,SD_SDD_0196,SD_SDD_0199*/»
  «/* Design ID : SD_SDD_0077,SD_SDD_0198,SD_SDD_0079,SD_SDD_0511,SD_SDD_0510,SD_SDD_0502 */»
      «««.........................Start For Sd_GaaClientHandleMapArray Array............................»»
      «/* Design ID : SD_SDD_0055 */»
      «IF client_handle_ids.size > 0»
      #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
      #include "Sd_MemMap.h"
      /* Sd_GaaClientHandleMapArray */
      const Sd_ServicesType Sd_GaaClientHandleMapArray[«client_service_cnt.size * Pbvc_list.size»] = {
      «var Lcli_hand_ids = get_cli_handlemaparray()»
      «Lcli_hand_ids.join(', ')»
      };
      #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
      #include "Sd_MemMap.h"
      «ENDIF»
      
      «««.........................Start For Sd_GSaaServerTimerStatic Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF sdInstances.map[sdServerTimers].flatten.size > 0»
      «Sd_GSaaServerTimerStatic»
      «ENDIF»
      «««.........................Start For Sd_GaaConfig Array............................»»
      #define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
      #include "Sd_MemMap.h"
      const Sd_ConfigType Sd_GaaConfig[SD_NUM_OF_CFG_SETS] =
          {
            «Pbvc_list.map[gaaConfig_PB(it)].join(',\n\n')»
          };
      #define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
      #include "Sd_MemMap.h"
      «««.........................Start For Sd_GaaServerServiceStatic Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF server_service_cnt.size > 0»
      «Sd_GaaServerServiceStatic»
      «ENDIF»
      «««.........................Start For Sd_GaaServerHandleMapArray Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF server_handle_ids.size > 0»
      #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
      #include "Sd_MemMap.h"
      /* Sd_GaaServerHandleMapArray */
      const Sd_ServicesType Sd_GaaServerHandleMapArray[«server_service_cnt.size»] = {
               «var Lserver_hand_ids = get_serv_handlemaparray()»
               «Lserver_hand_ids.join(', ')»
          };
      #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
      #include "Sd_MemMap.h"
      «ENDIF»
      «««.........................Start For Sd_GaaClientServiceStatic Array............................»»
      «/* Design ID : SD_SDD_0055 */»
      «IF client_service_cnt.size > 0»
      «Sd_GaaClientServiceStatic»   
      «ENDIF»
      «««.........................Start For Sd_GaaEvHandlerStatic Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF eve_hand_cnt.size > 0»
      «Sd_GaaEvHandlerStatic»
      «ENDIF»
      «««.........................Start For Sd_GaaConsumedEvGrpStatic Array............................»»
      «/* Design ID : SD_SDD_0055  */»
      «IF consumed_eve_grp_cnt.size > 0»
      «Sd_GaaConsumedEvGrpStatic»
      «ENDIF»
      «««.........................Start For Sd_GaaServicegroupStatic Array............................»»
      «IF SerGrp_handle_ids.size > 0»
      «Sd_GaaServicegroupStatic()»
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
  «/* Design ID : SD_SDD_0501,SD_SDD_0504,SD_SDD_0503,SD_SDD_0506,SD_SDD_0505,SD_SDD_0508*/»
  «/* Design ID : SD_SDD_0507,SD_SDD_0509,SD_SDD_0081,SD_SDD_0080,SD_SDD_0085,SD_SDD_0087*/»
  «/* Design ID : SD_SDD_0086,SD_SDD_0089,SD_SDD_0088,SD_SDD_0520,SD_SDD_0522,SD_SDD_0400*/»
  «/* Design ID : SD_SDD_0521,SD_SDD_0512,SD_SDD_0515,SD_SDD_0514,SD_SDD_0517,SD_SDD_0516*/»
  «/* Design ID : SD_SDD_0519,SD_SDD_0518,SD_SDD_0090,SD_SDD_0092,SD_SDD_0091,SD_SDD_0094*/»
  «/* Design ID : SD_SDD_0093,SD_SDD_0096,SD_SDD_0095,SD_SDD_0098,SD_SDD_0097,SD_SDD_0099*/»
  «/* Design ID : SD_SDD_0531,SD_SDD_0410,SD_SDD_0530,SD_SDD_0533,SD_SDD_0412,SD_SDD_0532*/»
      «««.............   /* «Sd_GaaClientProviderAddress()»*/......................»» 
      «IF (module?.sdGeneral?.sdEnableAclPolicyCheck) == true»
      «Sd_GaaClientProviderAddress()»
      «««.............   /* «Sd_GaaServerConsumerAddress()»*/......................»»                    
      «Sd_GaaServerConsumerAddress()»
      «ENDIF»
      
       «/* Design ID : SD_SDD_0055  */»
          «IF sort_used_soc_con_grp_arr.size > 0»
            «Sd_GaaSoConGroupStatic»
          «ENDIF»
          
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
      ''')
    }
    else
    {
     write('''
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
    «««.........................Start For Sd_GSaaClientTimerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF client_timer_cnt > 0»
    «Sd_GSaaClientTimerStaticNoVP»
    «ENDIF»
    «««.........................Start For Sd_GaaConEvGrpHandleMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
	«/* Design ID : SD_SDD_0411,SD_SDD_0524,SD_SDD_0403,SD_SDD_0523,SD_SDD_0526,SD_SDD_0405*/»
    «/* Design ID : SD_SDD_0411,SD_SDD_0524,SD_SDD_0403,SD_SDD_0523,SD_SDD_0526,SD_SDD_0405*/»
    «/* Design ID : SD_SDD_0525,SD_SDD_0404,SD_SDD_0528,SD_SDD_0407,SD_SDD_0527,SD_SDD_0409*/»
    «IF con_eve_grp_handle_ids.size > 0»
        #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
        #include "Sd_MemMap.h"
        /* Sd_GaaConEvGrpHandleMapArray */
        const Sd_ServicesType Sd_GaaConEvGrpHandleMapArray[«con_eve_grp_handle_ids.size»] = {
          «var Lconseve_hand_ids = get_conEvGrpHandleMapArray()»
          «Lconseve_hand_ids.join(', ')»
        };
        #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
        #include "Sd_MemMap.h"
        «ENDIF»
    «««.........................Start For Sd_GaaClientHandleMapArray Array............................»»
    «/* Design ID : SD_SDD_0055 */»
    «IF client_handle_ids.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
        /* Sd_GaaClientHandleMapArray */
        const Sd_ServicesType Sd_GaaClientHandleMapArray[«client_handle_ids.size»] = {
          «var Lcli_hand_ids = get_cli_handlemaparray()»
          «Lcli_hand_ids.join(', ')»
        };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
        «ENDIF»
    
    «««.........................Start For Sd_GSaaServerTimerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF sdInstances.map[sdServerTimers].flatten.size > 0»
    «Sd_GSaaServerTimerStaticNoVP»
    «ENDIF»
    «««.........................Start For Sd_GaaConfig Array............................»»
    #define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h"
    const Sd_ConfigType Sd_GaaConfig[SD_NUM_OF_CFG_SETS] =
      {
        «gaaConfig_PBNoVp()»
      };
    #define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h"
    «««.........................Start For Sd_GaaServerServiceStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF server_service_cnt.size > 0»
    «Sd_GaaServerServiceStaticNoVp»
    «ENDIF»
    «««.........................Start For Sd_GaaServerHandleMapArray Array............................»»
     «/* Design ID : SD_SDD_0055  */»
     «IF server_handle_ids.size > 0»
     #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
     #include "Sd_MemMap.h"
     /* Sd_GaaServerHandleMapArray */
     const Sd_ServicesType Sd_GaaServerHandleMapArray[«server_handle_ids.size»] = {
              «var Lserver_hand_ids = get_serv_handlemaparray()»
                   «Lserver_hand_ids.join(', ')»
              };
     #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
     #include "Sd_MemMap.h"
    «ENDIF»
    «««.........................Start For Sd_GaaClientServiceStatic Array............................»»
    «/* Design ID : SD_SDD_0055 */»
    «IF client_service_cnt.size > 0»
    «Sd_GaaClientServiceStaticNoVp»   
    «ENDIF»
    «««.........................Start For Sd_GaaEvHandlerStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF eve_hand_cnt.size > 0»
    «Sd_GaaEvHandlerStaticNoVp»
    «ENDIF»
    «««.........................Start For Sd_GaaConsumedEvGrpStatic Array............................»»
     «/* Design ID : SD_SDD_0055  */»
     «IF consumed_eve_grp_cnt.size > 0»
     «Sd_GaaConsumedEvGrpStaticNoVp()»
     «ENDIF»
     «««.........................Start For Sd_GaaServicegroupStatic Array............................»»
     «Sd_GaaServicegroupStaticNoVp()»
     «««.........................Start For Sd_GaaServicegroupClientArray Array............................»» 
     «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
     «Sd_GaaServicegroupClientArrayNoVp(module)»
     «ENDIF»
         «««.........................Start For Sd_GaaServicegroupServerArray Array............................»» 
         «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdServerServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
         «Sd_GaaServicegroupServerArrayNoVp(module)»
         «ENDIF»
         «««.........................Start For Sd_GaaServicegroupClientStatic Array............................»» 
         «IF((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten.size>0))»
         «Sd_GaaServicegroupClientStaticNoVp()»
         «ENDIF»
         «««.........................Start For Sd_GaaServicegroupServertStatic Array............................»» 
         «IF ((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdServerServices?.map[sdServiceGroupRefs_PB?.size]]?.filterNull?.flatten?.size>0))»
         «Sd_GaaServicegroupServertStaticNoVp()»
         «ENDIF»
          «««.............   /* «Sd_GaaClientProviderAddress()»*/......................»» 
          «IF (module?.sdGeneral?.sdEnableAclPolicyCheck) == true»
          «Sd_GaaClientProviderAddressNoVp()»
          «««.............   /* «Sd_GaaServerConsumerAddress()»*/......................»»                    
          «Sd_GaaServerConsumerAddressNoVp()»
          «ENDIF» 
          «/* Design ID : SD_SDD_0055  */»
          «IF sort_used_soc_con_grp_arr.size > 0»
          «Sd_GaaSoConGroupStatic»
	  «ENDIF»
	  
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
 
    ''')
    }

  write('''
   
   «««.........................Start For Sd_GaaRxPduMapArray Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF no_of_Instances.size > 0»
    #define «modulePrefix»_START_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    /* Sd_GaaRxPduMapArray */
    const Sd_ServicesType Sd_GaaRxPduMapArray[«(no_of_Instances.size)*2»] = {
    «var Lpdumaparray = get_rxpdumaparray()»
    «Lpdumaparray.join(', ')»
    };
    #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
    #include "Sd_MemMap.h"
    «ENDIF»
  «««.........................Start For Sd_GaaInstanceStatic Array............................»»
    «/* Design ID : SD_SDD_0055  */»
    «IF sdInstances.size > 0»
     «Sd_GaaInstanceStatic»   
    «ENDIF»
    
   ''')
valClear()
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
 
def valClear() {
		
		count_0 = 0
	}
   /*
   * Collecting ServerServiceHandleId
   * @param None
   * @return array
   */
  def get_serv_handlemaparray()
  {
    var array = new ArrayList<Integer>()
    //var arr_ids = new ArrayList<Integer>()
    
    if(!Pbvc_list.nullOrEmpty)
    {
      for (iter :Pbvc_list)
      {
   	     var arr_ids1 = new ArrayList<Integer>()
   	     var arr_ids = new ArrayList<Integer>()
   	     arr_ids = server_handle_ids_map.get(iter?.shortName)
   	     arr_ids1 = server_handle_ids_map.get(iter?.shortName)
   	     
   	     for(ids: arr_ids1.sort)
         {
             
              if(arr_ids.contains(ids))
              {
                 
                 array.add(arr_ids.indexOf(ids))
                 
              }
          }
   	  }
   }
   else
   {
   	var arr_ids = new ArrayList<Integer>()

    arr_ids = server_handle_ids

    for(ids: arr_ids.sort)
    {
     if(server_handle_ids.contains(ids))
     {
      array.add(server_handle_ids.indexOf(ids))
     }
    }
   }
   return array
  }
  
  
  
  /*
   * Collecting ServerServiceHandleId when variation point is configured
   * @param None
   * @return array
   */

def get_serv_handlemaparrayVp()
  {
    var arr_ids = new ArrayList<Integer>()
    arr_ids = server_handle_ids
    return arr_ids
  }

/* Sd_GaaConfig: when variants are configured and module is PB */
def gaaConfig_PB(PredefinedVariant iter1)
{
	          val Instances = module.sdConfig.sdInstances
	          var cstruct = new ArrayList<CStruct>
              ClientTimer_count = New_ClientTimer_count
              ClientTimer_count_pb = New_ClientTimer_count_pb
              ServerTimer_count = New_ServerTimer_count
              Inastance_count_pb = New_Inastance_count_pb
      		  Instance_count = New_Inastance_count
      		  CE_count = New_CE_count
      		  SerEve_count = New_SerEve_count
      		  CliSer_count = New_CliSer_count
      		  SerHdlr_count = New_SerHdlr_count
      		  Allcons_count = New_Allcons_count
      		  Allprov_count = New_Allprov_count
      		  Allowconsumer_count = 0
      		  AllowProvid_count = 0
      		  CliSdGrpCnt = New_CliSdGrpCnt
              SerSdGrpCnt = New_SerSdGrpCnt
              ServiceGrp_count = New_ServiceGrp_count 
      		  for(Ints:Instances)
      		  {
      		  	if(client_timer_cnt > 0)
      		  	{
      		  		var client_timer_arr_vp = get_client_Timer_ids_map()
                var client_timer_arr = client_timer_arr_vp?.get(iter1?.shortName) 
                 for (itr : 0..< client_timer_arr.size){
                 for (client_timers : Ints?.sdClientTimers){
                  if (client_timer_arr.get(itr).equals((client_timers.shortNamePath).toString)){
      		  		  Sd_client_timer.put(iter1.toString,ClientTimer_count_pb)
      		  		  New_ClientTimer_count_pb++
      		  		  ClientTimer_count++
      		  		  
      		  		  Sd_client_timer_variant.put(iter1.toString,ClientTimer_count)
      		  		}
      		  	  }
      		  	}
      		  	}
      		  	
      		   if (sdInstances.map[sdServerTimers].flatten.size > 0)
      		   {
      		   	    var Timer_pb = get_server_Timer_ids_map()
                    var Timer = Timer_pb?.get(iter1?.shortName)
                    for(server_service : Timer)
      		        {
      		  		Sd_server_timer_variant.put(iter1.toString,ServerTimer_count)
      		  		New_ServerTimer_count++
      		  		}
      		   }
      		    
      		  if(!sdInstances.map[sdInstanceLocalAdressCheckLength_PB].nullOrEmpty){
      		  	if(sdInstances.map[sdInstanceLocalAdressCheckLength_PB].head.filterVariant(iter1,Ints.toString) !== null)
      		  	{
      		  		Sd_Instance_variant.put(iter1.toString,Instance_count)
      		  		New_Inastance_count++
      		  	}
      		  	
      		  	}
      		  	Sd_Instance_variant_pb.put(iter1.toString,Inastance_count_pb)
      		  	New_Inastance_count_pb++
      		  	
      		  	for(client_service : Ints?.sdClientServices)
      		    {
      		  		for(cl_service_timer : client_service?.sdClientServiceTimerRef_PB?.filterVariant(iter1,Ints.toString))
                     {
                       if(!(client_timer_arr_pb?.contains((cl_service_timer.reference.shortNamePath)?.toString)))
                     {
                     client_timer_count = client_timer_count + 1
                     client_timer_arr_pb.add((cl_service_timer?.reference.shortNamePath)?.toString)
                     }
                    }
                    client_timer.put(iter1.toString, client_timer_count)
      		  		
      		  		for (consumed_eve_grp : client_service?.sdConsumedEventGroups)
      		  		{
                      if(!consumed_eve_grp.toString.nullOrEmpty)
                       {
      		  		     Sd_CE_variant.put(iter1.toString,CE_count)
      		  		     New_CE_count++
      		  	       }
      		  	     }
      		  	}
      		  	
      		  	for(server_service : Ints?.sdServerServices)
      		    {
      		  	    if(!server_service.toString.nullOrEmpty)
      		  	    {
      		  		Sd_SerEve_variant.put(iter1.toString,SerEve_count)
      		  		New_SerEve_count++
      		  	    }
      		  	}
      		  	    
      		  	
      		  	for(client_service : Ints?.sdClientServices)
      		    {
      		  	    if(!client_service.toString.nullOrEmpty)
      		  	    {
      		  		Sd_CliSer_variant.put(iter1.toString,CliSer_count)
      		  		New_CliSer_count++
      		  	    }
      		  	}
      		  	for(server_service : Ints?.sdServerServices)
      		    {
      		  	  for (ev_hand : server_service?.sdEventHandlers)
      		  	   { 
      		  	     if(!ev_hand.toString.nullOrEmpty)
      		  	     {
      		  		  Sd_Evehdl_variant.put(iter1.toString,SerHdlr_count)
      		  		  New_SerHdlr_count++
      		  	     }
      		  	   }
      		  	}
      		  if(module?.sdGeneral?.sdEnableAclPolicyCheck == true)
      		  {
      		  	for(server_service : Ints?.sdServerServices)
      		    {
      		  	  for (All_cons : server_service?.sdServerServiceAllowedConsumerss_PB?.filterVariant(iter1,Ints.toString)?.toSet)
      		  	   { 
      		  	     if(!All_cons.toString.nullOrEmpty)
      		  	     {
      		  		  All_cons_variant.put(iter1.toString,Allcons_count)
      		  		  New_Allcons_count++
      		  		  Allowconsumer_count++
      		  	     }
      		  	   }
      		  	}
      		  	for(client_service : Ints?.sdClientServices)
      		    {
      		  	  for (All_Prov : client_service?.sdClientServiceAllowedProviders_PB?.filterVariant(iter1,Ints.toString)?.toSet)
      		  	   { 
      		  	     if(!All_Prov.toString.nullOrEmpty)
      		  	     {
      		  		  All_prov_variant.put(iter1.toString,Allprov_count)
      		  		  New_Allprov_count++
      		  		  AllowProvid_count++
      		  	     }
      		  	   }
      		  	}
      		  }
      		  for(client_service : Ints?.sdClientServices)
      		  {
      		  	for (grpref : client_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,Ints.toString)?.toSet)
      		  	 {
      		      if((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (grpref != 0))
      		      {
      		  	   CliSerGrp_variant.put(iter1.toString,CliSdGrpCnt)
      		  	   New_CliSdGrpCnt++
      		      }
      		     }
      		  }
      		  for(ser_service : Ints?.sdServerServices)
      		  {
      		  	for (grpref1 : ser_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,Ints.toString)?.toSet)
      		  	 {
      		      if((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (grpref1 != 0))
      		      {
      		  	   SerSerGrp_variant.put(iter1.toString,SerSdGrpCnt)
      		  	   New_SerSdGrpCnt++
      		      }
      		     }
      		  }
      		  
      		}
      		for(sdsergrp : module.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1,module.sdConfig.toString)?.filterNull?.toSet)
      		{
      		  	if(sdsergrp != null)
      		  	{
      		  		ServiceGrp_variant.put(iter1.toString,ServiceGrp_count)
      		  	    New_ServiceGrp_count++
      		  	}
      		}
     
    	cstruct += new CStruct() =>[
    		comment = '''Sd_GaaConfig : «count_0++» - PostBuildConfigSet_«iter1.shortName»'''
    			
    			members += new Member() =>
    			[
    				comment = "*ulStartOfDbToc"
    				value = dbtoc.toString
    			]    		
             if(Sd_client_timer_variant.size > 0 )
             {
             	members += new Member() =>
    			[
    				comment = "*pSd_GSaaClientTimerStatic"
    				value = '&Sd_GSaaClientTimerStatic['+Sd_client_timer.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdClientTimerCount"
    				
    				value = client_timer.get(iter1.toString).toString
    			]
             }
    		 if(Sd_Instance_variant.size > 0 )
             {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaInstanceStatic"
    				value = '&Sd_GaaInstanceStatic['+Sd_Instance_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdInstanceIndexValue"
    				value = Sd_Instance_variant.get(iter1.toString).toString
    			]
    			
    		  }
    		 if(Sd_CE_variant.size > 0 )
              {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaConsumedEvGrpStatic"
    				value = '&Sd_GaaConsumedEvGrpStatic['+Sd_CE_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaConEvGrpHandleMapArray"
    				value = '&Sd_GaaConEvGrpHandleMapArray['+Sd_CE_variant.get(iter1.toString)+']'
    			]
    		   }
    		  if(Sd_SerEve_variant.size > 0 )
              {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaServerServiceStatic"
    				value = '&Sd_GaaServerServiceStatic['+Sd_SerEve_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaServerHandleMapArray"
    				value = '&Sd_GaaServerHandleMapArray['+Sd_SerEve_variant.get(iter1.toString)+']'
    			]
    		   }
    		if(Sd_server_timer_variant.size > 0 )
             {
             	members += new Member() =>
    			[
    				comment = "*pSd_GSaaServerTimerStatic"
    				value = '&Sd_GSaaServerTimerStatic['+Sd_server_timer_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdServerTimerIndexValue"
    				value = Sd_server_timer_variant.get(iter1.toString).toString
    			]
             }
             if(Sd_CliSer_variant.size > 0 )
             {
             	members += new Member() =>
    			[
    				comment = "*pSd_GaaClientServiceStatic"
    				value = '&Sd_GaaClientServiceStatic['+Sd_CliSer_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaClientHandleMapArray"
    				value = '&Sd_GaaClientHandleMapArray['+Sd_CliSer_variant.get(iter1.toString)+']'
    			]
    		  }
    		  	
    		  if(Sd_Evehdl_variant.size > 0 )
              {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaEvHandlerStatic"
    				value = '&Sd_GaaEvHandlerStatic['+Sd_Evehdl_variant.get(iter1.toString)+']'
    			]
    		  }
    		  if(module?.sdGeneral?.sdEnableAclPolicyCheck == true)
      		  {
    		   if(All_cons_variant.size > 0 )
               {	
    			members += new Member() =>
    			[
    				comment = "*pSdAllowedConsumerStatic"
    				value = '&Sd_GaaServerServiceAllowedConsumerStatic['+All_cons_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdAllowedConsumerStaticCount"
    				value = Allowconsumer_count.toString
    			]
    		   }
    		   if(All_prov_variant.size > 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pSdAllowedProviderStatic"
    				value = '&Sd_GaaClientServiceAllowedProviderStatic['+All_prov_variant.get(iter1.toString)+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdAllowedProviderStaticCount"
    				value = AllowProvid_count.toString
    			]
    		   }
    		  }
    		   if(CliSerGrp_variant.size > 0)
               {	
    			
    			members += new Member() =>
    			[
    				comment = "*pServgrpCliArray"
    				value = '&Sd_GaaServicegroupClientArray['+ServiceGrp_variant.get(iter1.toString)+']['+CliSerGrp_variant.get(iter1.toString)+']'
    			]
    		   }
    		   if(SerSerGrp_variant.size > 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pServgrpSerArray"
    				value = '&Sd_GaaServicegroupServerArray['+ServiceGrp_variant.get(iter1.toString)+']['+SerSerGrp_variant.get(iter1.toString)+']'
    			]
    			
    		   }
    		  if(New_ServiceGrp_count.intValue != 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pServgrpStatic"
    				value = '&Sd_GaaServicegroupStatic['+ServiceGrp_variant.get(iter1.toString)+']'
    			]
    			if(CliSerGrp_variant.size > 0)
               {
    			members += new Member() =>
    			[
    				comment = "*pServgrpCliStatic"
    				value = '&Sd_GaaServicegroupClientStatic['+ServiceGrp_variant.get(iter1.toString)+']'
    			]
    			
    			}
    			if(SerSerGrp_variant.size > 0)
               {
    			members += new Member() =>
    			[
    				comment = "*pServgrpSerStatic"
    				value = '&Sd_GaaServicegroupServerStatic['+ServiceGrp_variant.get(iter1.toString)+']'
    			]
    			
    			}
    		   }
    		   if(New_Inastance_count_pb.intValue != 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pRxPduMapArray"
    				value = '&Sd_GaaRxPduMapArray['+(Sd_Instance_variant_pb.get(iter1.toString) * 2)+']'
    			]
    		   }
    	]
    	return cstruct.head
}



def gaaConfig_PBNoVp()
{
	 val Instances = module.sdConfig.sdInstances
     val cstruct = new ArrayList<CStruct>
     count_0 = 0
     ClientTimer_count = New_ClientTimer_count
     Instance_count = New_Inastance_count
     ServerTimer_count = New_ServerTimer_count
     CE_count = New_CE_count
     SerEve_count = New_SerEve_count
     CliSer_count = New_CliSer_count
     SerHdlr_count = New_SerHdlr_count
     Allcons_count = New_Allcons_count
     Allprov_count = New_Allprov_count
     ServiceGrp_count = 0
     Allowconsumer_count = 0
     AllowProvid_count = 0
      		  for(Ints:Instances)
      		  {
      		  	 New_Inastance_count_pb++
      		  	if(Ints.sdClientTimers.head != null)
      		  	{
      		  		New_ClientTimer_count++
      		  	}
      		  	
      		  	if(sdInstances.map[sdInstanceLocalAdressCheckLength_PB].head !== null)
      		  	{
      		  		New_Inastance_count++
      		  	}
      		  	if(Ints.sdClientServices.head != null)
      		  	{
      		  		New_CliSer_count++
      		  	}
      		  	if(Ints?.sdClientServices.map[sdConsumedEventGroups].head != null)
      		    {
      		  		New_CE_count++
      		  	}
      		  	
      		  	if(Ints.sdServerServices.head != null)
      		  	 {
      		  		New_SerEve_count++
      		  	 }
      		  	
      		  	if(Ints.sdServerTimers.head != null)
      		  	{
      		  		New_ServerTimer_count++
      		  	}
      		  	for(server_service : Ints?.sdServerServices)
      		    {
      		  	  for (ev_hand : server_service?.sdEventHandlers)
      		  	   { 
      		  	     if(!ev_hand.toString.nullOrEmpty)
      		  	     {
      		  	        New_SerHdlr_count++
      		  	     }
      		  	   }
      		  	}
      		  if(module?.sdGeneral?.sdEnableAclPolicyCheck == true)
      		  {
      		  	for(server_service : Ints?.sdServerServices)
      		    {
      		  	  for (All_cons : server_service?.sdServerServiceAllowedConsumerss_PB?.toSet)
      		  	   { 
      		  	     if(!All_cons.toString.nullOrEmpty)
      		  	     {
      		  		  New_Allcons_count++
      		  		  Allowconsumer_count++
      		  	   }
      		  	  }
      		  	 }
      		  	 for(client_service : Ints?.sdClientServices)
      		    {
      		  	  for (All_Prov : client_service?.sdClientServiceAllowedProviders_PB?.toSet)
      		  	   { 
      		  	     if(!All_Prov.toString.nullOrEmpty)
      		  	     {
      		  		 New_Allprov_count++
      		  		 AllowProvid_count++
      		  	  }
      		  	 }
      		  	}
      		  }
      		  if ((module.sdConfig?.sdServiceGroups_PB !== null) && module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB]] !== null)
      		  	
      		  {
      		  if((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size > 0) && (module?.sdConfig?.sdInstances?.map[sdClientServices?.map[sdServiceGroupRefs_PB]]?.filterNull?.flatten.size>0) )
      		  {
      		  	New_CliSdGrpCnt++
      		  }
      		  
      		  }
      		  
      		  if((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0) && (module?.sdConfig?.sdInstances?.map[sdServerServices?.map[sdServiceGroupRefs_PB]]?.filterNull?.flatten.size>0))
      		  {
      		  	New_SerSdGrpCnt++
      		  }
      		  if((module.sdConfig?.sdServiceGroups_PB?.filterNull?.size>0))
      		  {
      		  	New_ServiceGrp_count++
      		  }
      		  }
	/* Sd_GaaConfig: when no variants are configured and module is PB */
	cstruct += new CStruct() =>[
    		comment = '''Sd_GaaConfig : «count_0++»'''
    			
    			members += new Member() =>
    			[
    				comment = "*ulStartOfDbToc"
    				value = dbtoc.toString
    			]    		
              if(New_ClientTimer_count.intValue !=0)
               {
    			members += new Member() =>
    			[
    				comment = "*pSd_GSaaClientTimerStatic"
    				value = '&Sd_GSaaClientTimerStatic['+ClientTimer_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdTimerIndexValue"
    				value = ClientTimer_count.toString
    			]
    		   }
    		   if(New_Inastance_count.intValue !=0)
               {
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaInstanceStatic"
    				value = '&Sd_GaaInstanceStatic['+Instance_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdInstanceIndexValue"
    				value = Instance_count.toString
    			]
    		   }
    		  if(New_CE_count.intValue !=0)
      		  {
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaConsumedEvGrpStatic"
    				value = '&Sd_GaaConsumedEvGrpStatic['+CE_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaConEvGrpHandleMapArray"
    				value = '&Sd_GaaConEvGrpHandleMapArray['+CE_count+']'
    			]
    		   }
    		   if(New_SerEve_count.intValue !=0)
      		   {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaServerServiceStatic"
    				value = '&Sd_GaaServerServiceStatic['+SerEve_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaServerHandleMapArray"
    				value = '&Sd_GaaServerHandleMapArray['+SerEve_count+']'
    			]
    		   }
    		   if(New_ServerTimer_count.intValue !=0)
               {
    			members += new Member() =>
    			[
    				comment = "*pSd_GSaaServerTimerStatic"
    				value = '&Sd_GSaaServerTimerStatic['+ServerTimer_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdServerTimerIndexValue"
    				value = ServerTimer_count.toString
    			]
    		   }
    		   if(New_CE_count.intValue !=0)
               {
             	members += new Member() =>
    			[
    				comment = "*pSd_GaaClientServiceStatic"
    				value = '&Sd_GaaClientServiceStatic['+CE_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaClientHandleMapArray"
    				value = '&Sd_GaaClientHandleMapArray['+CE_count+']'
    			]
    		   }
    		   
    		   if(New_SerHdlr_count.intValue !=0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pSd_GaaEvHandlerStatic"
    				value = '&Sd_GaaEvHandlerStatic['+SerHdlr_count+']'
    			]
    			
    		   }
    		   if(module?.sdGeneral?.sdEnableAclPolicyCheck == true)
      		   {
    		   if(New_Allcons_count.intValue !=0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pSdAllowedConsumerStatic"
    				value = '&Sd_GaaServerServiceAllowedConsumerStatic['+Allcons_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdAllowedConsumerStaticCount"
    				value = Allowconsumer_count.toString
    			]
    		   }
    		   
    		   if(New_Allprov_count.intValue !=0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pSdAllowedProviderStatic"
    				value = '&Sd_GaaClientServiceAllowedProviderStatic['+Allprov_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*ucSdAllowedProviderStaticCount"
    				value = AllowProvid_count.toString
    			]
    		   }
    		  }
    		   
    		   if(New_CliSdGrpCnt.intValue != 0)
               {	
    			
    			members += new Member() =>
    			[
    				comment = "*pServgrpCliArray"
    				value = '&Sd_GaaServicegroupClientArray['+ServiceGrp_count+']['+CliSdGrpCnt+']'
    			]
    		   }
    		   if(New_SerSdGrpCnt.intValue != 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pServgrpSerArray"
    				value = '&Sd_GaaServicegroupServerArray['+ServiceGrp_count+']['+SerSdGrpCnt+']'
    			]
    			
    		   }
    		   if(New_ServiceGrp_count.intValue != 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pServgrpStatic"
    				value = '&Sd_GaaServicegroupStatic['+ServiceGrp_count+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pServgrpCliStatic"
    				value = '&Sd_GaaServicegroupClientStatic['+CliSdGrpCnt+']'
    			]
    			members += new Member() =>
    			[
    				comment = "*pServgrpSerStatic"
    				value = '&Sd_GaaServicegroupServerStatic['+SerSdGrpCnt+']'
    			]
    		   }
    		   if(New_Inastance_count_pb.intValue != 0)
               {	
    			members += new Member() =>
    			[
    				comment = "*pRxPduMapArray"
    				value = '&Sd_GaaRxPduMapArray['+Inastance_count_pb+']'
    			]
    		   }	
    	]
    	return cstruct.head

}

   /*
   * Collecting ClientServiceHandleId
   * @param None
   * @return array
   */
  def get_cli_handlemaparray()
  {
    var array = new ArrayList<Integer>()
    if(!Pbvc_list.nullOrEmpty)
    {
      for (iter :Pbvc_list)
      {
   	     var arr_ids1 = new ArrayList<Integer>()
   	     arr_ids1 = client_handle_ids_map.get(iter?.shortName)
   	     
   	     for(ids: arr_ids1.sort)
         {
              
              if(client_handle_ids.contains(ids))
              {
                 array.add(client_handle_ids.indexOf(ids))
                 
              }
          }
   	  }
   }
   else
   {
   	var arr_ids = new ArrayList<Integer>()
    arr_ids = client_handle_ids
    for(ids: arr_ids.sort)
    {
    if(client_handle_ids.contains(ids))
    {
      array.add(client_handle_ids.indexOf(ids))
    }
    }
   }
    
    return array
  }
  
  /*
   * Collecting ClientServiceHandleId
   * @param None
   * @return array
   */
  def get_cli_handlemaparray_Vp()
  {
    var arr_ids = new ArrayList<Integer>()
    arr_ids = client_handle_ids
    return arr_ids
    
  }

   /*
   * Collecting ConsumedEventGroupHandleId
   * @param None
   * @return array
   */
  def get_conEvGrpHandleMapArray()
  {
    var array = new ArrayList<Integer>()
    if(!Pbvc_list.nullOrEmpty)
    {
      for (iter :Pbvc_list)
      {
   	     var arr_ids1 = new ArrayList<Integer>()
   	     arr_ids1 = con_eve_grp_handle_ids_map.get(iter?.shortName)
   	     
   	     for(ids: arr_ids1.sort)
         {
             if(con_eve_grp_handle_ids.contains(ids))
              {
                 array.add(con_eve_grp_handle_ids.indexOf(ids))
                 
              }
          }
   	  }
   }
   else
   {
   	var arr_ids = new ArrayList<Integer>()

    arr_ids = con_eve_grp_handle_ids

    for(ids: arr_ids.sort)
    {
     if(con_eve_grp_handle_ids.contains(ids))
     {
      array.add(con_eve_grp_handle_ids.indexOf(ids))
     }
    }
   }
    
    return array
  }
  
  def get_conEvGrpHandleMapArray_Vp()
  {
    var arr_ids = new ArrayList<Integer>()

    arr_ids = con_eve_grp_handle_ids
    
   return arr_ids
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
    var array = new ArrayList<Integer>()
if(!Pbvc_list.nullOrEmpty)
 {
  for (iter :Pbvc_list)
  {
    
    var arr_ids1 = new ArrayList<Integer>()
    arr_ids1 = inst_uni_multicast_rx_pdu_map.get(iter?.shortName)
    arr_ids1.sort
  for(ind = 0; ind < arr_ids1.size; ind++)
  {
    for(inst : sdInstances)
    {
      if(arr_ids1?.sort.get(ind) == inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.filterVariant(iter,inst.toString)?.get(0)?.integerValue)
      {
         array.add(no_of_Instances.indexOf(inst?.shortNamePath?.toString))
      }
      if(arr_ids1?.sort.get(ind) == inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.filterVariant(iter,inst.toString)?.get(0)?.integerValue)
      {
         array.add(no_of_Instances.indexOf(inst?.shortNamePath?.toString))
      }
    }
  }
  
 }
}
else
{
	inst_uni_multicast_rx_pdu.sort
  for(ind = 0; ind < inst_uni_multicast_rx_pdu.size; ind++)
  {
    for(inst : sdInstances)
    {
      if(inst_uni_multicast_rx_pdu?.sort.get(ind) == inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
      {
         array.add(no_of_Instances.indexOf(inst?.shortNamePath?.toString))
      }
      if(inst_uni_multicast_rx_pdu?.sort.get(ind) == inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
      {
         array.add(no_of_Instances.indexOf(inst?.shortNamePath?.toString))
      }
    }
  }
  
}
    return array
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
    for(iter1:_soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
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
  
  
/* Sd_GSaaServerTimerStatic: when no variants are configured and module is PB */  
def Sd_GSaaServerTimerStaticNoVP(){
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
    if((Pbvc_list.nullOrEmpty)&&(isPostBuild(module)))
    {
     server_timer_staticNoVp()
    }
    if (!cstruct.nullOrEmpty) 
    {
     '''
     «str»
     «cstruct.join("," + System.lineSeparator)»
     «stp»
     '''
    }
}

/* Sd_GSaaServerTimerStatic: when variants are configured and module is PB */ 
def Sd_GSaaServerTimerStatic(){
  cstruct.clear
       val str = '''
    #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h"
    static const Sd_ServerTimerStaticType Sd_GSaaServerTimerStatic[«(sdInstances.map[get_server_timer_arr1]
    	.flatten.size * Pbvc_list.size)»] =
    {'''
       val stp =
    '''};
    #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Sd_MemMap.h" '''
    Pbvc_list?.map[server_timer_static(it)].join(',\n\n')
    if (!cstruct.nullOrEmpty) 
    {
     '''
     «str»
     «cstruct.join("," + System.lineSeparator)»
     «stp»
     '''
    }
}

  def server_timer_staticNoVp()
  {
    for (sd_inst : sdInstances)
    {
      var Timer = get_server_timer_arr1
      
      for (Server_Timer : Timer)
      {
      	cstruct += new CStruct()=>
      	[
      		comment = '''Sd_GSaaServerTimerStatic_«ServertimerIdx++» - «sd_inst?.shortName»_«Server_Timer.shortName»'''
      	    members += new Member()=>
      	    [
      	    	comment = '''ulServerTimerTtlsec'''
      	    	value = '''«Server_Timer.sdServerTimerTTL_PB.head?.integerValue?.toHex+'U'»'''
      	    	
      	    ]
      	    members += new Member()=>
      	    [
      	    	comment = '''ulInitialOfferDelayMax'''
      	    	if (!(Server_Timer.sdServerTimerInitialOfferDelayMax_PB.nullOrEmpty))
      	    	{
      	    	   if(Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.head.floatValue !== null)
	      	    	   	{
	      	    	   		value = ''' «(Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
	      	    	   	}
	      	    	   	else
		      	    	{
		      	    		value = "SD_TIMER_UNUSED"
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
      	    	 	value = '''«(Server_Timer.sdServerTimerInitialOfferDelayMin_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
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
      	    	   value = '''«(Server_Timer.sdServerTimerInitialOfferRepetitionBaseDelay_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	   
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
      	    	 	value = '''«(Server_Timer.sdServerTimerOfferCyclicDelay_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
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
      	    	 	 value = '''«(Server_Timer.sdServerTimerRequestResponseMaxDelay_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
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
      	    	 	value = ''' «(Server_Timer.sdServerTimerRequestResponseMinDelay_PB?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
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
      	    	 	 if(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.head?.integerValue !== null)
      	    	 	 	{
      	    	 	 		value = ''' «(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.head?.integerValue).toHex»'''
      	    	 	 	}
      	    	 	 	else
		      	    	{
		      	    	 	value = "SD_TIMER_UNUSED"
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
 def server_timer_static(PredefinedVariant iter1)
  {
    for (sd_inst : sdInstances)
    {
      //var Timer = get_server_timer_arr1 
      var Timer_pb = get_server_Timer_ids_map()
      var Timer = Timer_pb?.get(iter1?.shortName) 
      for (Server_Timer : Timer)
      {
      	cstruct += new CStruct()=>
      	[
      		comment = '''Sd_GSaaServerTimerStatic_«ServertimerIdx++» - «sd_inst?.shortName»_«Server_Timer.shortName» - «iter1?.shortName»'''
      	    members += new Member()=>
      	    [
      	    	comment = '''ulServerTimerTtlsec'''
      	    	value = '''«Server_Timer.sdServerTimerTTL_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue?.toHex+'U'»'''
      	    ]
      	    members += new Member()=>
      	    [
      	    	comment = '''ulInitialOfferDelayMax'''
      	    	if (!(Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.filterVariant(iter1,sd_inst.toString).toList.nullOrEmpty))
      	    	{
      	    	   if(Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue !==null)
	      	    	   	{
	      	    	   		value = ''' «(Server_Timer.sdServerTimerInitialOfferDelayMax_PB?.filterVariant(iter1,sd_inst.toString).head?.floatValue/Sd_main_func_period).intValue.toHex»'''
	      	    	   	}
	      	    	   	else
		      	    	{
		      	    		value = "SD_TIMER_UNUSED"
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
      	    	 if (!(Server_Timer.sdServerTimerInitialOfferDelayMin_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	    	 {
      	    	 	value = '''«(Server_Timer.sdServerTimerInitialOfferDelayMin_PB?.filterVariant(iter1,sd_inst.toString)?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
      	    	 }
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	comment = '''ulInitialOfferRepetitionBaseDelay'''
      	    	if (!(Server_Timer.sdServerTimerInitialOfferRepetitionBaseDelay_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	        {
      	    	   value = '''«(Server_Timer.sdServerTimerInitialOfferRepetitionBaseDelay_PB?.filterVariant(iter1,sd_inst.toString)?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	   
      	        }
      	        else 
      	        {
      	        	value = "SD_TIMER_UNUSED"
      	        }    
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulTimerOfferCyclicDelay'''
      	    	 if (!(Server_Timer.sdServerTimerOfferCyclicDelay_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	    	 {
      	    	 	value = '''«(Server_Timer.sdServerTimerOfferCyclicDelay_PB?.filterVariant(iter1,sd_inst.toString)?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
      	    	 }
      	    	 
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulRequestResponseMaxDelay'''
      	    	 if (!(Server_Timer.sdServerTimerRequestResponseMaxDelay_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	    	 {
      	    	 	 value = '''«(Server_Timer.sdServerTimerRequestResponseMaxDelay_PB?.filterVariant(iter1,sd_inst.toString)?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	 
      	    	 }
      	    	 
      	    	 else
      	    	 {
      	    	 	value = "SD_TIMER_UNUSED"
      	    	 }   
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = '''ulRequestResponseMinDelay'''
      	    	 if (!(Server_Timer.sdServerTimerRequestResponseMinDelay_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	    	 {
      	    	 	value = ''' «(Server_Timer.sdServerTimerRequestResponseMinDelay_PB?.filterVariant(iter1,sd_inst.toString)?.head?.floatValue/Sd_main_func_period).intValue.toHex»'''
      	    	 	
      	    	 }
      	    	 else
      	    	 {
      	    	 	 value = "SD_TIMER_UNUSED"
      	    	 }
      	    ]
      	    
      	    members += new Member ()=>
      	    [
      	    	 comment = ''' ucInitialOfferRepetitionsMax '''
      	    	 if (!(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
      	    	 {
      	    	 	 if(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue !== null)
      	    	 	 	{
      	    	 	 		value = ''' «(Server_Timer.sdServerTimerInitialOfferRepetitionsMax_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue).toHex»'''
      	    	 	 	}
      	    	 	 	else
		      	    	{
		      	    	 	value = "SD_TIMER_UNUSED"
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
      return cstruct.head
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
   /* Sd_GaaInstanceStatic: when module is PB */
  def Sd_GaaInstanceStatic() {
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_InstanceStaticType Sd_GaaInstanceStatic[«Sd_Cfg_PBcfg_H.Sd_GInstances_arr.size»] =
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
  	var Instance = module?.sdConfig.sdInstances
  	var Instance_count = 0
  	if(!module?.getPredefinedVariants.nullOrEmpty)
      {
        Pbvc_list = module?.getPredefinedVariants.sortBy[shortName]
      }
      
      if(!Pbvc_list.nullOrEmpty)
       {
         for(iter1:Pbvc_list)
         {
           for(iter_Instance : Instance)
           {
            if(iter_Instance?.sdInstanceLocalAdressCheckLength_PB?.filterVariant(iter1,iter_Instance.toString).head !== null)
            {
              Instance_count++
            }
           }
         }
       }

  if(!Pbvc_list.nullOrEmpty)
  {
   for (iter :Pbvc_list)
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
     	    	if (soad_tx_pduref_hash.size > 0 && sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB?.filterVariant(iter,sd_inst.toString).size > 0)
     	    	{
     	    	   for(txpdu: sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB.filterVariant(iter,sd_inst.toString))
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
     	    	if (!(sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.filterVariant(iter,sd_inst.toString).nullOrEmpty))
     	    	{
     	    		for (l1 : sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.filterVariant(iter,sd_inst.toString))
     	    		{
     	    			value = '''«l1?.integerValue.toHex»'''
     	    		}
     	    	}
                 else 
                  {
				   /*None*/
				  }				 
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddMulticastRxPduId'''
     	    	if (!(sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.filterVariant(iter,sd_inst.toString).nullOrEmpty))
     	    	{
     	    		for(l1 : sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.filterVariant(iter,sd_inst.toString))
     	    		{
     	    			value = '''«l1?.integerValue.toHex»'''
     	    		}
     	    	} 
     	    	else{}	
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddIpAddrSoConId'''
     	    	value = '''«get_IpAddrSoConId_vp(sd_inst, iter)»'''
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
     	    		value = '''«get_uni_cast_socid_vp(sd_inst?.sdInstanceUnicastRxPdu, iter)»'''
     	    		value = '''«ddRxUnicastSoConId.toHex»'''
     	    	}
     	    	else
     	    	{
     	    		
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''ddRxMulticastSoConId'''
     	    	if (sd_inst?.sdInstanceMulticastRxPdu !== null)
     	    	{
     	    		value = '''«get_multi_cast_socid_vp(sd_inst?.sdInstanceMulticastRxPdu, iter)»'''
     	    		value = '''«ddRxMulticastSoConId.toHex»'''
     	    	}
     	    	else
     	    	{}
     	    	
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usDemErrorMalformedId'''
     	    	if (_dem?.demConfigSet?.demEventParameters !== null)
     	    	{
     	    		value = '''«get_sd_dem(sd_inst, iter)»'''
     	    	}
     	    	else
     	    	{}
     	    	
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
     	    	
     	    	var domain_type_hash = domain_type_hash_vp.get(iter?.shortName)
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
     	    	if(sd_inst?.sdInstanceLocalAdressCheckLength_PB?.filterVariant(iter,sd_inst.toString)?.head != null)
     	    	{
     	    		value = '''«sd_inst?.sdInstanceLocalAdressCheckLength_PB?.filterVariant(iter,sd_inst.toString)?.head?.integerValue?.toHex»'''   
     	    	}
     	        else
     	        {
     	       	 value = '''SD_INVALID'''   
     	       	}
     	    ]   
     	  ]
     }
     
     }
     
     }
     
     else
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
     	    	else
     	    	{
     	    		
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
     	    	else
     	    	{
     	    		
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
     	    	else
     	    	{
     	    		
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
     	    	else
     	    	{
     	    		
     	    	}
     	    ]
     	    
     	    members += new Member =>
     	    [
     	    	comment = '''usDemErrorMalformedId'''
     	    	if (_dem?.demConfigSet?.demEventParameters !== null)
     	    	{
     	    		value = '''«get_sd_demNoVp(sd_inst)»'''
     	    	}
     	        else
     	        {
     	        	
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
     	    	if(sd_inst?.sdInstanceLocalAdressCheckLength_PB?.head != null)
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
     	
     }
     return cstruct
   }


   /*
   *
   * @param sd_inst SdInstance type
   * @return None
   */
  def get_sd_dem(SdInstance sd_inst, PredefinedVariant iter)
  {
    DemErrorMalformedId = 0XFFFF
    DemErrorOutOfResId = 0XFFFF
    DemErrorSubEventgroupNacId = 0XFFFF
    for(dem_eve_prm : _dem?.demConfigSet?.demEventParameters)
    {
      dem_eve_parm_hash.put(dem_eve_prm?.shortNamePath?.toString, dem_eve_prm?.demEventId)
    }

    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_MALFORMED_MSG_PB?.filterVariant(iter,sd_inst.toString).nullOrEmpty))
    {
      for(malform_msg : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_MALFORMED_MSG_PB?.filterVariant(iter,sd_inst.toString))
      {
        if(dem_eve_parm_hash.containsKey(malform_msg?.reference?.shortNamePath?.toString))
        {
          DemErrorMalformedId = dem_eve_parm_hash?.get(malform_msg?.reference?.shortNamePath?.toString)
        }
      }
    }
    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_OUT_OF_RES_PB?.filterVariant(iter,sd_inst.toString).nullOrEmpty))
    {
      for(out_of_res : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_OUT_OF_RES_PB?.filterVariant(iter,sd_inst.toString))
      {
        if(dem_eve_parm_hash.containsKey(out_of_res?.reference?.shortNamePath?.toString))
        {
          DemErrorOutOfResId = dem_eve_parm_hash?.get(out_of_res?.reference?.shortNamePath?.toString)
        }
      }
    }

    if(!(sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_SUBSCR_NACK_RECV_PB?.filterVariant(iter,sd_inst.toString).nullOrEmpty))
    {
      for(out_of_res : sd_inst?.sdInstanceDemEventParameterRefs?.SD_E_SUBSCR_NACK_RECV_PB?.filterVariant(iter,sd_inst.toString))
      {
        if(dem_eve_parm_hash.containsKey(out_of_res?.reference?.shortNamePath?.toString))
        {
          DemErrorSubEventgroupNacId = dem_eve_parm_hash?.get(out_of_res?.reference?.shortNamePath?.toString)
        }
      }
    }
  }

def get_sd_demNoVp(SdInstance sd_inst)
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
def get_IpAddrSoConId_vp(SdInstance sd_inst, PredefinedVariant iter1)
    {
      for(sdTxPduRef : sd_inst?.sdInstanceTxPdu?.sdTxPduRef_PB?.filterVariant(iter1,SdInstance.toString))
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
def get_uni_cast_socid_vp(Sd.SdConfig.SdInstance.SdInstanceUnicastRxPdu sdInstanceUnicastRxPdu, PredefinedVariant iter1)
  {
    for(sd_rxpdu : sdInstanceUnicastRxPdu?.sdRxPduRef_PB?.filterVariant(iter1,Sd.SdConfig.SdInstance.toString))
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
def get_multi_cast_socid_vp(Sd.SdConfig.SdInstance.SdInstanceMulticastRxPdu sdInstanceMulticastRxPdu, PredefinedVariant iter1)
  {
    for(sd_rxpdu : sdInstanceMulticastRxPdu?.sdRxPduRef_PB?.filterVariant(iter1,Sd.SdConfig.SdInstance.toString))
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
   
  
  /* Sd_GaaServerServiceStatic: when no variants are configured and module is PB */
 
 def Sd_GaaServerServiceStaticNoVp() {
  
  cstruct.clear
 
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ServerServiceStaticType Sd_GaaServerServiceStatic[«Sd_Cfg_PBcfg_H.server_services_cnt.size»] =
  {'''
       val stp =
    '''};
    
   #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #include "Sd_MemMap.h" ''' 

 serverServiceStaticNoVp()
 
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
  
 }
   /* Sd_GaaServerServiceStatic: when variants are configured and module is PB */
 def Sd_GaaServerServiceStatic() {
  
  cstruct.clear
 
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ServerServiceStaticType Sd_GaaServerServiceStatic[«Sd_Cfg_PBcfg_H.server_services_cnt.size»] =
  {'''
       val stp =
    '''};
    
   #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
   #include "Sd_MemMap.h" ''' 

 Pbvc_list.map[serverServiceStatic(it)].join(',\n')
 
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
  
 }   
  /* Sd_GaaServerServiceStatic: when no variants are configured and module is PB */   
  def serverServiceStaticNoVp()
  {
    for (sd_inst : sdInstances){
    
    for (server_service : sd_inst?.sdServerServices) {
      cstruct += new CStruct()=>
      [
      	comment = '''Sd_GaaServerServiceStatic : «Sd_Gserverstructinst++» - «sd_inst?.shortName+'_'+server_service?.
      	shortName»'''
        
        members += new Member =>
        [
        	comment = '''ulMinorVersion'''
        	value = '''«server_service?.sdServerServiceMinorVersion_PB?.head?.integerValue.toHex+'U'»'''
        	     	
         ]
       
        members += new Member =>
        [
         	comment = '''pTcpSoConGrp'''
         	if(server_service?.sdServerServiceTcpRef_PB?.size > 0)
         	{
         	   if (sort_used_soc_con_grp_arr.contains(server_service?.sdServerServiceTcpRef_PB?.head?.reference?.shortNamePath?.toString))
         	   	  {
         	   	  	 value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.indexOf(server_service?.sdServerServiceTcpRef_PB?.head?.
         	   	  	 	reference?.shortNamePath?.toString
         	   	  	 )+']'»'''
         	   	  }
         	   	  else
         	   	  {
         	   	  	 value = "NULL_PTR" 
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
        		if(sort_used_soc_con_grp_arr.contains(server_service?.sdServerServiceUdpRef_PB?.head?.reference?.shortNamePath?.toString))
        		   {
        		   	  value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
                      indexOf(server_service?.sdServerServiceUdpRef_PB?.head?.reference?.shortNamePath?.toString)+']'»'''
        		   }
        		   else
        		   {
        		   	  value = "NULL_PTR"
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
        	var server_timer_arr = get_server_timer_arr()
        	value = '''&Sd_GSaaServerTimerStatic[«server_timer_arr.indexOf(server_service?.sdServerServiceTimerRef_PB?.head?.reference?.shortNamePath?.
    				toString
    			)»]'''
        	
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
       	   value = '''«server_service?.sdServerServiceId_PB?.head?.integerValue?.toHex+'U'»'''      	   
       	   
        ]
       
        members += new Member =>
        [
       	    comment = '''usInstanceId'''
       	    value = '''«server_service?.sdServerServiceInstanceId_PB?.head?.integerValue?.toHex»'''
       	          	    
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
       	    	value = '''SoAdConf_SoAdRoutingGroup_«act_server_grp_id»'''
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
        	value = '''«server_service?.sdServerServiceMajorVersion_PB?.head?.integerValue.toHex»'''
        	
        ]
       
        members += new Member =>
    	[
    	    comment = '''stServerStaticFlag'''
    	    value = '''«stServerStaticFlagNoVp(server_service).head»'''
    	] 
    	 
    	members += new Member =>
        [
        	comment = '''pServiceGroupRef'''
        	  
         if(server_service?.sdServiceGroupRefs_PB?.size>0){
        	if(sort_used_ser_grp_arr.contains(server_service?.sdServiceGroupRefs_PB?.head?.reference?.shortNamePath?.toString))
        	 {
        		    value = '''&Sd_GaaServicegroupStatic[«sort_used_ser_grp_arr.indexOf(server_service?.sdServiceGroupRefs_PB?.head?.reference?.shortNamePath?.toString)»]'''
        	 }
             else
        	 {
        			value = "NULL_PTR"
        	 }
        	
          }
         else
         {
        		value = "NULL_PTR"
         }
        	
        ]
        if(server_service?.sdServerServiceLoadBalancingWeight_PB.size > 0)
        {      
         	members += new Member =>
            [
        	comment = ''' usServerServiceLoadBalancingWeight'''
        	for (maj_ver : server_service?.sdServerServiceLoadBalancingWeight_PB)
        	{
        		value = '''«maj_ver?.integerValue.toHex»'''
        	}
            ]
        }
        if(server_service?.sdServerServiceLoadBalancingPriority_PB.size > 0)
        {          
        	members += new Member =>
            [
        	comment = ''' usServerServiceLoadBalancingPriority'''
        	for (maj_ver : server_service?.sdServerServiceLoadBalancingPriority_PB)
        	{
        		value = '''«maj_ver?.integerValue.toHex»'''
        	}
            ]
         }
      ]
     }    
    }
    return cstruct
  }
/* Sd_GaaServerServiceStatic: when variants are configured and module is PB */ 
   def serverServiceStatic(PredefinedVariant iter1)
  {
    //servertimerRefpb(iter1)
    for (sd_inst : sdInstances){
    for (server_service : sd_inst?.sdServerServices?.sortBy[sdServerServiceHandleId]) {
      cstruct += new CStruct()=>
      [
      	comment = '''Sd_GaaServerServiceStatic : «Sd_Gserverstructinst++» - «sd_inst?.shortName+'_'+server_service?.
      	shortName»  -  «iter1.shortName»'''
      	
        members += new Member =>
        [
        	comment = '''ulMinorVersion'''
        	value = '''«server_service?.sdServerServiceMinorVersion_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue.toHex+'U'»'''
        	     	
         ]
      
        members += new Member =>
        [
         	comment = '''pTcpSoConGrp'''
         	if(server_service?.sdServerServiceTcpRef_PB?.filterVariant(iter1,sd_inst.toString).size > 0)
         	{
         	   if (sort_used_soc_con_grp_arr.contains(server_service?.sdServerServiceTcpRef_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.toString))
         	   	  {
         	   	  	 value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.indexOf(server_service?.sdServerServiceTcpRef_PB?.filterVariant(iter1,sd_inst.toString)?.head?.
         	   	  	 	reference?.shortNamePath?.toString
         	   	  	 )+']'»'''
         	   	  }
         	   	  else
         	   	  {
         	   	  	 value = "NULL_PTR" 
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
        	if (server_service?.sdServerServiceUdpRef_PB?.filterVariant(iter1,sd_inst.toString).size > 0)
            {
        		if(sort_used_soc_con_grp_arr.contains(server_service?.sdServerServiceUdpRef_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.toString))
        		   {
        		   	  value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
                      indexOf(server_service?.sdServerServiceUdpRef_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.toString)+']'»'''
        		   }
        		   else
        		   {
        		   	  value = "NULL_PTR"
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
        	//var server_timer_arr = get_server_timer_arr()
        	var Timer_pb = get_server_Timer_ids_map1()
            var server_timer_arr = Timer_pb?.get(iter1?.shortName) 
    			value = '''&Sd_GSaaServerTimerStatic[«((Sd_server_timer_variant.get(iter1.toString).intValue) + (server_timer_arr.indexOf(server_service?.sdServerServiceTimerRef_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.
    				toString
    			)))»]'''
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
        	comment = '''usHandleId'''
        	value = '''«server_service?.sdServerServiceHandleId?.toHex»'''
        ]
        
       members += new Member =>
       [
       	   comment = '''usServiceId'''
       	   value = '''«server_service?.sdServerServiceId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue?.toHex+'U'»'''      	   
       	   
       ]
       
       members += new Member =>
       [
       	    comment = '''usInstanceId'''
       	    value = '''«server_service?.sdServerServiceInstanceId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue?.toHex»'''
       	          	    
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
       	    val act_server_grp_id = get_act_server_grp_id_vp(server_service?.shortNamePath?.toString, iter1)
       	    if (!(act_server_grp_id.nullOrEmpty))
       	    {
       	    	value = '''SoAdConf_SoAdRoutingGroup_«act_server_grp_id»'''
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
        	value = '''«server_service?.sdServerServiceMajorVersion_PB?.filterVariant(iter1,sd_inst.toString).head?.integerValue.toHex»'''
        	
        ]
       
         members += new Member =>
    	 [
    	    comment = '''stServerStaticFlag'''
    	    value = '''«stServerStaticFlag(server_service, iter1).head»'''
    	 ] 
    	 
    	 members += new Member =>
         [
        	comment = '''pServiceGroupRef'''
        	  
           if(server_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,sd_inst.toString).toList.size>0)
           {
        	    
               if(sort_used_ser_grp_arr.contains(server_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.toString))
        	    {
        		    value = '''&Sd_GaaServicegroupStatic[«sort_used_ser_grp_arr.indexOf(server_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,sd_inst.toString)?.head?.reference?.shortNamePath?.toString)»]'''
        		}
               else
        	    {
        			value = "NULL_PTR"
        		}
        	 
           }
           else
           {
        		value = "NULL_PTR"
           }
        	
        ]
        if(server_service?.sdServerServiceLoadBalancingWeight_PB?.filterVariant(iter1,sd_inst.toString)?.size > 0)
        {      
         	members += new Member =>
            [
        	comment = ''' usServerServiceLoadBalancingWeight'''
        	value = '''«server_service?.sdServerServiceLoadBalancingWeight_PB?.filterVariant(iter1,sd_inst.toString).head?.integerValue.toHex»'''
        	]
        }
        if(server_service?.sdServerServiceLoadBalancingPriority_PB?.filterVariant(iter1,sd_inst.toString)?.size > 0)
        {          
        	members += new Member =>
            [
        	comment = ''' usServerServiceLoadBalancingPriority'''
        	value = '''«server_service?.sdServerServiceLoadBalancingPriority_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue.toHex»'''
        	]
         }
       ]
      }    
     }
     //ServerTimer_countpb = ServerTimer_pb + 6
     return cstruct
   }
    /* stServerStaticFlag: when no variants are configured and module is PB */
    def stServerStaticFlagNoVp(SdServerService service) {
    var cstruct = new ArrayList<CStruct>	
    cstruct += new CStruct()=>
    [
    	members += new Member =>
      [
        comment = '''blAutoAvaliable'''
        if (service?.sdServerServiceAutoAvailable_PB?.head?.booleanValue == true)
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
     /* stServerStaticFlag: when variants are configured and module is PB */     
 def stServerStaticFlag(SdServerService service, PredefinedVariant iter1) {
 	
    var cstruct = new ArrayList<CStruct>	
    cstruct += new CStruct()=>
    [
    	members += new Member =>
      [
        comment = '''blAutoAvaliable'''
        if (service?.sdServerServiceAutoAvailable_PB?.filterVariant(iter1,service.toString).head?.booleanValue == true)
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
    	 	comment = '''blActivationRoGrpIdPresent'''  	 
    	 	val act_server_grp_id = get_act_server_grp_id_vp(service?.shortNamePath?.toString, iter1)	
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  
  
  	def get_act_client_grp_id_vp(String clientservice, PredefinedVariant iter1)
    {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var cli_routgrp = act_client_routing_grp_map.get(iter1?.shortName)
      if(cli_routgrp.get(clientservice) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  
  def get_act_consumed_eve_grp_id_vp(String con_eve_path, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var con_routgrp = act_consumed_eve_routing_grp_map.get(iter1?.shortName)
      if(con_routgrp?.get(con_eve_path) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  def get_act_server_grp_id_vp(String serverservice, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var ser_routgrp = act_server_routing_grp_map.get(iter1?.shortName)
      if(ser_routgrp?.get(serverservice) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  
  def get_act_eve_handler_grp_id_vp(String eve_handler, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var eve_handroutgrp = act_eve_hand_routing_grp_map.get(iter1?.shortName)
      if(eve_handroutgrp?.get(eve_handler) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  def get_act_eve_handler_udp_grp_id_vp(String udp_ref, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var eve_handroutgrp = act_eve_hand_udp_routing_grp_map.get(iter1?.shortName)
      
      if(eve_handroutgrp?.get(udp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  def get_act_eve_handler_tcp_grp_id_vp(String tcp_ref, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var eve_handroutgrp = act_eve_hand_tcp_routing_grp_map.get(iter1?.shortName)
      
      if(eve_handroutgrp?.get(tcp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
          return (soad_rout_grps?.shortName?.toString)
        }
      }
  }
  
  def get_con_eve_tcp_act_id_vp(String con_eve_ref, PredefinedVariant iter1)
  {
      for(soad_rout_grps : _soad?.soAdConfig?.soAdRoutingGroups)
      {
        var con_eve_tcp = sd_con_eve_tcp_ref_arr_map.get(iter1?.shortName)
        if(con_eve_tcp?.get(con_eve_ref) == soad_rout_grps?.shortNamePath?.toString)
        {
          return (soad_rout_grps?.shortName?.toString)
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
          return (soad_rout_grps?.shortName?.toString)
        }
      }
  }
  def get_con_eve_udp_act_id_vp(String con_eve_ref, PredefinedVariant iter1)
  {
      for(soad_rout_grps : _soad?.soAdConfig?.soAdRoutingGroups)
      {
        var con_eve_udp = sd_con_eve_udp_ref_arr_map.get(iter1?.shortName)
        if(con_eve_udp?.get(con_eve_ref) == soad_rout_grps?.shortNamePath?.toString)
        {
          return (soad_rout_grps?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
   def get_eve_hand_udp_act_id_vp(String udp_ref, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var eve_udp = sd_eve_handler_udp_ref_arr_map.get(iter1?.shortName)
      if(eve_udp?.get(udp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
        return (soad_rout_grp?.shortName?.toString)
      }
    }
  }
  
  def get_eve_hand_tcp_act_id_vp(String tcp_ref, PredefinedVariant iter1)
  {
    for(soad_rout_grp : _soad?.soAdConfig?.soAdRoutingGroups)
    {
      var eve_tcp = sd_eve_handler_tcp_ref_arr_map.get(iter1?.shortName)
      if(eve_tcp?.get(tcp_ref) == soad_rout_grp?.shortNamePath?.toString)
      {
        return (soad_rout_grp?.shortName?.toString)
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
  
  def get_multi_eve_soc_con_id_vp(String eve_handler, PredefinedVariant iter1)
  {
    var eve_han = sd_eve_hand_multi_soc_con_map.get(iter1?.shortName)
    return ((soad_connections?.get(eve_han?.get(eve_handler)))?.toHex)?.toString
  }
  
  
 /* Sd_GaaClientServiceStatic: when no variants are configured and module is PB */ 
 def Sd_GaaClientServiceStaticNoVp(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ClientServiceStaticType Sd_GaaClientServiceStatic[SD_NO_OF_CLIENT_SERVICES_PB] =
  {'''
       val stp =
   '''};
    
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" ''' 
 clientServiceStaticNoVp()
 
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
 }
  /* Sd_GaaClientServiceStatic: when variants are configured and module is PB */ 
 def Sd_GaaClientServiceStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ClientServiceStaticType Sd_GaaClientServiceStatic[SD_NO_OF_CLIENT_SERVICES_PB] =
  {'''
       val stp =
   '''};
    
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" ''' 
 Pbvc_list.map[clientServiceStatic(it)].join(',\n\n')
 
 if (!cstruct.nullOrEmpty) 
 {
   '''
   «str»
     «cstruct.join("," + System.lineSeparator)»
   «stp»
    '''
  }
 }
  
 /* Sd_GaaClientServiceStatic: when variants are configured and module is PB */   
def clientServiceStatic(PredefinedVariant iter)
{
  	
  for(sd_inst : sdInstances)
     {
       for (client_service : sd_inst?.sdClientServices)
       {
       cstruct += new CStruct()=>
       [
     	comment = '''Sd_GaaClientServiceStatic : «Sd_Gclientstructinst++» - «sd_inst?.shortName+'_'+client_service?.
     	shortName»  -  «iter.shortName»'''
     	members += new Member()=>
     	[
     		comment = '''usHandleId '''
     		value = '''«client_service?.sdClientServiceHandleId?.toHex»'''
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usServiceId'''
     		value = '''«client_service?.sdClientServiceId_PB.filterVariant(iter,sd_inst.toString).head?.integerValue?.toHex+'U'»'''
     		 		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usInstanceId'''
     		value = '''«client_service?.sdClientServiceInstanceId_PB.filterVariant(iter,sd_inst.toString).head?.integerValue?.toHex+'U'»'''
     		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ucMajorVersion'''
     		value = '''«client_service?.sdClientServiceMajorVersion_PB.filterVariant(iter,sd_inst.toString).head?.integerValue.toHex»'''
     		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ulMinorVersion'''
     		value = '''«client_service?.sdClientServiceMinorVersion_PB.filterVariant(iter,sd_inst.toString).head?.integerValue.toHex+'U'»'''
     		
     	]
     
     	members += new Member()=>
     	[
     		comment = '''pTcpSoConGrp'''
     		if(client_service?.sdClientServiceTcpRef_PB?.size>0)
     		{
     			if(soad_soc_con_grps.contains(client_service?.sdClientServiceTcpRef_PB?.filterVariant(iter,sd_inst.toString).head?.reference?.shortNamePath?.toString))
     				{
     					value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.
                        indexOf(client_service?.sdClientServiceTcpRef_PB?.filterVariant(iter,sd_inst.toString).head?.reference?.shortNamePath?.toString)+']'»'''
     				}
     				else
     				{
     					value = "NULL_PTR"
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
     			if(soad_soc_con_grps.contains(client_service?.sdClientServiceUdpRef_PB?.filterVariant(iter,sd_inst.toString).head?.reference?.shortNamePath?.toString))
     				{
     					value = '''«'&Sd_GaaSoConGroupStatic['+sort_used_soc_con_grp_arr.indexOf(client_service?.sdClientServiceUdpRef_PB?.filterVariant(iter,sd_inst.toString).head?.reference?.shortNamePath?.toString)+']'»'''
     				}
     				else
     				{
     					value = "NULL_PTR "
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
     		var client_timer_arr_pb = get_client_Timer_ids_map()
     		var client_timer_arr = client_timer_arr_pb.get(iter?.shortName)
     		value = '''&Sd_GSaaClientTimerStatic[«((Sd_client_timer.get(iter.toString).intValue) +  (client_timer_arr.indexOf(client_service?.sdClientServiceTimerRef_PB.filterVariant(iter,sd_inst.toString).head?.reference?.shortNamePath?.
     				toString
     			)))»]'''
     		
     	]
     	
     	members += new Member ()=>
     	[
     		comment = '''pConfigOption'''
     		var conf_opt_client_rec_index = get_config_opt_client_cap_rec_index()
     		if (conf_opt_client_rec_index.size > 0 && conf_opt_client_rec_index.containsKey(client_service?.shortNamePath?.toString))
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
     		val act_client_grp_id = get_act_client_grp_id_vp(client_service?.shortNamePath?.toString, iter)
     		if (!(act_client_grp_id.nullOrEmpty))
     		{
     			value = '''SoAdConf_SoAdRoutingGroup_«act_client_grp_id»'''
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
     		value = '''«stClientStaticFlagVp(client_service, iter).head»'''
     	]
    
         members += new Member()=>
         [
            comment = "EndrivenBehaviour"
            if(client_service.sdVersionDrivenFindBehavior_PB.filterVariant(iter,sd_inst.toString).map[it.enumValue].filterNull.empty)
            {
                value = '''SD_EXACT_OR_ANY_MINOR_VERSION'''
            }
            else
            {
                value = '''SD_«client_service.sdVersionDrivenFindBehavior_PB.filterVariant(iter,sd_inst.toString).head.enumValue»'''
            }
          ]

        members += new Member =>
        [
        	comment = '''pServiceGroupRef'''
        	var service_grp_arr = get_service_grp_arr()
           if(client_service?.sdServiceGroupRefs_PB?.size>0)
           {
        	if(service_grp_arr.contains(client_service?.sdServiceGroupRefs_PB?.filterVariant(iter,sd_inst.toString).head?.reference.shortNamePath.toString))
        		{
        		value = '''&Sd_GaaServicegroupStatic[«service_grp_arr.indexOf(client_service?.sdServiceGroupRefs_PB?.filterVariant(iter,sd_inst.toString).head?.reference.shortNamePath.toString)»]'''
        		}
        		else
        		{
        			value = "NULL_PTR"
        		}
        	
           }
          else
          {
        		value = "NULL_PTR"
          }
        ]
        
        members += new Member =>
        [  
         if(client_service.sdBlocklistedVersions_PB.filterVariant(iter,sd_inst.toString).size.intValue != 0 )
         {
           comment = '''sdBlocklistedMinorVersions'''
        	if(client_service.sdBlocklistedVersions_PB?.filterVariant(iter,sd_inst.toString).head?.sdBlocklistedMinorVersionss_PB.filterVariant(iter,sd_inst.toString) != null )
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        	    value ='''«client_service.sdBlocklistedVersions_PB?.filterVariant(iter,sd_inst.toString).head?.sdBlocklistedMinorVersionss_PB.filterVariant(iter,sd_inst.toString).map[integerValue].join(",")»'''
        	
        	}
        	else
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        		value = '''0'''
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
/* Sd_GaaClientServiceStatic: when no variants are configured and module is PB */  
def clientServiceStaticNoVp()
{
  for(sd_inst : sdInstances)
  {
    for (client_service : sd_inst?.sdClientServices)
    {
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
     		value = '''«client_service?.sdClientServiceId_PB?.head?.integerValue?.toHex+'U'»'''
     		 		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''usInstanceId'''
     		value = '''«client_service?.sdClientServiceInstanceId_PB?.head?.integerValue?.toHex+'U'»'''
     		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ucMajorVersion'''
     		value = '''«client_service?.sdClientServiceMajorVersion_PB?.head?.integerValue.toHex»'''
     		
     	]
     	
     	members += new Member()=>
     	[
     		comment = '''ulMinorVersion'''
     		value = '''«client_service?.sdClientServiceMinorVersion_PB?.head?.integerValue.toHex+'U'»'''
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
     		var client_timer_arr = get_client_timer_arr()
     			value = '''&Sd_GSaaClientTimerStatic[«client_timer_arr.indexOf(client_service?.sdClientServiceTimerRef_PB?.head?.reference?.shortNamePath?.
     				toString
     			)»]'''
     	]
     	
     	members += new Member ()=>
     	[
     		comment = '''pConfigOption'''
     		var conf_opt_client_rec_index = get_config_opt_client_cap_rec_index()
     		if (conf_opt_client_rec_index.size > 0 && conf_opt_client_rec_index.containsKey(client_service?.shortNamePath?.toString))
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
     			value = '''SoAdConf_SoAdRoutingGroup_«act_client_grp_id»'''
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
        	comment = '''pServiceGroupRef'''
        	var service_grp_arr = get_service_grp_arr()
        	if(client_service?.sdServiceGroupRefs_PB?.size>0){
        	if(service_grp_arr.contains(client_service?.sdServiceGroupRefs_PB?.filterNull?.head?.reference.shortNamePath.toString))
        		{
        		value = '''&Sd_GaaServicegroupStatic[«service_grp_arr.indexOf(client_service?.sdServiceGroupRefs_PB?.filterNull?.head?.reference.shortNamePath.toString)»]'''
        		}
        		else
        		{
        			value = "NULL_PTR"
        		}
        	
        	
        	}
        	else
        	{
        		value = "NULL_PTR"
        	}
        ]

	    members += new Member =>
	    [  
        	if(client_service.sdBlocklistedVersions_PB.size.intValue != 0 )
        	{
        	 
        	comment = '''sdBlocklistedMinorVersions'''
        	if(client_service.sdBlocklistedVersions_PB?.head?.sdBlocklistedMinorVersionss_PB != null )
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        	    value ='''«client_service.sdBlocklistedVersions_PB?.head?.sdBlocklistedMinorVersionss_PB.map[integerValue].join(",")»'''
        	
        	}
        	else
        	{
        		comment = '''sdBlocklistedMinorVersions'''
        		value = '''0'''
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
    /* stClientStaticFlag: when no variants are configured and module is PB */
  def stClientStaticFlag(SdClientService service)
  {
       var cstruct = new ArrayList<CStruct>
       cstruct += new CStruct() =>
       [
       	   members += new Member()=>
       	   [
       	  	  comment = '''blAutoRequire'''
       	  	  if (service?.sdClientServiceAutoRequire_PB?.head?.booleanValue == true)
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
       /* stClientStaticFlagVp: when no variants are configured and module is PB */
   def stClientStaticFlagVp(SdClientService service, PredefinedVariant iter)
   {
       var cstruct = new ArrayList<CStruct>
       cstruct += new CStruct() =>
       [
       	   members += new Member()=>
       	   [
       	  	  comment = '''blAutoRequire'''
       	  	  if (service?.sdClientServiceAutoRequire_PB?.filterVariant(iter,service.toString).head?.booleanValue == true)
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
 /* Sd_GSaaClientTimerStatic: when variants are configured and module is PB */    
   /* Violates #ref Sd_Cfg_C_REF_1 Violates MISRA 2012 Required Rule 1.1 */
    /* PRQA S 0857 EOF */
def Sd_GSaaClientTimerStatic(){
cstruct.clear

val str = '''
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
 const Sd_ClientTimerStaticType Sd_GSaaClientTimerStatic[«(client_timer_cnt.intValue)»] =
{'''
      val stp =
'''};
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h" '''
Pbvc_list?.map[client_timer_static(it)].join(',\n\n')
if (!cstruct.nullOrEmpty) 
  {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
  }    
 
 /* Sd_GSaaClientTimerStatic: when no variants are configured and module is PB */ 
def Sd_GSaaClientTimerStaticNoVP(){
cstruct.clear

val str = '''
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
 const Sd_ClientTimerStaticType Sd_GSaaClientTimerStatic[SD_NO_OF_CLIENT_TIMERS] =
{'''
      val stp =
'''};
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h" '''
client_timer_staticNoVp()
if (!cstruct.nullOrEmpty) 
  {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
  }
    /* Sd_GSaaClientTimerStatic: when no variants are configured and module is PB */
  def client_timer_static(PredefinedVariant iter1)
  {
  	
  	var client_timer_arr = new ArrayList<String>()
  	var client_timer_arr_pb = new HashMap<String, ArrayList<String>>()
	client_timer_arr_pb = get_client_Timer_ids_map()
    client_timer_arr = client_timer_arr_pb?.get(iter1?.shortName) 
	for (itr : 0..< client_timer_arr.size){
	for (sd_inst : sdInstances){
    for (client_timers : sd_inst?.sdClientTimers){
     if (client_timer_arr.get(itr).equals((client_timers.shortNamePath).toString)){
     	
       cstruct += new CStruct()=>
       [
     		
     		comment = '''Sd_GSaaClientTimerStatic : «Sd_Gclienttimer_cnt++» - «sd_inst?.shortName»_«client_timers?.
     		shortName»_«iter1?.shortName»'''
            members += new Member()=>
            [
            	comment = '''ulClientTimerTtlsec'''
            	value = '''«(client_timers?.sdClientTimerTTL_PB?.filterVariant(iter1,sd_inst.toString).head.integerValue.toHex)+'U'»'''
            	
            ]
            
            members += new Member ()=>
            [
            	 comment = '''ulInitialFindDelayMax'''
            	 if (!(client_timers?.sdClientTimerInitialFindDelayMax_PB.nullOrEmpty))
            	 {
            		 value = '''«((client_timers?.sdClientTimerInitialFindDelayMax_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		            			
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
               	   	   value = '''«((client_timers?.sdClientTimerInitialFindDelayMin_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
               	   	   
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
                		value = '''«((client_timers?.sdClientTimerInitialFindRepetitionsBaseDelay_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
                		
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
                	   value = '''«((client_timers?.sdClientTimerRequestResponseMaxDelay_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
                	   
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
                  	 	 value = '''«((client_timers?.sdClientTimerRequestResponseMinDelay_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
                  	 	  	 
                  	 }
                  	 else
                  	 {
                  	  	 value = "SD_TIMER_UNUSED"
                  	 } 	
                 ]
                 
                 members += new Member()=>
                 [
                 	comment = '''ucInitialFindRepetitionsMax'''
                 	if(!(client_timers?.sdClientTimerInitialFindRepetitionsMax_PB.nullOrEmpty))
                 	{
                 	    value = '''«((client_timers?.sdClientTimerInitialFindRepetitionsMax_PB?.filterVariant(iter1,sd_inst.toString).head?.integerValue).toHex)»'''
                 	            	    
                 	}
                 	else
                 	{
                 		value = "SD_TIMER_UNUSED"
                 	}
                 ] 
                 
                 members += new Member ()=>
                 [
            	 comment = '''ulSubscribeEventgroupRetryDelay'''
            	 if (!(client_timers?.sdSubscribeEventgroupRetryDelay_PB.nullOrEmpty))
            	 {
            		 value = '''«((client_timers?.sdSubscribeEventgroupRetryDelay_PB?.filterVariant(iter1,sd_inst.toString).head.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		            			
            	  }
            	  else
            	  {
            		   value = "SD_TIMER_UNUSED"
            	  }       		
                ] 
             
                members += new Member()=>
                 [
                 	comment = '''ucSubscribeEventgroupRetryMax'''
                 	if(!(client_timers?.sdSubscribeEventgroupRetryMax_PB.nullOrEmpty))
                 	{
                 	    value = '''«((client_timers?.sdSubscribeEventgroupRetryMax_PB?.filterVariant(iter1,sd_inst.toString).head?.integerValue)?.toHex)»'''
                 	            	    
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
        
     return cstruct.head
  }
      /* Sd_GSaaClientTimerStatic: when no variants are configured and module is PB */
  def client_timer_staticNoVp()
  {
  	 var client_timer_arr = get_client_timer_arr()
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
            	value = '''«(client_timers?.sdClientTimerTTL_PB.head.integerValue.toHex)+'U'»'''
            ]
            
            members += new Member ()=>
            [
            	 comment = '''ulInitialFindDelayMax'''
            	  if (!(client_timers?.sdClientTimerInitialFindDelayMax_PB.nullOrEmpty))
            	  {
            		 value = '''«((client_timers?.sdClientTimerInitialFindDelayMax_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		            			
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
               	   	   value = '''«((client_timers?.sdClientTimerInitialFindDelayMin_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
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
                		value = '''«((client_timers?.sdClientTimerInitialFindRepetitionsBaseDelay_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
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
                	   value = '''«((client_timers?.sdClientTimerRequestResponseMaxDelay_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
                	   
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
                  	 	 value = '''«((client_timers?.sdClientTimerRequestResponseMinDelay_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
                  	 	 	 
                  	 }
                  	 else
                  	 {
                  	  	 value = "SD_TIMER_UNUSED"
                  	 } 	
                 ]
                 
                 members += new Member()=>
                 [
                 	comment = '''ucInitialFindRepetitionsMax'''
                 	if(!(client_timers?.sdClientTimerInitialFindRepetitionsMax_PB.nullOrEmpty))
                 	{
                 	    value = '''«((client_timers?.sdClientTimerInitialFindRepetitionsMax_PB?.head?.integerValue).toHex)»'''
                 	}
                 	else
                 	{
                 		value = "SD_TIMER_UNUSED"
                 	}
                 ] 
                 
                 members += new Member ()=>
                 [
            	 comment = '''ulSubscribeEventgroupRetryDelay'''
            	  if (!(client_timers?.sdSubscribeEventgroupRetryDelay_PB.nullOrEmpty))
            	  {
            		 value = '''«((client_timers?.sdSubscribeEventgroupRetryDelay_PB?.head.floatValue/Sd_main_func_period).intValue.toHex)»'''
            		            			
            	  }
            	  else
            	  {
            		   value = "SD_TIMER_UNUSED"
            	  }       		
                ] 
             
                members += new Member()=>
                 [
                 	comment = '''ucSubscribeEventgroupRetryMax'''
                 	if(!(client_timers?.sdSubscribeEventgroupRetryMax_PB.nullOrEmpty))
                 	{
                 	    value = '''«((client_timers?.sdSubscribeEventgroupRetryMax_PB?.head?.integerValue)?.toHex)»'''
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
  
  def get_used_soc_con_grp_arr()
  {
    for(sokcongrps : _soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
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
  /* Sd_GaaEvHandlerStatic: when no variants are configured and module is PB */  
  def Sd_GaaEvHandlerStaticNoVp(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_EvHandlerStaticType Sd_GaaEvHandlerStatic[SD_NO_OF_EV_HANDLERS] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  event_handler_staticNoVp()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
     /* Sd_GaaEvHandlerStatic: when variants are configured and module is PB */
   def Sd_GaaEvHandlerStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_EvHandlerStaticType Sd_GaaEvHandlerStatic[SD_NO_OF_EV_HANDLERS] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  Pbvc_list.map[event_handler_static(it)].join(',\n\n')
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   } 
    /* Sd_GaaEvHandlerStatic: when no variants are configured and module is PB */ 
  def event_handler_staticNoVp()
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
    		var server_timer_arr = get_server_timer_arr()
    			value = '''&Sd_GSaaServerTimerStatic[«server_timer_arr.indexOf(eve_handlers?.sdEventHandlerTimerRef_PB?.head?.reference?.shortNamePath?.
    				toString
    			)»]'''
    				
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
    	    value = '''«eve_handlers?.sdEventHandlerMulticastThreshold_PB?.head?.integerValue.toHex»'''
    		
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
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_udp_grp_id»'''
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
    			value = '''SoAdConf_SoAdRoutingGroup_«UdpActivationRoGrpId»'''
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
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_tcp_grp_id»'''
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
    			value = '''SoAdConf_SoAdRoutingGroup_«TcpActivationRoGrpId»'''
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
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_grp_id»'''
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
  /* Sd_GaaEvHandlerStatic: when variants are configured and module is PB */
def event_handler_static(PredefinedVariant iter)
  {    
    for (sd_inst : sdInstances){
    for (server_service : sd_inst?.sdServerServices.sortBy[sdServerServiceHandleId]){
    for (eve_handlers : server_service?.sdEventHandlers){
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaEvHandlerStatic : 
    	«Sd_GEveHandlerstructinst++» - «sd_inst?.shortName+'_'+server_service?.shortName+'_'+eve_handlers?.shortName+'_'+iter?.shortName»'''
    	members += new Member ()=>
    	[
    		comment = '''pServerTimer'''
    		//var server_timer_arr = get_server_timer_arr()
    		var Timer_pb = get_server_Timer_ids_map1()
            var server_timer_arr = Timer_pb?.get(iter?.shortName) 
    			value = '''&Sd_GSaaServerTimerStatic[«(Sd_server_timer_variant.get(iter.toString).intValue) + (server_timer_arr.indexOf(eve_handlers?.sdEventHandlerTimerRef_PB?.filterVariant(iter,sd_inst.toString)?.head?.reference?.shortNamePath?.
    				toString
    			))»]'''
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
    	    value = '''«eve_handlers?.sdEventHandlerMulticastThreshold_PB?.filterVariant(iter,sd_inst.toString)?.head?.integerValue.toHex»'''
    		
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
    		val act_eve_handler_udp_grp_id = get_act_eve_handler_udp_grp_id_vp(eve_handlers?.shortNamePath?.toString, iter)
    		if(!(act_eve_handler_udp_grp_id.nullOrEmpty))
    		{
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_udp_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}   		
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddUdpActivationRoGrpId'''
    		val UdpActivationRoGrpId = get_eve_hand_udp_act_id_vp(eve_handlers?.shortNamePath?.toString, iter)
    		if(!(UdpActivationRoGrpId.nullOrEmpty))
    		{
    			value = '''SoAdConf_SoAdRoutingGroup_«UdpActivationRoGrpId»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member ()=>
    	[
    		comment = '''ddTcpTriggeringRoGrpId'''	
    		val act_eve_handler_tcp_grp_id = get_act_eve_handler_tcp_grp_id_vp(eve_handlers?.shortNamePath?.toString, iter)
    		if(!(act_eve_handler_tcp_grp_id.nullOrEmpty))
    		{
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_tcp_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member() =>
    	[
    		comment = '''ddTcpActivationRoGrpId'''
    		val TcpActivationRoGrpId = get_eve_hand_tcp_act_id_vp(eve_handlers?.shortNamePath?.toString, iter)
    		if(!(TcpActivationRoGrpId.nullOrEmpty))
    		{
    			value = '''SoAdConf_SoAdRoutingGroup_«TcpActivationRoGrpId»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddMulticastActivationRoGrpId'''
    		val act_eve_handler_grp_id = get_act_eve_handler_grp_id_vp(eve_handlers?.shortNamePath?.toString,iter)
    		if(!(act_eve_handler_grp_id.nullOrEmpty))
    		{
    			value = '''SoAdConf_SoAdRoutingGroup_«act_eve_handler_grp_id»'''
    		}
    		else
    		{
    			value = '''«0.toHex»'''
    		}
    	]
    	
    	members += new Member()=>
    	[
    		comment = '''ddMulticastEventSoConId'''
    		val sd_eve_hand_multi_soc_con_id = get_multi_eve_soc_con_id_vp(eve_handlers?.shortNamePath?.toString, iter)
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
    		value = '''«stEvHandlerStaticFlag_vp(eve_handlers, iter).head»'''
    	]
    ]
    }
   }
  }
  return cstruct 
}
  /* stEvHandlerStaticFlag: when no variants are configured and module is PB */
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

 /* stEvHandlerStaticFlag: when no variants are configured and module is PB */
def stEvHandlerStaticFlag_vp(SdEventHandler handlers, PredefinedVariant iter)
{
   var cstruct = new ArrayList<CStruct>
   cstruct += new CStruct()=> 
   [
   	  members += new Member()=>
   	  [
   	  	  comment = '''blUdpTriggeringRoGrpIdPresent'''
   	  	  val act_eve_handler_udp_grp_id = get_act_eve_handler_udp_grp_id_vp(handlers?.shortNamePath?.toString, iter)
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
   	  	  val UdpActivationRoGrpId = get_eve_hand_udp_act_id_vp(handlers?.shortNamePath?.toString, iter)
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
   	  	  val act_eve_handler_tcp_grp_id = get_act_eve_handler_tcp_grp_id_vp(handlers?.shortNamePath?.toString, iter)
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
   	  	   val TcpActivationRoGrpId = get_eve_hand_tcp_act_id_vp(handlers?.shortNamePath?.toString, iter)
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
   	   	   val act_eve_handler_grp_id = get_act_eve_handler_grp_id_vp(handlers?.shortNamePath?.toString, iter)
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
   	   	   val sd_eve_hand_multi_soc_con_id = get_multi_eve_soc_con_id_vp(handlers?.shortNamePath?.toString, iter)
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
     /* Sd_GaaConsumedEvGrpStatic: when variants are configured and module is PB */
  def Sd_GaaConsumedEvGrpStatic(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ConsumedEvGrpStaticType Sd_GaaConsumedEvGrpStatic[SD_NO_OF_CONSUMED_EV_GRP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
 Pbvc_list.map[consumed_eve_grp_static(it)].join(',\n\n')
 

 if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
 /* Sd_GaaConsumedEvGrpStatic: when no variants are configured and module is PB */  
 def Sd_GaaConsumedEvGrpStaticNoVp(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
  const Sd_ConsumedEvGrpStaticType Sd_GaaConsumedEvGrpStatic[SD_NO_OF_CONSUMED_EV_GRP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  consumed_eve_grp_staticNoVp()
  
  if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   /* Sd_GaaConsumedEvGrpStatic: when no variants are configured and module is PB */   
  def consumed_eve_grp_staticNoVp()
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
              	  value = '''SoAdConf_SoAdRoutingGroup_«act_consumed_eve_grp_id»'''
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
          	   	   value = '''SoAdConf_SoAdRoutingGroup_«TcpActivationRoGrpId»'''
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
          	  	  value = '''SoAdConf_SoAdRoutingGroup_«UdpActivationRoGrpId»'''
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
            	value = '''«stConsumedEvGrpStaticFlagNoVp(consumed_eve_grp).head»'''
            ]
         ] 
       }
     }
   }
   return cstruct
 }
  /* Sd_GaaConsumedEvGrpStatic: when variants are configured and module is PB */
 def consumed_eve_grp_static(PredefinedVariant iter1)
  {
    for (sd_inst : sdInstances) {
    for (client_service : sd_inst?.sdClientServices) {
    for (consumed_eve_grp : client_service?.sdConsumedEventGroups){
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaConsumedEvGrpStatic : 
    	«Sd_GConsumedEvstructinst++» - «sd_inst?.shortName+'_'+
    client_service?.shortName+'_'+consumed_eve_grp?.shortName+'_'+iter1?.shortName »'''
        
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
         	  for (timer : consumed_eve_grp?.sdConsumedEventGroupTimerRef_PB?.filterVariant(iter1,sd_inst.toString))
         	  {
         	  	   var client_timer_arr_pb = get_client_Timer_ids_map()
     		       var client_timer_arr = client_timer_arr_pb.get(iter1?.shortName)
     		       
         	  	   value = '''&Sd_GSaaClientTimerStatic[«((Sd_client_timer.get(iter1.toString).intValue) + (client_timer_arr.indexOf(timer?.reference?.shortNamePath?.
         	  	   	toString
         	  	   )))»]'''     	  	   
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
          	  val act_consumed_eve_grp_id = get_act_consumed_eve_grp_id_vp(consumed_eve_grp?.shortNamePath?.toString, iter1)
              if(!(act_consumed_eve_grp_id.nullOrEmpty))
              {
              	  value = '''SoAdConf_SoAdRoutingGroup_«act_consumed_eve_grp_id»'''
              }
              else
              {
               	   value = '''«0.toHex»'''
              }
          ]
          
          members += new Member ()=>
          [
          	   comment = '''ddTcpActivationRoGrpId'''
          	   val TcpActivationRoGrpId = get_con_eve_tcp_act_id_vp(consumed_eve_grp?.shortNamePath?.toString, iter1)
          	   if(!(TcpActivationRoGrpId.nullOrEmpty))
          	   {
          	   	   value = '''SoAdConf_SoAdRoutingGroup_«TcpActivationRoGrpId»'''
          	   }
          	   else
          	   {
          	   	    value = '''«0.toHex»'''
          	   }
          ]
          
          members += new Member() =>
          [
          	  val UdpActivationRoGrpId = get_con_eve_udp_act_id_vp(consumed_eve_grp?.shortNamePath?.toString, iter1)
          	  comment =  '''ddUdpActivationRoGrpId''' 
          	  if(!(UdpActivationRoGrpId.nullOrEmpty))
          	  {
          	  	  value = '''SoAdConf_SoAdRoutingGroup_«UdpActivationRoGrpId»'''
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
            	value = '''«stConsumedEvGrpStaticFlag(consumed_eve_grp, iter1).head»'''
            ]
         ] 
       }
     }
   }
   return cstruct
 }
 /* stConsumedEvGrpStaticFlag: when variants are configured and module is PB */
def stConsumedEvGrpStaticFlag(SdConsumedEventGroup consumed, PredefinedVariant iter1)
{
   var cstruct = new ArrayList<CStruct>
   cstruct += new CStruct()=>
   [
   	  members += new Member()=>
   	  [
   	  	  comment = '''blAutoRequire'''
   	  	  for (value : consumed?.sdConsumedEventGroupAutoRequire_PB?.filterVariant(iter1,consumed.toString))
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
   	   	   val act_consumed_eve_grp_id = get_act_consumed_eve_grp_id_vp(consumed?.shortNamePath?.toString, iter1)
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
   	   	   val TcpActivationRoGrpId = get_con_eve_tcp_act_id_vp(consumed?.shortNamePath?.toString, iter1)
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
   	   	   val UdpActivationRoGrpId = get_con_eve_udp_act_id_vp(consumed?.shortNamePath?.toString, iter1)
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
  /* stConsumedEvGrpStaticFlag: when no variants are configured and module is PB */
 def stConsumedEvGrpStaticFlagNoVp(SdConsumedEventGroup consumed)
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
   const Sd_ServiceGroupType Sd_GaaServicegroupStatic[SD_SERVICE_GROUP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  Pbvc_list.map[getservicegroupstatic(it)].join(',\n\n')
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   } 
   
/* Sd_Service_group */
 
 def Sd_GaaServicegroupStaticNoVp(){
  cstruct.clear
  val str = '''
  #define «modulePrefix»_START_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h"
   const Sd_ServiceGroupType Sd_GaaServicegroupStatic[SD_SERVICE_GROUP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  servicegroupstaticNoVp()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
  def getservicegroupstatic(PredefinedVariant iter1)
  {
  	val pbservicegrps = module?.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1, module?.sdConfig.toString)?.toSet
  	pbservicegrps?.map[servicegroupstatic(it, iter1)].join(',\n')
  }   
  def servicegroupstatic(SdServiceGroup srgrp, PredefinedVariant iter1)
  {
   if(srgrp != null)
    {
    	cstruct += new CStruct()=>
       [
    	comment = '''Sd_GaaServicegroupStatic : «iter1?.shortName»'''
        members += new Member ()=>
         [
         	  comment = '''usHandleId'''
         	  value = '''«srgrp?.sdServiceGroupHandleId.toHex»'''
         ]
       ] 
    }
    
  return cstruct
 }
 
 def servicegroupstaticNoVp()
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
   const uint16 Sd_GaaServicegroupClientArray[«SerGrp_handle_ids?.size»][SD_CLIENT_REF_SERVICEGRP_CONFIGURED] =
  {
  	
  	«Pbvc_list.map[getServicegroupClientArray(it)].join(',\n\n')»
  	
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''
}  
 def getServicegroupClientArray(PredefinedVariant iter1)
  {
  	val pbservicegrps = module?.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1, module?.sdConfig.toString)?.toSet
  	pbservicegrps?.map[servicegroupClientArray(it, module, iter1)].join(',\n')
  }        
 def servicegroupClientArray(SdServiceGroup sdGrp, Sd module, PredefinedVariant iter1)
 {
   var clientHandleIds =  module?.sdConfig?.sdInstances?.map[sdClientServices?.filter[sdServiceGroupRefs_PB?.filterVariant(iter1,module.toString)?.filter[it.reference == sdGrp]?.size > 0]]?.filterNull?.filterNull?.flatten?.map[sdClientServiceHandleId]
   return ("{"+clientHandleIds.join(",")+"}")
 }
 
 /* Service Group Client Array */
 def Sd_GaaServicegroupClientArrayNoVp(Sd module){
  '''
  #define «modulePrefix»_START_SEC_CONST_16
  #include "Sd_MemMap.h"
   const uint16 Sd_GaaServicegroupClientArray[«module.sdConfig?.sdServiceGroups_PB.map[sdServiceGroupHandleId]?.filterNull?.size»][«module.sdConfig.sdInstances.map[sdClientServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size»] =
  {
  	
  	«module?.sdConfig?.sdServiceGroups_PB?.toList?.map[servicegroupClientArrayNoVp(module)].join(",\n")»
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''
}  
         
 def servicegroupClientArrayNoVp(SdServiceGroup sdGrp, Sd module)
 {
   var clientHandleIds =  module?.sdConfig?.sdInstances?.map[sdClientServices?.filter[sdServiceGroupRefs_PB?.filter[it.reference == sdGrp]?.size > 0]]?.filterNull?.filterNull?.flatten?.map[sdClientServiceHandleId]
   return ("{"+clientHandleIds.join(",")+"}")
 }  
         
 def Sd_GaaServicegroupServerArray(Sd module){
  '''
  #define «modulePrefix»_START_SEC_CONST_16
  #include "Sd_MemMap.h"
   const uint16 Sd_GaaServicegroupServerArray[«SerGrp_handle_ids?.size»][SD_SERVER_REF_SERVICEGRP_CONFIGURED] =
  {
  	
  	«Pbvc_list.map[getServicegroupServerArray(it)].join(',\n\n')»
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''
} 
  
  def getServicegroupServerArray(PredefinedVariant iter1)
  {
  	val pbservicegrps = module?.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1, module?.sdConfig.toString)?.toSet
  	pbservicegrps?.map[servicegroupServerArray(it, module, iter1)].join(',\n')
  }
         
 def servicegroupServerArray(SdServiceGroup sdGrp, Sd module, PredefinedVariant iter1)
 {
  var  serverHandleIds = module?.sdConfig?.sdInstances?.map[sdServerServices?.filter[sdServiceGroupRefs_PB?.filterVariant(iter1,module.toString)?.filter[it.reference == sdGrp]?.size > 0]]?.filterNull?.filterNull?.flatten?.map[sdServerServiceHandleId]
  return ("{"+serverHandleIds.join(",")+"}")
 }

def Sd_GaaServicegroupServerArrayNoVp(Sd module){
  '''
  #define «modulePrefix»_START_SEC_CONST_16
  #include "Sd_MemMap.h"
   const uint16 Sd_GaaServicegroupServerArray[«module.sdConfig?.sdServiceGroups_PB.map[sdServiceGroupHandleId]?.filterNull?.size»][«(module.sdConfig?.sdInstances.map[sdServerServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size)»] =
  {
  	«module?.sdConfig?.sdServiceGroups_PB?.toList?.map[servicegroupServerArrayNoVp(module)]?.join(",\n")»
  };
  #define «modulePrefix»_STOP_SEC_CONST_16
  #include "Sd_MemMap.h" '''
} 
         
 def servicegroupServerArrayNoVp(SdServiceGroup sdGrp, Sd module)
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
   const Sd_ServicegroupClientArrayType Sd_GaaServicegroupClientStatic[SD_SERVICE_GROUP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  Pbvc_list.map[getservicegroupClientstatic(it)].join(',\n\n')
  
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
 def getservicegroupClientstatic(PredefinedVariant iter1)
  {
  	val pbservicegrps = module?.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1, module?.sdConfig.toString)?.toSet
  	pbservicegrps?.map[servicegroupClientstatic(it, iter1)].join(',\n')
  }  
 def servicegroupClientstatic(SdServiceGroup sd_Sgrp, PredefinedVariant iter1)
  {
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupClienttStatic '''
        
        Sd_Cfg_H.size_Array=0
         members += new Member ()=>
         [
         	for(Sd_inst:sdInstances){
         		for(clientServices:Sd_inst.sdClientServices)
         		if(clientServices?.sdServiceGroupRefs_PB?.filterVariant(iter1,module.toString)?.filter[it.reference == sd_Sgrp]?.size>0)
         		{
         			
         		Sd_Cfg_H.size_Array	=Sd_Cfg_H.size_Array +1
         	  
         	  }
         	  }
         	  comment = '''usArray_size'''
         	  value = '''«Sd_Cfg_H.size_Array»'''
         ]
       ]
  
  
   return cstruct
 }
 
 /* Service Group Client Array*/ 
  def Sd_GaaServicegroupClientStaticNoVp(){
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
  
  servicegroupClientstaticNoVp()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
  def servicegroupClientstaticNoVp()
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
   const Sd_ServicegroupServerArrayType Sd_GaaServicegroupServerStatic[SD_SERVICE_GROUP] =
  {'''
       val stp =
  '''};
  #define «modulePrefix»_STOP_SEC_CONST_UNSPECIFIED
  #include "Sd_MemMap.h" '''
  
  Pbvc_list.map[getservicegroupServerstatic(it)].join(',\n\n')
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   
   def getservicegroupServerstatic(PredefinedVariant iter1)
  {
  	val pbservicegrps = module?.sdConfig?.sdServiceGroups_PB?.filterVariant(iter1, module?.sdConfig.toString)?.toSet
  	pbservicegrps?.map[servicegroupServerstatic(it, iter1)].join(',\n')
  }    
   
 def servicegroupServerstatic(SdServiceGroup sd_Sgrp, PredefinedVariant iter1)
  {
    
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupServerStatic '''
        
        Sd_Cfg_PBcfg_H.size_Array=0
         members += new Member ()=>
         [
         	for(Sd_inst:sdInstances){
         		for(ServerServices:Sd_inst.sdServerServices)
         		if(ServerServices?.sdServiceGroupRefs_PB?.filterVariant(iter1,module.toString)?.filter[it.reference == sd_Sgrp]?.size>0)
         		{
         			
         		Sd_Cfg_PBcfg_H.size_Array = Sd_Cfg_PBcfg_H.size_Array +1
         	  
         	  }
         	  }
         	  comment = '''usArray_size'''
         	  value = '''«Sd_Cfg_PBcfg_H.size_Array»'''
         ]
       ]
  
  
   return cstruct
 }
 
 /*Service Group Server Array  */
  def Sd_GaaServicegroupServertStaticNoVp(){
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
  
  servicegroupServerstaticNoVp()
    if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }    
   
     def servicegroupServerstaticNoVp()
  {
    for (sd_Sgrp : sdServiceGroups) {
  	 
    
    cstruct += new CStruct()=>
    [
    	comment = '''Sd_GaaServicegroupServerStatic '''
        
        Sd_Cfg_PBcfg_H.size_Array=0
         members += new Member ()=>
         [
         	for(Sd_inst:sdInstances){
         		for(ServerServices:Sd_inst.sdServerServices)
         		if(ServerServices?.sdServiceGroupRefs_PB?.filter[it.reference == sd_Sgrp]?.size>0)
         		{
         			
         		Sd_Cfg_PBcfg_H.size_Array = Sd_Cfg_PBcfg_H.size_Array +1
         	  
         	  }
         	  }
         	  comment = '''usArray_size'''
         	  value = '''«Sd_Cfg_PBcfg_H.size_Array»'''
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
  
  Pbvc_list.map[getclientproviderAddressinst(it)].join(',\n\n')
   
  if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   def Sd_GaaClientProviderAddressNoVp(){
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
  clientproviderAddressNoVp()
   
  if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
   
   def getclientproviderAddressinst(PredefinedVariant iter)
     {
     	val sdInst = module.sdConfig.sdInstances.toSet
     	sdInst.map[getclientproviderAddresscli(it,iter)].join(',\n\n')
     }
     
     def getclientproviderAddresscli(SdInstance sdins, PredefinedVariant iter)
     {
     	val cliser = sdins?.sdClientServices.toSet
     	cliser.map[getclientproviderAddress(it, iter)].join(',\n\n')
     }
     
     def getclientproviderAddress(SdClientService cliser, PredefinedVariant iter)
     {
     	val cliprov = cliser?.sdClientServiceAllowedProviders_PB?.filterVariant(iter, module?.sdConfig.toString)?.toSet
     	cliprov.map[clientproviderAddress(it, iter)].join(',\n\n')
     }
   
   def clientproviderAddress(SdClientServiceAllowedProvider cliSerAllowprov, PredefinedVariant iter)
     {
       
           cstruct += new CStruct()=>
            [
    	      comment = '''Sd_GaaClientServiceAllowedProviderStatic : PostBuildConfigSet_«iter.shortName»'''
    	      members += new Member()=>
              [
                   comment = "SdIpAddressType"
                   if(cliSerAllowprov.sdIpAddressType == null)
                     {
                       value = '''SD_NULL_PTR'''
                      }
                   else
                     {
                      value = '''«cliSerAllowprov.sdIpAddressType»'''
                     }

               ]
  
    	comment = '''Sd_GaaClientServiceAllowedProviderStatic  : PostBuildConfigSet_«iter.shortName»'''
    	
         members += new Member ()=>
         [
         if(cliSerAllowprov?.sdIpAddressType.toString == "SD_AF_INET"   )
           {
    
           comment = '''AllowedProviderAddress'''
           val array= cliSerAllowprov.sdIpAddress.toString.replace(".",",")
          
              value= '''{«array»}'''
           }
          else
          {
    	    val array= cliSerAllowprov.sdIpAddress.toString.replace(".",",")
            value= '''{«array»}'''
           }
        ]
      ]
  
  
   return cstruct
 }
 
 def clientproviderAddressNoVp()
     {
       for(Sd_inst:sdInstances){
  		for(ServerServices:Sd_inst.sdClientServices){ 
  		 for(ServerServices2 :ServerServices.sdClientServiceAllowedProviders_PB)
  		 {
           cstruct += new CStruct()=>
            [
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
  
  Pbvc_list.map[getserverconsumerAddressinst(it)].join(',\n\n')
 if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }   
   
 def Sd_GaaServerConsumerAddressNoVp(){
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
  
  serverconsumerAddressNoVp()
 if (!cstruct.nullOrEmpty) 
        {
          '''
          «str»
         «cstruct.join("," + System.lineSeparator)»
          «stp»
          '''
        }
   }
 
 def getserverconsumerAddressinst(PredefinedVariant iter)
     {
     	val sdInst = module.sdConfig.sdInstances.toSet
     	sdInst.map[getserverconsumerAddressser(it,iter)].join(',\n\n')
     }
 def getserverconsumerAddressser(SdInstance sdins, PredefinedVariant iter)
     {
     	val ser = sdins?.sdServerServices.toSet
     	ser.map[getserverconsumerAddress(it, iter)].join(',\n\n')
     }
 def getserverconsumerAddress(SdServerService ser, PredefinedVariant iter)
     {
     	val cliprov = ser?.sdServerServiceAllowedConsumerss_PB?.filterVariant(iter, module?.sdConfig.toString)?.toSet
     	cliprov.map[serverconsumerAddress(it, iter)].join(',\n\n')
     }        
     
def  serverconsumerAddress(SdServerServiceAllowedConsumers server, PredefinedVariant iter)
  {
    
          cstruct += new CStruct()=>
           [
    	   comment = '''Sd_GaaServerServiceAllowedConsumerStatic ''' 
    	    members += new Member()=>
           [
            comment = "SdIpAddressType"
            if(server.sdIpAddressType == null)
            {
                 value = '''SD_NULL_PTR'''
            }
            else
            {
                value = '''«server.sdIpAddressType»'''
            }

            ]
           members += new Member ()=>
            [
              if(server?.sdIpAddressType.toString == "SD_AF_INET"   )
              {
                 comment = '''AllowedProviderAddress'''
                 val array= server.sdIpAddress.toString.replace(".",",")
                 value= '''{«array»}'''
              }
              else
              {
    	         val array= server.sdIpAddress.toString.replace(".",",")
                 value= '''{«array»}'''
              }
                    
             ]
       
           ]
  
        
   return cstruct
 }
 def  serverconsumerAddressNoVp()
  {
    for(Sd_inst:sdInstances){
  		for(ServerServices:Sd_inst.sdServerServices){ 
  		for(ServerServices2:ServerServices.sdServerServiceAllowedConsumerss_PB)
  		 {
          cstruct += new CStruct()=>
           [
    	   comment = '''Sd_GaaServerServiceAllowedConsumerStatic ''' 
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
 def get_server_handle_count()
 {
 	val inst = module?.sdConfig?.sdInstances
 	val hdlids = inst?.map[sdServerServices.map[sdServerServiceHandleId?.intValue]]?.filterNull?.flatten
 	for(id :hdlids)
 	{
 		server_handle_count.add(id)
 		
 	}
 	return server_handle_count
 }
 def servertimerRefpb(PredefinedVariant iter1)
   {
   	servertimerpb(iter1)
   	for(tim : sd_timer.get(iter1?.shortName))
   	{
   		SerTimerRef.add(tim)
   	}
   }
   def servertimerpb(PredefinedVariant iter1)
   {
   	var Timer = get_server_timer_arr1 
   	for (sd_inst : sdInstances)
    {
     for (Server_Timer : Timer)
      {
       	sd_timerref.add(Server_Timer?.shortNamePath.toString)
       	
      }
     }
     
      sd_timer.put(iter1?.shortName, sd_timerref)
      
      
   }
   
 def servertimerpbNoVp()
   {
   	 for(sd_inst : module?.sdConfig?.sdInstances)
     {
       for(Timer : sd_inst?.sdServerTimers)
       {
       	  sd_timercount.put(Timer?.shortNamePath?.toString,New_ServerTimer_countpb)
       	  New_ServerTimer_countpb++
       	  
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
    const Sd_SoConGroupStaticType Sd_GaaSoConGroupStatic[«Sd_Cfg_PBcfg_H.Soad_cnt_arr.size»] =
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
    
    for (sokcongrps : _soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
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
}

                  
      
       
       
       
       
       

