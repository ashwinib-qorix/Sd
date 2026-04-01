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

/*
 * Provides template for generating configuration for Sd C source file.
 * To be extended by the class providing content to be generated.
 */

@WorkflowComponent
class Sd_Cfg_Lcfg_C extends Cfg_C_Template <Sd> {

  extension Sd_Cfg_PBcfg_H = Sd_Cfg_PBcfg_H.EXTENSION_CFG_H
 
 static extension VariantHandlingExtensions = VariantHandlingExtensions.INSTANCE
  var Iterable <PredefinedVariant> predefinedVariant
  var pbvclist = new ArrayList<PredefinedVariant>
  public static Iterable<PredefinedVariant> Pbvc_list
  
  
  var static Hndlindx = 0
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
  
  
  var New_ServerTimer_countpb = 0
  
  
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
  var array = new ArrayList<Integer>
  
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
  var consumed_eve_grp_id_hash = new HashMap<String, ArrayList<HashMap<String, Integer>>>()
  var soAdRoutingGroups_arr = new ArrayList<String>()
  var server_service_cnt = new ArrayList<String>()
  
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
  sd_con_eve_udp_ref_arr = get_sd_con_eve_udp_ref()
  sd_eve_handler_tcp_ref_arr = get_sd_eve_handler_tcp_ref_arr()
  sd_eve_handler_udp_ref_arr = get_sd_eve_handler_udp_ref_arr()
  server_service_cnt = get_server_services_cnt()
  
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
  sort_used_ser_grp_arr = get_service_grp_arr1()
  fill_soad_con_array()
  
  get_used_soc_con_grp_arr()
   

  write('''
    
  

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
    
    
  «/* Design ID : SD_SDD_0529,SD_SDD_0408,SD_SDD_6001,SD_SDD_6002,SD_SDD_6003*/»
  «/* Design ID : SD_SDD_0140,SD_SDD_0382,SD_SDD_0381,SD_SDD_0384,SD_SDD_6008*/»
  «/* Design ID : SD_SDD_0383,SD_SDD_6009,SD_SDD_0265,SD_SDD_0386,SD_SDD_0022*/»
  «/* Design ID : SD_SDD_0264,SD_SDD_0385,SD_SDD_0146,SD_SDD_0025,SD_SDD_6004*/»
  «/* Design ID : SD_SDD_0266,SD_SDD_6005,SD_SDD_0027,SD_SDD_6006,SD_SDD_0026*/»
  «/* Design ID : SD_SDD_6007,SD_SDD_0139,SD_SDD_0069,SD_SDD_0444,SD_SDD_0446*/»
  «/* Design ID : SD_SDD_6011,SD_SDD_6012,SD_SDD_6013,SD_SDD_6014,SD_SDD_0272*/»
    «««.........................Start For Sd_GaaSoConGroupStatic Array............................»»
    

    
            
    ''')

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

   
	
	def getShortName(Integer integer) {
		throw new UnsupportedOperationException("TODO: auto-generated method stub")
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
   * @param consumed_eve_grp String type, coneve_grp_id Integer Type
   * @return None
   */
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
 
   
   
  
 
 
 
 
  
 
 
   
 
   
   
  
}

                  
      
       
       
       
       
       

