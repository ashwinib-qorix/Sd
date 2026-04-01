/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name     : Sd_Cfg_H.xtend
 *
 * Description   : It Provides template for generating configuration for Sd_Cfg.h file
 *
 * Prev.Safety compliant AUTOSAR release version:R23-11
 *
 * Prev.Safety compliant AUTOSAR SW version: 1.0.0
 */

/*
 * Revision History:
 * Date            Changed By             Description
 * 24-Sep-2024     Devika Ramesh      ConfigSetHandle generation update
 * 07-July-2025    Samarth Golwalker  Migration Release R24-11.
 * 08-Aug-2025     Gourav Purohit     Version Updated to 0.2.0.
 * 01-Sep-2025     Gourav Purohit     Version Updated to 0.3.0.
 */




package com.kpit.c4k.bsw.sd.codegen

import com.kpit.c4k.bsw.templates.Cfg_H_Template
import com.kpit.c4k.core.model.StringPath
import com.kpit.c4k.core.workflow.annotations.WorkflowComponent
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerTimer
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdGeneral
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.TcpIp
import java.util.ArrayList
import java.util.HashMap
import java.util.List
import java.util.TreeMap
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdServiceGroup
import com.kpit.c4k.ecuc.vh.VariantHandlingExtensions
import autosar40.genericstructure.varianthandling.PredefinedVariant
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerTimer
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.EcuC
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceAllowedProvider

@WorkflowComponent
class Sd_Cfg_PBcfg_H extends Cfg_H_Template<Sd> {

   public static val EXTENSION_CFG_H = new Sd_Cfg_PBcfg_H
    static extension VariantHandlingExtensions = VariantHandlingExtensions.INSTANCE
    public static Iterable<PredefinedVariant> Pbvc_list
   SdGeneral Sd_General

   /* create list and store values */
   var public static Sd_GInstances_arr = new ArrayList<String>()
   var public static Sd_server_timer = new HashMap<String, String>()
   var static inst_uni_multicast_rx_pdu = new ArrayList<Integer>()
   var static ser_grp_cnt = new ArrayList<Integer>()
 
   SoAd _Soad = null
   Sd _Sd
   TcpIp _tcpip = null
   double Sd_Mainfunc_period_ms
   var static int evhandler_timer_cnt = 0
   var public static int client_timer_cnt = 0
    var public static int client_timer_cnt_pb =0
    var public static int server_timer_cnt_vp =0
   var public static int service_grp_cnt0 = 0
   var public static int service_grp_cnt1 = 0
   var public static int server_timer_cnt_pb = 0
    var public static int blacklisted_grp_cnt = 0
   var static int Soad_socket_cnt = 0
   var static int config_opt_total_length = 0
    var public static int size_Array=0;
   var static int otherservKeyLength = 0
   var totalSdSerGrps = 0
   var cliserallprovs = 0
   var ServerSerallCons = 0
   var static int config_opt_inst_hstnm_index
   var static int config_opt_serv_cap_rec_index
   var static int config_opt_client_cap_rec_index
   var static int config_opt_consumed_eve_index
   var static int config_opt_eve_handler_index
   var static act_server_routing_grp = new HashMap<String, String>()
   var static client_timer = new HashMap<String, Integer>()
   var static act_client_routing_grp = new HashMap<String, String>()
   var static act_consumed_eve_routing_grp = new HashMap<String, String>()
   var static act_eve_handler_routing_grp = new HashMap<String, String>()
   var static sd_con_eve_tcp_ref_arr = new HashMap<String, String>()
   var static sd_con_eve_udp_ref_arr = new HashMap<String, String>()
   var static sd_eve_handler_tcp_ref_arr = new HashMap<String, String>()
   var static sd_eve_handler_udp_ref_arr = new HashMap<String, String>()
   var static sd_eve_handler_multi_soc_con = new HashMap<String, String>()
   var static act_eve_handler_udp_routing_grp = new HashMap<String, String>()
   var static act_eve_handler_tcp_routing_grp = new HashMap<String, String>()
   
   
   var static domain_type_hash = new HashMap<String, String>()
   var static StringPath sd_serv_tcp_ref
   var static StringPath sd_serv_udp_ref
   var static StringPath sd_client_tcp_ref
   var static StringPath sd_client_udp_ref
    var static StringPath sd_client_grp_ref
   var static StringPath sd_client_con_ev_grp_ref
   var static String type_defs
   var public static Soad_cnt_arr = new ArrayList<String>
   var static Soad_client_con_ev_grp = new ArrayList<String>
   var static time_type_arr = new ArrayList<Double>
   var static server_timer_arr = new ArrayList<String>()
   var static client_timer_arr = new ArrayList<String>()
   var static server_timer_arr1 = new ArrayList<SdServerTimer>()
    var static server_Sgrp_arr = new ArrayList<String>()
     var static client_Sgrp_arr = new ArrayList<String>()
   var static config_opt_serv_cap_rec = new ArrayList<Object>
   var static config_opt_client_cap_rec = new ArrayList<Object>
   var static config_opt_consumed_eve = new ArrayList<Object>
   var static config_opt_eve_handler = new ArrayList<Object>
   var static config_opt_sd_inst_hstname = new ArrayList<Object>
   
   var static config_chars = new ArrayList<String>()
   var static config_values = new ArrayList<String>()
   var static otherserv = new ArrayList<Object>
   var public static server_services_cnt = new ArrayList<String>()
   var public static client_services_cnt = new ArrayList<String>()
   var public static service_grp_cnt = new ArrayList<String>()
   var static eve_handler_cnt = new ArrayList<String>()
   var static server_service_arr = new ArrayList<String>()
   var public static client_soc_congrp_arr = new ArrayList<String>()
    var public static Service_grp = new ArrayList<String>()
   var public static consumed_eve_grp_cnt = new ArrayList<String>()
   var public static event_handle_ids = new ArrayList<Integer>()
   var static server_handle_ids = new ArrayList<Integer>()
   //var static server_handle_ids_ = new ArrayList<Integer>()
   var static client_handle_ids = new ArrayList<Integer>()
   var static SerGrp_handle_ids = new ArrayList<String>()
   var static con_eve_grp_handle_ids = new ArrayList<Integer>()
   var static consumedevegrphash = new HashMap<String, Integer>()
   var static consumed_eve_grp_list = new ArrayList<HashMap<String, Integer>>()
   var static consumed_eve_grp_id_hash = new HashMap<String, ArrayList<HashMap<String, Integer>>>()
   var static server_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
   var static client_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
   var static client_Timer_ids_map = new HashMap<String, ArrayList<String>>()
   var static con_eve_grp_Timer_ids_map = new HashMap<String, ArrayList<String>>()
   var static server_Timer_ids_map = new HashMap<String, ArrayList<SdServerTimer>>()
   var static server_Timer_ids_map1 = new HashMap<String, ArrayList<String>>()
   var static con_eve_grp_handle_ids_map = new HashMap<String, ArrayList<Integer>>()
   var static act_client_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static act_server_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static act_consumed_eve_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static sd_con_eve_tcp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
   var static sd_con_eve_udp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
   var static act_eve_handler_udp_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static act_eve_handler_tcp_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static sd_eve_handler_tcp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
   var static sd_eve_handler_udp_ref_arr_map = new HashMap<String, HashMap<String, String>>()
   var static act_eve_handler_routing_grp_map = new HashMap<String, HashMap<String, String>>()
   var static sd_eve_handler_multi_soc_con_map = new HashMap<String, HashMap<String, String>>()
   var static domain_type_hash_map = new HashMap<String, HashMap<String, String>>()
   var static inst_uni_multicast_rx_pdu_map = new HashMap<String, ArrayList<Integer>>()
   var static config_opt_inst_hash = new HashMap<String, Integer>()
   var static config_opt_con_eve_hash = new HashMap<String, Integer>()
   var static config_opt_eve_handler_hash = new HashMap<String, Integer>()
   var static config_opt_client_serv_hash = new HashMap<String, Integer>()
   var static config_opt_server_serv_hash = new HashMap<String, Integer>()
   var static eve_handler_handle_ids = new ArrayList<Integer>()
   var static sd_client_con_ev_grp_ref_hash = new HashMap<String, HashMap<Integer, ArrayList<String>>>()
   var static other_servevals = new HashMap<String, Integer>()
   var static other_serve_main_hash = new HashMap<String, HashMap<String,Integer>>()
   
   /* for key value of records */
   var client_cap_rec = new HashMap<String, String>
   /*fill client_cap_rec */
   var client_capability_rec_final = new HashMap<String, HashMap<String, String>>()
   /*fill client_capability_rec_final */
   var client_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>()
   var client_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>()
   var client_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>()
   var sort_client_service_hash = new HashMap<Integer, ArrayList<HashMap<String,
   ArrayList<HashMap<String, HashMap<String, String>>>>>>()
   /* for key value of records */
   var server_cap_rec = new HashMap<String, String>
   /*fill server_cap_rec */
   var server_capability_rec_final = new HashMap<String, HashMap<String, String>>()
   /*fill server_capability_rec_final */
   var server_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>()
   var server_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>()
   var server_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>()
   var sort_server_service_hash = new HashMap<Integer, ArrayList<HashMap<String,
   ArrayList<HashMap<String, HashMap<String, String>>>>>>()
   
   var sd_conevgrp_sokbaseid_hash = new HashMap<Integer, ArrayList<String>>()
   
   var New_ServerTimer_countpb = 0
  
   /*fill con_eve_cap_rec */
 
   /*fill con_eve_capability_rec_final */
   var con_eve_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>()
   var con_eve_cl_serv_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
   var con_eve_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>()
   var ser_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>()
   var sort_con_eve_hash = new HashMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String,
   HashMap<String, String>>>>>>


   
 
   /*fill eve_handlere_capability_rec_final */
   var eve_handler_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>()
   var eve_handler_grp_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
   
   var eve_handler_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>()
   var sort_eve_handler_hash = new HashMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String,
    String>>>>>>
   var con_ev_grp_ref = new ArrayList<String>()
   List<SdInstance> SdInstance 
   List<SdServiceGroup> SdServiceGroup
   List<SdClientServiceAllowedProvider> clientserallowprovs
   int rec_cnt

   int count = 0
   int client_rec_len = 0
   int client_rec_length = 0
   int eve_handler_rec_len = 0
   int eve_handler_rec_length = 0
   int index = 0
   int server_rec_len = 0
   int server_rec_length = 0
   int con_eve_rec_len = 0
   int con_eve_rec_length = 0
   int sd_hst_name_length = 0
   int client_rec_cnt = 0
   int server_rec_cnt = 0
   int con_eve_rec_cnt = 0
   int eve_handler_rec_cnt = 0
   

   int otherserv_flag = 0

  int tcpip_ipv6_support = 0


   override protected getModuleClass() {
     return Sd
   }

   override protected getTemplateVersion() {
     return "0.3.0"
   }

   override protected writeIncludeSection() {
     super.writeIncludeSection()
     write('''
     #include "SoAd.h"
     #include "TcpIp_Types.h"
     ''')
     }

   override protected writePrecompileMacros() {
   	
   	
    
     super.writePrecompileMacros()
     _tcpip = findModule(TcpIp)
     _Soad = findModule(SoAd)
     SdInstance = module?.sdConfig?.sdInstances
     SdServiceGroup = module?.sdConfig?.sdServiceGroups_PB
     Sd_General = module?.sdGeneral
     Sd_Mainfunc_period_ms = (Sd_General.sdMainFunctionCycleTime * 1000)
     
     if(!module?.getPredefinedVariants.nullOrEmpty)
      {
         Pbvc_list = module?.getPredefinedVariants.sortBy[shortName]
      }
      else
      {
      	fill_sd_detailsNoVp()
      }
      
      if(!Pbvc_list.nullOrEmpty)
      {
      for(iter1 : Pbvc_list)
      {
      	fill_sd_details(iter1)
      }
      sd_Srgrp()
      
      if(SdInstance?.map[sdClientTimers].flatten.size > 0)
      {
      	Client_timer_count()
      }
      
     }
      sd_config_option()
     if(!Pbvc_list.nullOrEmpty)
     {
      for(iter1 : Pbvc_list)
      { 
        get_tcpip_domain_type_vp(iter1)
      }
     }
     else
     {
     	get_tcpip_domain_type()
     }

     /**
   * Design ID : SD_SDD_0360, SD_SDD_0055, SD_SDD_0030
   * Generates PreCompile Options in the output file.
   * @param None.
   * Returns Nothing
   */
     write('''
     /*  Pre-compile option for variant-support */
     #define «toMacroName('SdPreCompileSingle')»                      «stdOn(isPreCompile(module))»

     /* Pre-compile option for Error detection */
     #define «toMacroName('SdDevErrorDetect')»                        «stdOn(Sd_General?.sdDevErrorDetect.booleanValue)»

     /* Pre-compile option to check if Version Info API */
     #define «toMacroName('SdGetVersionInfo')»                        «stdOn(Sd_General?.sdVersionInfoApi.booleanValue)»
     /* Pre-compile option to check if Version  */
       #define «toMacroName('SdSubscribeEventgroupRetryEnable')»                        «stdOn(Sd_General?.sdSubscribeEventgroupRetryEnable.booleanValue)»
       
/* Pre-compile option to check if Version  */
	 #define «toMacroName('SdEnableAclPolicyCheck')»                «stdOn(Sd_General?.sdEnableAclPolicyCheck.booleanValue)»
	  
    /* Pre-compile option to check if SdSetRemAddrOfClientRxMulticastSoCon  */
    #define «toMacroName('SdSetRemAddrOfClientRxMulticastSoCon')»           «stdOn(Sd_General?.sdSetRemAddrOfClientRxMulticastSoCon?.booleanValue)»
     

	 
          /* Pre-compile option to check if Version  */	 
	 #define «toMacroName('SdEnableSecurityEventReporting')»        «stdOn(Sd_General?.sdEnableSecurityEventReporting.booleanValue)»
	 
	  «IF Sd_General?.sdEnableSecurityEventReporting.booleanValue == true »
	  #define SD_SEV_SOME_IP_ACL_CHECK_FAILED_OFFER                   «GetIdsmHandleId(1)»       
	  «ELSE»
	  /*#define SD_SEV_SOME_IP_ACL_CHECK_FAILED_OFFER             84U */
	  «ENDIF»
	  
	   «IF Sd_General?.sdEnableSecurityEventReporting.booleanValue == true »
	   #define SD_SEV_DUPLICATE_OFFER                                  «GetIdsmHandleId(2)»       
	   «ELSE»
	   /*#define SD_SEV_DUPLICATE_OFFER             88U */
	   «ENDIF»
	   
	   «IF Sd_General?.sdEnableSecurityEventReporting.booleanValue == true »
	   #define SD_SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION      «GetIdsmHandleId(3)»       
	  «ELSE»
	   /*#define SD_SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION             85U */
	  «ENDIF»
	     
	  «IF Sd_General?.sdEnableSecurityEventReporting.booleanValue == true »
	   #define SD_SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST          «GetIdsmHandleId(4)»       
	  «ELSE»
	   /*#define SD_SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST             86U */
	  «ENDIF»

     «IF stdOn(isPreCompile(module)) =="STD_OFF"»
     
     /* Pre-compile option for SdMainFunctionCycleTime  */
     #define SD_VAL_ZERO                               «"0x00U"»
     
     /* Pre-compile option for SdMainFunctionCycleTime  */
     #define SD_VAL_ONE                               «"0x01U"»
     
     /* Pre-compile option for SdMainFunctionCycleTime  */
     #define SD_SEC_TO_COUNT                               «(1000/Sd_Mainfunc_period_ms).intValue+"U"»

     «IF Sd_GInstances_arr.size != 0»
     /* Pre-compile option for Total Instances across all ConfigSets */
     #define SD_NO_OF_INSTANCES                               «Sd_GInstances_arr.size+"U"»
     «ENDIF»

     /* Pre-compile option for Sd no of Server Services */
     #define SD_NO_OF_SERVER_SERVICES                      «server_services_cnt.size+"U"»
     
     «IF(!module?.getPredefinedVariants.nullOrEmpty)»
     /* Pre-compile option for Sd no of Client services */
     #define SD_NO_OF_SERVER_SERVICES_PB                      «server_services_cnt.size * Pbvc_list.size +"U"»
     «ELSE»
     /* Pre-compile option for Sd no of Client services */
     #define SD_NO_OF_SERVER_SERVICES_PB                      «server_services_cnt.size +"U"»
     «ENDIF»
     
     /* Pre-compile option for Sd no of Server Services */
     #define SD_NO_OF_SERVER_SERVICE                      «module.sdConfig.sdInstances.map[sdServerServices?.map[sdServerServiceHandleId]]?.filterNull?.flatten?.size+"U"»

     /* Pre-compile option for Sd no of Handles */
     #define SD_NO_OF_EV_HANDLERS                          «event_handle_ids.size+"U"»

     /* Pre-compile option for Sd Queue size */
     #define SD_QUEUE_SIZE                                 «client_services_cnt.size+event_handle_ids.size+
     server_services_cnt.size+consumed_eve_grp_cnt.size+"U"»

     /* Pre-compile option for Sd no of Client services */
     #define SD_NO_OF_CLIENT_SERVICES                      «client_services_cnt.size+"U"»
     
     «IF(!module?.getPredefinedVariants.nullOrEmpty)»
     /* Pre-compile option for Sd no of Client services */
     #define SD_NO_OF_CLIENT_SERVICES_PB                      «client_services_cnt.size * Pbvc_list.size +"U"»
     «ELSE»
     /* Pre-compile option for Sd no of Client services */
     #define SD_NO_OF_CLIENT_SERVICES_PB                      «client_services_cnt.size +"U"»
     «ENDIF»
     
     /* Pre-compile option for Sd no of Consumed EV Group */
     #define SD_NO_OF_CONSUMED_EV_GRP                      «consumed_eve_grp_cnt.size+"U"»

     /* Pre-compile option for number of server timers */
     #define SD_NO_OF_SERVER_TIMERS                        «SdInstance.map[sdServerTimers].flatten.size+'U'»
     «IF (!module?.getPredefinedVariants.nullOrEmpty)»
     /* Pre-compile option for number of client timers */
     #define SD_NO_OF_CLIENT_TIMERS                  «client_timer_cnt_pb+'U'»     
     «ELSE»
     /* Pre-compile option for number of client timers */
     #define SD_NO_OF_CLIENT_TIMERS                  «client_timer_cnt+'U'»
     «ENDIF»
     /* Pre-compile option for no of socket groups */
     #define SD_NO_OF_SO_CON_GRPS                          «Soad_cnt_arr.size+'U'»

     /* Pre-compile option for Sd no of Socket connection */
     #define SD_NO_OF_SOCKET_CONNECTIONS                   «Soad_socket_cnt+'U'»
     
     /* Pre-compile option for Sd timer unused */
     #define SD_TIMER_UNUSED                               «0+'U'»
     «IF(!module?.getPredefinedVariants.nullOrEmpty)»
     #define SD_SERVICE_GROUP        «totalSdSerGrps.intValue+'U'»
      «ELSE»
      #define SD_SERVICE_GROUP        «module?.sdConfig?.sdServiceGroups_PB.size+'U'»
      «ENDIF»
      «IF(module?.getPredefinedVariants.nullOrEmpty)»
     #define SD_NO_OF_ALLOWED_CLIENT_PROVIDER   «SdInstance.map[sdClientServices.map[sdClientServiceAllowedProviders_PB]].flatten.flatten.size+'U'»
     #define SD_NO_OF_PROVIDED_SERVER_CONSUMER   «SdInstance.map[sdServerServices.map[sdServerServiceAllowedConsumerss_PB]].flatten.flatten.size+'U'»
     «ELSE»  
     #define SD_NO_OF_ALLOWED_CLIENT_PROVIDER   «cliserallprovs.intValue+'U'»
     #define SD_NO_OF_PROVIDED_SERVER_CONSUMER   «ServerSerallCons.intValue+'U'»
     «ENDIF»
     «IF Soad_client_con_ev_grp.size > 0»
     /* Pre-compile option for Sd no of Multicast Group */
     #define SD_MULTICAST_GRP_INDEX_CONFIGURED             STD_ON
     «ELSE»
     /* Pre-compile option for Sd no of Multicast Group */
     #define SD_MULTICAST_GRP_INDEX_CONFIGURED             STD_OFF
     «ENDIF»

     /* Pre-compile option for Sd no of multicast socket connection group */
     #define SD_NO_OF_MULTICAST_SO_CON_GRP                 «Soad_client_con_ev_grp.size+'U'»

     /* Pre-compile option for sd total size of config option */
     #define SD_TOTAL_SIZE_OF_CONFIG_OPTION                «config_opt_total_length+'U'»

     «IF tcpip_ipv6_support == 1»
     /* Pre-compile option for IPv6 */
     #define SD_IPV6_ENABLED                               STD_ON
     «ELSE»
     /* Pre-compile option for IPv6 */
     #define SD_IPV6_ENABLED                               STD_OFF
     «ENDIF»
     «ENDIF»

     /* Pre-compile option for if Consumed ev group is configured  is true */
     «IF consumed_eve_grp_cnt.size == 0»
     #define SD_CONSUMED_EV_GRP_CONFIGURED                 STD_OFF
     «ELSE»
     #define SD_CONSUMED_EV_GRP_CONFIGURED                 STD_ON
     «ENDIF»
     
     /* Pre-compile option to check if Client is configured */
          «IF module.sdConfig?.sdServiceGroups_PB?.size > 0»
          #define SD_SERVICE_GROUP_CONFIGURED     STD_ON
          «ELSE»
          #define SD_SERVICE_GROUP_CONFIGURED     STD_OFF
          «ENDIF»
          
     «IF module.sdConfig?.sdServiceGroups_PB?.size >0 »
      #define SD_CLIENT_REF_SERVICEGRP_CONFIGURED    «module.sdConfig.sdInstances.map[sdClientServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size+"U"»
     «ENDIF»
     «IF module.sdConfig?.sdServiceGroups_PB?.size >0 »
      #define SD_SERVER_REF_SERVICEGRP_CONFIGURED    «module.sdConfig.sdInstances.map[sdServerServices?.map[sdServiceGroupRefs_PB]?.filterNull]?.filterNull?.flatten?.flatten?.size+"U"»
     «ENDIF»
     
     /* Pre-compile option to check if Client is configured */
     «IF client_services_cnt.size == 0»
     #define SD_CLIENT_CONFIGURED                          STD_OFF
     «ELSE»
     #define SD_CLIENT_CONFIGURED                          STD_ON
     «ENDIF»

     /* Pre-compile option to check if Ev handler is configured */
     «IF event_handle_ids.size == 0»
     #define SD_EV_HANDLER_CONFIGURED                      STD_OFF
     «ELSE»
     #define SD_EV_HANDLER_CONFIGURED                      STD_ON
     «ENDIF»

     /* Pre-compile option to check if server is configured */
     «IF server_services_cnt.size == 0»
     #define SD_SERVER_CONFIGURED                          STD_OFF
     «ELSE»
     #define SD_SERVER_CONFIGURED                          STD_ON
     «ENDIF»
     /*Macro to define total No of variation point at module level*/
     
     #define SD_NUM_OF_CFG_SETS  «fetchConfigset()»U
          	
     
    ''')
   }
   
   override  writeConfigurationSetHandles() {
    super.writeConfigurationSetHandles
    write('''
    «module.generateConfigSetHandle»
    ''')
  }

def fetchConfigset()
{
  var count = 0

  if(!Pbvc_list.nullOrEmpty)
  {
    count = Pbvc_list.size
   }
   else
   {
   	count = 1
   }

return count

}
      override protected writeGlobalDataTypes() {
     super.writeGlobalDataTypes()
     write('''
     «get_sd_service_type()»
     «get_sd_time_type»
     «type_defs»

/* ServerTimer
 * This is an array which contains all the Server Service Timers.
  All delay fields are in counts. count = (time in sec) /
                                            (main function period in sec)
  All Fields are configurable as per note given in the Sd_TimeType*/
/* Design_ID : SD_SDD_0123*/
typedef struct
{
  /* This is the SdServerTimerTTL in seconds */
  uint32 ulServerTimerTtlsec;
  /* This is the SdServerTimerInitialOfferDelayMax in counts */
  Sd_TimeType ulInitialOfferDelayMax;
  /* This is the SdServerTimerInitialOfferDelayMin in counts */
  Sd_TimeType ulInitialOfferDelayMin;
  /* This is the SdServerTimerInitialFindRepetitionsBaseDelay in counts */
  Sd_TimeType ulInitialOfferRepetitionBaseDelay;
  Sd_TimeType ulTimerOfferCyclicDelay;
  /* This is the SdServerTimerRequestResponseMaxDelay in counts */
  Sd_TimeType ulRequestResponseMaxDelay;
  /* This is the SdServerTimerRequestResponseMinDelay in counts */
  Sd_TimeType ulRequestResponseMinDelay;
  /* This is the SdServerTimerInitialFindRepetitionsMax (uint8) */
  uint8 ucInitialOfferRepetitionsMax;
} Sd_ServerTimerStaticType;

/* Design_ID : SD_SDD_0452*/
typedef struct
{
	 /*SdServiceGroupHandleId */
	uint16 usHandleId;
	
}Sd_ServiceGroupType;

/* Client Timer 
   This is an array which contains all the Client Service Timers.
  Most fields are in counts. count = (time in sec) /
                                      (main function period in sec)
  All Fields are configurable as per note given in the Sd_TimeType*/

/* Design_ID : SD_SDD_0117*/
typedef struct STag_Sd_ClientTimerStaticType
{
    /* This is the SdClientTimerTTL in seconds */
  uint32 ulClientTimerTtlsec;
    /* This is the SdClientTimerInitialFindDelayMax in counts */
  Sd_TimeType ulInitialFindDelayMax;
    /* This is the SdClientTimerInitialFindDelayMin in counts */
  Sd_TimeType ulInitialFindDelayMin;
    /* This is the SdClientTimerInitialFindRepetitionsBaseDelay in counts */
  Sd_TimeType ulInitialFindRepetitionsBaseDelay;
    /* This is the SdClientTimerRequestResponseMaxDelay in counts */
  Sd_TimeType ulRequestResponseMaxDelay;
    /* This is the SdClientTimerRequestResponseMinDelay in counts */
  Sd_TimeType ulRequestResponseMinDelay;
    /* This is the SdClientTimerInitialFindRepetitionsMax (uint8) */
  uint8 ucInitialFindRepetitionsMax;
  
  /* This is the SdSubscribeEventgroupRetryDelay in counts */
  Sd_TimeType ulSubscribeEventgroupRetryDelay;
  
 /* This is the SdSubscribeEventgroupRetryMax */
     uint8 ucSubscribeEventgroupRetryMax;
     
} Sd_ClientTimerStaticType;

/* SocketConnectionGroup
 * This is the SocketConnectionGroup Structure
  It contains all socketConnectiongroups referred to in all structures above */
/* Design_ID : SD_SDD_0127*/
typedef struct
{
    /* This is the base Id of the SocketConnection array. */
  SoAd_SoConIdType usBaseSocketConIndex;
    /* This is the no of sockets of the SocketConnection array. */
  uint16 usNoOfSockets;
} Sd_SoConGroupStaticType;


/* Instance Structure Static
 * Instance structure for static parameters */

/* Design_ID : SD_SDD_0123*/
typedef struct STag_Sd_InstanceStaticType
{
    /* This is pointer to the Configuration String containing hostname.
     * NULL if absent. */
  const uint8 * pConfigOption;
    /* Base Server Services Index (for Static and Dynamic arrays) */
  Sd_ServicesType usBaseServerServiceIndex;
    /* No of Server Sevices for this instance. */
  Sd_ServicesType usNoOfServerServices;
    /* Base Client Services Index (For Static and Dynamic arrays) */
  Sd_ServicesType usBaseClientServiceIndex;
    /* No of Client Services for this instance. */
  Sd_ServicesType usNoOfClientServices;
    /* The Tx PDU Id for this instance . Retrieved from SoAd -> SoAdPduRoute ->
     * SoAdTxPduId  that is matching with  SdTxPduRef*/
  PduIdType ddTxPduId;
    /* The Unicast Rx PduID for this instance  */
  PduIdType ddUnicastRxPduId;
    /* The Multicast RxPduId for this instance.  */
  PduIdType ddMulticastRxPduId;
    /* This is the SoConID that is used to check against the
     * Sd_LocalIpAddrAssignmentChg for this instance.  This SoConId is
     * referenced from the SoAdPduRoute -> SoAdTxPduRef, which has the same
     * value as SdInstanceTxPdu-> SdTxPduRef.
     * The value of the SoConId will be derived from SoAdPduRoute ->
     * SoAdPduRouteDest -> SoAdTxSocketConnOrSocketConnBundleRef.
     * If it is a group reference, the first SoConId in that group is
     * considered, else the SoCon is directly written.*/
  SoAd_SoConIdType ddIpAddrSoConId;
    /* Note - SoConId or SoConGrp needs to be generated here as per [00482] for
     * reception of message
     Pending Discussion. */
    /* Unicast SoConId derived as per [00482]  Pending Discussion */
  SoAd_SoConIdType ddRxUnicastSoConId;
    /* Multicast SoConId derived as per [00482]  Pending */
  SoAd_SoConIdType ddRxMulticastSoConId;
    /* This is the Dem ID of the error SD_E_MALFORMED_MSG, if not configured it
     * will have the value SD_DEM_INVALID*/
  uint16 usDemErrorMalformedId;
    /* This is the Dem ID of the error SD_E_OUT_OF_RES if not configured it
     * will have the value SD_DEM_INVALID */
  uint16 usDemErrorOutOfResId;
   /* Reference to the DemEventParameter which shall be issued when
    * receiving SubscribeEventgroupNack entry.*/
  uint16 usDemErrorSubEventgroupNackId;
    /* This is the self index for the instance */
  Sd_ServicesType ucInstanceSelfIndex;
  /* This is TRUE if domain is IPv4 and false if it is IPv6
    It is determined from the TCPIP domains of all the socketConnection Groups
    and PDU's associated with this instance. They must all be same */
  boolean blDomainIpv4;
  /*This item describes on how many bits of the addresses shall be compared to determine,
    if a remote address is acceptable to be used.
    This shall support IPv4 (0..32) and IPv6 (0..128).
    If this item is not present, the security checks use the configured netmask instead.
    "0" meaning not to check at all. For example "8" means that the first 8 bits of a remote
    address must be equal to the local address to be considered acceptable.*/
    uint16  usSdInstanceLocalAdressCheckLength;
} Sd_InstanceStaticType;

/* This is the Server Service Static Flag */
/* Design_ID : SD_SDD_0125*/
typedef struct STag_Sd_ServerStaticFlagType
{
    /* This is (1) if SdServerServiceAutoAvailable is TRUE else (0) */
  unsigned int blAutoAvaliable : 1;
    /*  This is (1) if SdServerServiceActivationRef is present else (0) */
  unsigned int blActivationRoGrpIdPresent : 1;
    /* Reserved */
  unsigned int ucReserved : 6;
} Sd_ServerStaticFlagType;
/*Service Group static */



/* Server Service Static
 * This is the structure for the Static parameters for the Server
  This is an array ordered as per configurations and then as per Instances.
*/

/* Design_ID : SD_SDD_0124*/
typedef  struct STag_Sd_ServerServiceStaticType
{
      /* This is the Minor Version for this Server Service. */
    uint32 ulMinorVersion;
      /* Reference Id of the SocketConnectionGroup Structure for TCP. NULL if
       * not present */
    const Sd_SoConGroupStaticType * pTcpSoConGrp;
      /* Reference Id of the SocketConnectionGroup Structure for UDP. NULL if
       * not present */
    const Sd_SoConGroupStaticType * pUdpSoConGrp;
      /* Reference to the Server Timer */
    const Sd_ServerTimerStaticType * pServerTimer;
      /* This is pointer to the assembled Configuration option string. NULL if
       * absent. */
    const uint8 * pConfigOption;
      /* This is the Handle Id for the Server Service. */
    uint16 usHandleId;
      /* This is the Service ID for this Server Service. */
    uint16 usServiceId;
      /* This is Instance ID of the server service */
    uint16 usInstanceId;
      /* This is the Index of the key of the OtherServ option in the
       * ConfigurationOption array.  If OtherServ key is not present,
       * this is set as Zero */
    uint16 usOtherServKeyIndex;
      /* This is the Length of the the OtherServ key in the
       * ConfigurationOption array.  If OtherServ key is not present,
       * this is set as Zero */
    uint16 usOtherServKeyLength;
      /* This is the Routing Group ID  that is referred to in
       * SdServerServiceActivationRef in SdProvidedMethods */
    SoAd_RoutingGroupIdType ddActivationRoGrpId;
      /* The Base event handler index which is used by this server service */
    Sd_ServicesType usBaseEvHandlerIndex;
      /* No of Event Handlers registered to this server service.*/
    Sd_ServicesType usNoOfEvHandlers;
      /* This gives the index of the current element in the Server Service
       * array (Self Index)*/
    Sd_ServicesType usServerSelfIndex;
      /* This is the reference to the SdInstance for this ServerService */
    uint8 ucSdInstanceIndex;
      /* This is the Major Version for this ServerService. */
    uint8 ucMajorVersion;
      /* This is the flag for Server Static structure. (description below) */
    Sd_ServerStaticFlagType stServerStaticFlag;
    
	/*Sd_Service_grp_ref*/
	const Sd_ServiceGroupType * pServiceGroupRef;
	
    «IF SdInstance?.head?.sdServerServices?.head?.sdServerServiceLoadBalancingWeight_PB?.size > 0  »
    /*usServerServiceLoadBalancingWeight*/
    uint32 usSdServerServiceLoadBalancingWeight;
    «ENDIF»
    «IF SdInstance?.head?.sdServerServices.head?.sdServerServiceLoadBalancingPriority_PB?.size > 0  »	
    /*usServerServiceLoadBalancingPriority*/
    uint32 usServerServiceLoadBalancingPriority;
    «ENDIF»
  
    
} Sd_ServerServiceStaticType;



/* This is the Event Handler Static Flag */
/* Design_ID : SD_SDD_0121*/
typedef struct STag_Sd_EvHandlerStaticFlagType
{
    /* This is TRUE if SdEventTriggeringRef in SdEventHandlerUdp is present */
  unsigned int blUdpTriggeringRoGrpIdPresent :1;
    /* This is TRUE if SdEventActivationRef in SdEventHandlerUdp is present */
  unsigned int blUdpActivationRoGrpIdPresent :1;
    /* This is TRUE if SdEventTriggeringRef in SdEventHandlerTcp is present */
  unsigned int blTcpTriggeringRoGrpIdPresent :1;
    /* This is TRUE if SdEventActivationRef in SdEventHandlerTcp is present */
  unsigned int blTcpActivationRoGrpIdPresent :1;
    /* This is TRUE if SdEventActivationRef in SdEventHandlerMulticast is
     * present */
  unsigned int blMulticastActivationRoGrpIdPresent :1;
    /* This is TRUE if SdMulticastEventSoConRef in SdEventHandlerMulticast
      is present */
  unsigned int blMulticastEventSoConPresent :1;
    /* Reserved */
  unsigned int ucReserved :2;
} Sd_EvHandlerStaticFlagType;


/* Event Handler Type Static
 * Array of structures ordered by Server Service.
  size is the total no of EvHandlers across all instances and all
  configurations */
/* Design_ID : SD_SDD_0122*/
typedef struct STag_Sd_EvHandlerStaticType
{
    /* Reference to Server Timer */
  const Sd_ServerTimerStaticType * pServerTimer;
    /* This is pointer to the assembled Configuration option string. NULL if
     * absent. */
  const uint8 * pConfigOption;
    /* This is the SdEventHandlerHandleId */
  uint16 usHandleId;
    /* This is the SdEventHandlerEventGroupId */
  uint16 usEventGroupId;
    /* This is the SdEventHandlerMulticastThreshold */
  uint16 usMulticastThreshold;
    /* This is the Index of the key of the OtherServ option in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyIndex;
    /* This is the Length of the the OtherServ key in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyLength;
    /* This is the Routing Group Id mentioned in SdEventHandlerUdp ->
     * SdEventTriggeringRef */
  SoAd_RoutingGroupIdType ddUdpTriggeringRoGrpId;
    /* This is the Routing Group Id mentioned in SdEventHandlerUdp ->
     * SdEventActivationRef */
  SoAd_RoutingGroupIdType ddUdpActivationRoGrpId;
    /* This is the Routing Group Id mentioned in SdEventHandlerTcp ->
     * SdEventTriggeringRef */
  SoAd_RoutingGroupIdType ddTcpTriggeringRoGrpId;
    /* This is the Routing Group Id mentioned in SdEventHandlerTcp ->
     * SdEventActivationRef */
  SoAd_RoutingGroupIdType ddTcpActivationRoGrpId;
    /* This is the Routing Group Id mentioned in SdEventHandlerMulticast ->
     * SdEventActivationRef */
  SoAd_RoutingGroupIdType ddMulticastActivationRoGrpId;
    /* This is the Socket Connection ID referred to in
            SdEventHandlerMulticast -> SdMulticastEventSoConRef */
  SoAd_SoConIdType ddMulticastEventSoConId;
    /* Index of the Reference to Server Service */
  Sd_ServicesType usServerServiceIndex;
    /* This gives the index of the current element in the Event Handler array
     * (Self Index)*/
  Sd_ServicesType usEvHandlerSelfIndex;
    /* This is the flag for the Event Handler */
  Sd_EvHandlerStaticFlagType stEvHandlerStaticFlag;
} Sd_EvHandlerStaticType;



/* This is the flag for the Client service static */
/* Design_ID : SD_SDD_0115*/
typedef struct STag_Sd_ClientServiceStaticFlagType
{
    /* This is (1) if  SdClientServiceAutoRequire is TRUE else (0) */
  unsigned int blAutoRequire :1;
    /* This is (1) if SdClientServiceActivationRef in SdConsumedMethods is
     * configured else (0) */
  unsigned int blActivationRoGrpIdPresent : 1;
    /* Reserved */
  unsigned int ucReserved :6;
} Sd_ClientServiceStaticFlagType;
/*SdVersionDrivenFindBehavior enumerationtype*/
typedef enum ETag_Sd_VersionDrivenFindBehavior
{
	SD_EXACT_OR_ANY_MINOR_VERSION = 0,
	SD_MINIMUM_MINOR_VERSION
}Sd_VersionDrivenFindBehaviorType;

/* Client Service Static
 * This contains the static parameters for client service */
/* Design_ID : SD_SDD_0116*/
typedef struct STag_Sd_ClientServiceStaticType
{
    /* This is the Handle Id for the Client Service*/
   uint16 usHandleId;
    /* This is the Service ID for the Client Service */
  uint16 usServiceId;
    /* This is the Instance ID for the Client Service */
  uint16 usInstanceId;
    /* This is the Major Version for the Client Service. */
  uint8 ucMajorVersion;
    /* This is the Minor Version for the Client Service */
  uint32 ulMinorVersion;

    /* Reference Id of the SocketConnectionGroup Structure for TCP. NULL if no
     * present */
  const Sd_SoConGroupStaticType * pTcpSoConGrp;
    /* Reference Id of the SocketConnectionGroup Structure for UDP. NULL if not
     * present */
  const Sd_SoConGroupStaticType * pUdpSoConGrp;
    /* Reference to the Client Timer */
  const Sd_ClientTimerStaticType * pClientTimer;
    /* This is pointer to the assembled Configuration option string. NULL if
     * absent. */
  const uint8 * pConfigOption;
    /* This is the Index of the key of the OtherServ option in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyIndex;
    /* This is the Length of the the OtherServ key in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyLength;
    /* This is the base Consumed Event Group for this Client Service */
  Sd_ServicesType usBaseConEventGrp;
    /* This is the no of Consumed Event Groups for this Client Service */
  Sd_ServicesType usNoOfConEventGrp;
    /* This gives the index of the current element in the Client Service array
    (Self Index)*/
  Sd_ServicesType usClientSelfIndex;
    /* This is the Routing Group ID  that is referred to in
     * SdClientServiceActivationRef in SdConsumedMethods */
  SoAd_RoutingGroupIdType ddActivationRoGrpId;
    /* This is the reference to the SdInstance for this ServerService */
  uint8 ucSdInstanceIndex;
    /* Flag for Client Service Static */
  Sd_ClientServiceStaticFlagType stClientStaticFlag;
  /* Version driver behaviour */
  Sd_VersionDrivenFindBehaviorType EndrivenBehaviour;
  
  /*Sd_Service_Group_Ref*/
  const Sd_ServiceGroupType * pServiceGroupRef;
  
  uint16 SdBlacklistedMinorVersions;
  
 
} Sd_ClientServiceStaticType;


/* This is the flag for consumed event group static parameters */
/* Design_ID : SD_SDD_0119*/
typedef struct STag_Sd_ConsumedEvGrpStaticFlagType
{
    /* This is set to (1) if SdConsumedEventGroupAutoRequire is TRUE else (0) */
  unsigned int blAutoRequire :1;
    /* This is TRUE if SdConsumedEventGroupMulticastActivationRef is present */
  unsigned int blMulticastActivationRoGrpIdPresent :1;
    /* This is TRUE if SdConsumedEventGroupTcpActivationRef is present */
  unsigned int blTcpActivationRoGrpIdPresent :1;
    /* This is TRUE if SdConsumedEventGroupUdpActivationRef is present */
  unsigned int blUdpActivationRoGrpIdPresent :1;
    /* Reserved */
  unsigned int ucReserved:4;
} Sd_ConsumedEvGrpStaticFlagType;




/* Consumed Event Group Static
   This is the structure to hold the consumed event group static constants
 It is an array of size the total no of consumed event groups .
It is indexed according to the Sd_ClientServiceStaticType structure */
/* Design_ID : SD_SDD_0120*/
/* Design_ID : SD_SDD_0010*/
typedef struct STag_Sd_ConsumedEvGrpStaticType
{
    /* This is pointer to the assembled Configuration option string. NULL if
     * absent. */
  const uint8 * pConfigOption;
    /* Reference to the Client Timer */
  const Sd_ClientTimerStaticType * pClientTimer;
    /* This is the Handle Id for the Consumed Event Grp */
  uint16 usHandleId;
    /* This is the Event Group ID as configured */
  uint16 usEventGroupId;
    /* This is the Index of the key of the OtherServ option in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyIndex;
    /* This is the Length of the the OtherServ key in the
     * ConfigurationOption array.  If OtherServ key is not present,
     * this is set as Zero */
  uint16 usOtherServKeyLength;
    /* This is the Routing Group Id mentioned in
     * SdConsumedEventGroupMulticastActivationRef */
  SoAd_RoutingGroupIdType ddMulticastActivationRoGrpId;
    /* This is the Routing Group Id mentioned in
     * SdConsumedEventGroupTcpActivationRef */
  SoAd_RoutingGroupIdType ddTcpActivationRoGrpId;
    /* This is the Routing Group Id mentioned in
     * SdConsumedEventGroupUdpActivationRef */
  SoAd_RoutingGroupIdType ddUdpActivationRoGrpId;
    /* This is the base index of the first SoConGrp refeerred by
     * SdConsumedEventGroupMulticastGroupRef */
  SoAd_SoConIdType ddBaseMulticastSoConGrpIndex;
    /* This is the number of SdConsumedEventGroupMulticastGroupRef */
  SoAd_SoConIdType ddNoOfMulticastSoConGrp;
    /* This is the Client Service Index for this Consumed Event Group */
  Sd_ServicesType usClientServiceIndex;
    /* This gives the index of the current element in the Consumed Event
     * Group array (Self Index)*/
  Sd_ServicesType usConEvGrpSelfIndex;
    /* This field is generated if multiple Consumed event groups in the same
     * ClientService have the same EventGroupId. For the first one, it is
     * generated as 0, for the second as 1, and so on.  This counter has a
     * range from 0 to 15*/
  uint8 ucCounter;
    /* Flag for the Consumed Event Group */
  Sd_ConsumedEvGrpStaticFlagType stConsumedEvGrpStaticFlag;
} Sd_ConsumedEvGrpStaticType;



/* Design_ID : SD_SDD_0453*/
typedef struct STag_Sd_ServicegroupClientArrayType
{
  
  uint16 usArray_size;
    /* This is the Event Group ID as configured */
 
 
} Sd_ServicegroupClientArrayType;
/* Design_ID : SD_SDD_0454*/
typedef struct STag_Sd_ServicegroupServerArrayType
{
  
  uint16 usArray_size;
    /* This is the Event Group ID as configured */
 
 
} Sd_ServicegroupServerArrayType;

«IF (module?.sdGeneral?.sdEnableAclPolicyCheck) == true»
typedef enum ETag_Sd_IpAddressType
{
	SD_AF_INET = 2,
	SD_AF_INET6 = 28 
	
}Sd_IpAddressType;
/*Design_ID :*/

typedef struct STag_Sd_ProviderConsumerList
{
	Sd_IpAddressType domain;

	uint8 SdIpAddress[18];
	
}Sd_ProviderConsumerListType;

/*typedef struct STag_Sd_ServerServiceAllowedConsumer
{
	Sd_IpAddressType domain;
	uint8 SdIpAddress[18];
	
}Sd_ServerServiceAllowedConsumerType;*/

«ELSE»
typedef enum ETag_Sd_IpAddressType
{
		SD_AF_INET = 2,
		SD_AF_INET6 = 28,
		SD_WILDCARD_DOMAIN = 0, 
		
}Sd_IpAddressType;
	
typedef enum ETag_Sd_ProviderConsumerType
{    
	SD_CONSUMER_TYPE,
	SD_PROVIDER_TYPE,
	SD_ANY_TYPE
	
}Sd_ProviderConsumerType;

typedef struct STag_Sd_ProviderConsumerList
{
	uint16 usServiceId;
	
	Sd_ProviderConsumerType ListMemberType;
	
	Sd_IpAddressType domain;

	uint8 SdIpAddress[18];
	
}Sd_ProviderConsumerListType;

«ENDIF»

  ''')
     }
     
def Client_timer_count()
{
 if(!Pbvc_list.nullOrEmpty)
  {
  for(iter1:Pbvc_list)
  {
  for (sd_inst : module.sdConfig.sdInstances){
     var client_timer_arr_pb = get_client_Timer_ids_map()
     var client_timer_arr = client_timer_arr_pb?.get(iter1?.shortName) 
     for (itr : 0..< client_timer_arr.size){
     for (client_timers : sd_inst?.sdClientTimers){
     if (client_timer_arr.get(itr).equals((client_timers.shortNamePath).toString)){
     	client_timer_cnt_pb++
     }
   }
  }
 }
}
}
return client_timer_cnt_pb
}
def Server_timer_count()
{
 if(!Pbvc_list.nullOrEmpty)
  {
  for(iter1:Pbvc_list)
  {
  for (sd_inst : module.sdConfig.sdInstances){
     var server_timer_arr_pb = get_server_Timer_ids_map()
     var server_timer_arr = server_timer_arr_pb?.get(iter1?.shortName) 
     for (itr : 0..< server_timer_arr.size)
     {
     for (server_timers : sd_inst?.sdServerServices)
     {
     if (server_timer_arr.get(itr).equals((server_timers.shortNamePath).toString))
     {
     	server_timer_cnt_vp++
     }
    }
   }
  }
 }
}
return server_timer_cnt_vp
}

def GetIdsmHandleId(Integer HandleID) {
  
  if(Sd_General.sdSecurityEventRefs !== null) 
  {
  	if((Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_OFFER !== null) && (HandleID == 1))
  	{
  		return "IdsMConf_IdsMEvent_"+Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_OFFER.shortName;
  	}
  	else if (HandleID == 1)
  	{
  		return '84U';
  	}
    else if((Sd_General.sdSecurityEventRefs.SEV_SOME_IP_SD_DUPLICATE_OFFER !== null) && (HandleID == 2))
  	{
  		return "IdsMConf_IdsMEvent_"+Sd_General.sdSecurityEventRefs.SEV_SOME_IP_SD_DUPLICATE_OFFER.shortName;
  	}
  	else if (HandleID == 2)
  	{
  		return '88U';
  	}
    else if((Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION !== null) && (HandleID == 3))
  	{
  		return "IdsMConf_IdsMEvent_"+Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION.shortName;
  	}
  	else if (HandleID == 3)
  	{
  		return '85U';
  	}
    else if((Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST !== null) && (HandleID == 4))
  	{
  		return "IdsMConf_IdsMEvent_"+Sd_General.sdSecurityEventRefs.SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST.shortName ;
  	}
  	else if (HandleID == 4)
  	{
  		return '86U';
  	}

  	else
  	{
  		
  	}
  }
  else if (HandleID == 1)
  {
  	return '84U';
  }
  else if (HandleID == 2)
  {
    return '88U';
  }
  else if (HandleID == 3)
  {
    return '85U';
  }
  else if (HandleID == 4)
  {
    return '86U';
  }   
  
  }
  def sd_Srgrp()
  {
  	val pdvs = findModule(EcuC)?.ecucPostBuildVariants?.ecucPostBuildVariantRefs
  	
    for(iter1 : pdvs)
    {
    	
    for(sd_sergrps : SdServiceGroup?.filterVariant(iter1, module?.sdConfig.toString))
     {
     	if(!(SerGrp_handle_ids.contains(sd_sergrps.shortName)))
     	{
     		SerGrp_handle_ids.add(sd_sergrps?.shortName)
        }
     }
     totalSdSerGrps += filterVariant(SdServiceGroup, iter1, module?.sdConfig?.toString)?.toSet?.size
     	
    }
    
     
  }
   def fill_sd_details(PredefinedVariant iter1)
   {
     //client_soc_congrp_arr = new ArrayList<String>
     client_services_cnt = new ArrayList<String>
     var server_handle_ids_ = new ArrayList<Integer>()
     var client_handle_ids_ = new ArrayList<Integer>()
     var act_client_routing_grp_ = new HashMap<String, String>()
     var act_server_routing_grp_ = new HashMap<String, String>()
     var client_Timer_ids_ = new ArrayList<String>()
     var server_Timer_ids_ = new ArrayList<SdServerTimer>()
     var server_Timer_ids_snp = new ArrayList<String>()
     var con_eve_grp_handle_ids_ = new ArrayList<Integer>()
     var con_eve_grp_Timer_ids_ = new ArrayList<String>()
     var inst_uni_multicast_rx_pdu_ = new ArrayList<Integer>()
     var act_consumed_eve_routing_grp_ = new HashMap<String, String>()
     var sd_con_eve_tcp_ref_arr_ = new HashMap<String, String>()
     var sd_con_eve_udp_ref_arr_ = new HashMap<String, String>()
     var act_eve_handler_udp_routing_grp_ = new HashMap<String, String>()
     var act_eve_handler_tcp_routing_grp_ = new HashMap<String, String>()
     var sd_eve_handler_tcp_ref_arr_ = new HashMap<String, String>()
     var sd_eve_handler_udp_ref_arr_ = new HashMap<String, String>()
     var act_eve_handler_routing_grp_ = new HashMap<String, String>()
     var sd_eve_handler_multi_soc_con_ = new HashMap<String, String>()
     var base = 0
     count = 0
     
     for(sd_inst : SdInstance)
     {
       
       val inst_path = sd_inst?.shortNamePath?.toString
       con_eve_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
      
       Sd_GInstances_arr.add(inst_path)
       
     /*   if(sd_inst.sdInstanceLocalAdressCheckLength_PB.filterVariant(iter1,sd_inst.toString).head !== null)
       { Sd_GInstances_arr.add(inst_path)}*/
       inst_uni_multicast_rx_pdu.add(sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue)
       inst_uni_multicast_rx_pdu.add(sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue)
       inst_uni_multicast_rx_pdu_.add(sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue)
       inst_uni_multicast_rx_pdu_.add(sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.filterVariant(iter1,sd_inst.toString)?.head?.integerValue)
       inst_uni_multicast_rx_pdu_map.put(iter1?.shortName,inst_uni_multicast_rx_pdu_ )
       for(cl_service : sd_inst?.sdClientServices)
       {
         val client_service_path = cl_service?.shortNamePath?.toString
         client_services_cnt.add(cl_service?.shortNamePath?.toString)
         client_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>
      
  
         for(cl_service_timer : cl_service?.sdClientServiceTimerRef_PB?.filterVariant(iter1,sd_inst.toString))
         {
           
           if(!(client_Timer_ids_.contains((cl_service_timer.reference.shortNamePath)?.toString)))
           {
             //client_timer_cnt = client_timer_cnt + 1
             client_Timer_ids_.add((cl_service_timer.reference.shortNamePath)?.toString)
             
           }
           if(!(client_timer_arr.contains((cl_service_timer.reference.shortNamePath)?.toString)))
           {
             client_timer_cnt = client_timer_cnt + 1
             client_timer_arr.add((cl_service_timer.reference.shortNamePath)?.toString)
           }
           
          
         }
         client_timer.put(iter1.shortName, client_timer_cnt)
         
         
         for (consumed_ev : cl_service?.sdConsumedEventGroups)
         {
           for(consumed_ev_timer : consumed_ev?.sdConsumedEventGroupTimerRef_PB?.filterVariant(iter1,sd_inst.toString))
           {
            if(!(client_timer_arr.contains((consumed_ev_timer.reference.shortNamePath)?.toString)))
            {
             client_timer_cnt = client_timer_cnt + 1
             client_timer_arr.add((consumed_ev_timer .reference.shortNamePath)?.toString)
            }
            if(!(client_Timer_ids_.contains((consumed_ev_timer.reference.shortNamePath)?.toString)))
            {
             client_Timer_ids_.add((consumed_ev_timer.reference.shortNamePath)?.toString)
            }
           }
           
         }
        client_Timer_ids_map.put(iter1.shortName, client_Timer_ids_)
         for(Service_Group:cl_service?.sdServiceGroupRefs_PB?.filterVariant(iter1,sd_inst.toString)?.filterNull )
         {
         	  if(!(client_Sgrp_arr.contains((Service_Group.reference.shortNamePath)?.toString)))
            {
             service_grp_cnt0 = service_grp_cnt0 + 1
             client_Sgrp_arr.add((Service_Group.reference.shortNamePath)?.toString)
            }
         	
         }

         for(cl_serv_caprecords : cl_service?.sdClientCapabilityRecords)
         {
           var client_serv_path = cl_serv_caprecords?.shortNamePath?.toString
           client_serv_path = client_serv_path?.substring(0, client_serv_path.lastIndexOf("/"))
           client_cap_rec?.put("ClientServiceCapabilityRecordKey", cl_serv_caprecords?.
           	sdClientServiceCapabilityRecordKey
           )
           client_cap_rec?.put("ClientServiceCapabilityRecordValue", cl_serv_caprecords?.
           	sdClientServiceCapabilityRecordValue?.toString
           )
           client_capability_rec_final?.put(cl_serv_caprecords?.shortNamePath?.toString, client_cap_rec)
           client_cap_rec_list.add(client_capability_rec_final)
           client_cap_rec = new HashMap<String, String>
           client_capability_rec_final = new HashMap<String, HashMap<String, String>>
           
           
        }
         if(client_cap_rec_list.size > 0)
         {
          client_service_hash.put(client_service_path, client_cap_rec_list)
          client_service_list.add(client_service_hash)
          client_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
         }
        for(cl_servTcpRef : cl_service?.sdClientServiceTcpRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
        {
          sd_client_tcp_ref = cl_servTcpRef?.reference?.shortNamePath
          if((client_soc_congrp_arr.contains(sd_client_tcp_ref?.toString)) == false)
          {
            client_soc_congrp_arr.add(sd_client_tcp_ref?.toString)
          }
          for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
          {
            if(sokcon?.shortNamePath?.toString.equals(sd_client_tcp_ref?.toString))
            {
             if((Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString)) == false)
             {
               Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
               sokcon?.soAdSocketConnections?.forEach
               [
                 Soad_socket_cnt = Soad_socket_cnt + 1
               ]
             }
           }
         }
       }
       for(cl_servUdpRef : cl_service?.sdClientServiceUdpRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
       {
         sd_client_udp_ref = cl_servUdpRef?.reference?.shortNamePath
         if((client_soc_congrp_arr.contains(sd_client_udp_ref?.toString)) == false)
         {
           client_soc_congrp_arr.add(sd_client_udp_ref?.toString)
         }
         for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
         {
           if(sokcon?.shortNamePath?.toString.equals(sd_client_udp_ref?.toString))
           {
             if(Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString) == false)
             {
               Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
               sokcon?.soAdSocketConnections?.forEach
               [
                 Soad_socket_cnt = Soad_socket_cnt + 1
               ]
             }
           }
         }
       }
       val clserallprov = cl_service?.sdClientServiceAllowedProviders_PB
       clientserallowprovs = cl_service?.sdClientServiceAllowedProviders_PB
       cliserallprovs += filterVariant(clserallprov, iter1, sd_inst.toString)?.toSet?.size
       consumed_eve_grp_list = new ArrayList<HashMap<String, Integer>>
       for(conevegrp : cl_service?.sdConsumedEventGroups)
       {
         con_eve_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>
         val conev_path = conevegrp?.shortNamePath?.toString
         
         consumed_eve_grp_cnt.add(conevegrp?.shortNamePath?.toString)
         con_eve_grp_handle_ids.add(conevegrp?.sdConsumedEventGroupHandleId)
         con_eve_grp_handle_ids_.add(conevegrp?.sdConsumedEventGroupHandleId)
  
           if(con_eve_cap_rec_list.size > 0)
          {
           con_eve_cl_serv_hash.put(conev_path, con_eve_cap_rec_list)
           con_eve_grp_list.add(con_eve_cl_serv_hash)
           con_eve_cl_serv_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
          }
          consumedevegrphash.put(conevegrp?.shortNamePath?.toString, conevegrp?.sdConsumedEventGroupId.intValue)
          consumed_eve_grp_list.add(consumedevegrphash)
          consumedevegrphash = new HashMap<String, Integer>()

          
        for(conevegrpMA : conevegrp?.sdConsumedEventGroupMulticastActivationRef_PB?.filterVariant(iter1,sd_inst.toString))
        {  	
        if(conevegrpMA?.reference?.shortNamePath?.toString != null)
        {
              act_consumed_eve_routing_grp.put(conev_path, conevegrpMA?.reference?.shortNamePath?.toString)
              act_consumed_eve_routing_grp_.put(conev_path, conevegrpMA?.reference?.shortNamePath?.toString)
        }
        }
        for(conevegrpTA : conevegrp?.sdConsumedEventGroupTcpActivationRef_PB?.filterVariant(iter1,sd_inst.toString))
        {	
          if(conevegrpTA?.reference?.shortNamePath?.toString != null)
          {
              sd_con_eve_tcp_ref_arr.put(conev_path, conevegrpTA?.reference?.shortNamePath?.toString)
              sd_con_eve_tcp_ref_arr_.put(conev_path, conevegrpTA?.reference?.shortNamePath?.toString)
          }
         }
         for(conevegrpUA : conevegrp?.sdConsumedEventGroupUdpActivationRef_PB?.filterVariant(iter1,sd_inst.toString))
         {
          if(conevegrpUA?.reference?.shortNamePath?.toString != null)
           {
              sd_con_eve_udp_ref_arr.put(conev_path, conevegrpUA?.reference?.shortNamePath?.toString)
              sd_con_eve_udp_ref_arr_.put(conev_path, conevegrpUA?.reference?.shortNamePath?.toString)
           }
         }
          con_ev_grp_ref = new ArrayList<String>()
          if(!(conevegrp?.sdConsumedEventGroupMulticastGroupRefs_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
          {
            for(multigrp : conevegrp?.sdConsumedEventGroupMulticastGroupRefs_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
            {
        if(multigrp?.reference?.shortNamePath?.toString != null)
        {
                con_ev_grp_ref.add(multigrp?.reference?.shortNamePath?.toString)
                  
                sd_client_con_ev_grp_ref = multigrp?.reference?.shortNamePath

                if((client_soc_congrp_arr.contains((multigrp?.reference?.shortNamePath)?.toString) == false))
                {
                  client_soc_congrp_arr.add((multigrp?.reference?.shortNamePath)?.toString)
                }
                 
                for(sokcongrp : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
                {
                  if(sokcongrp?.shortNamePath?.toString.equals(sd_client_con_ev_grp_ref?.toString))
                  {
                    if(Soad_cnt_arr.contains(sokcongrp?.shortNamePath?.toString) == false)
                    {
                      Soad_cnt_arr.add(sokcongrp?.shortNamePath?.toString)
                      sokcongrp?.soAdSocketConnections?.forEach
                      [
                      Soad_socket_cnt = Soad_socket_cnt + 1
                      ]
                    }
                    Soad_client_con_ev_grp.add(sokcongrp?.shortNamePath?.toString)
                  }
                }
        }
            }
          }
      if(con_ev_grp_ref.size > 0)
      {
        sd_conevgrp_sokbaseid_hash.put(base, con_ev_grp_ref)
        
        base = base + con_ev_grp_ref.size
      sd_client_con_ev_grp_ref_hash.put(conev_path, sd_conevgrp_sokbaseid_hash)
      sd_conevgrp_sokbaseid_hash = new HashMap<Integer, ArrayList<String>>
      }
        }
        consumed_eve_grp_id_hash.put(client_service_path, consumed_eve_grp_list)
    if(!(cl_service?.sdConsumedMethods?.sdClientServiceActivationRef_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
    {
          for(cl_serv_actref : cl_service?.sdConsumedMethods?.sdClientServiceActivationRef_PB?.filterVariant(iter1,sd_inst.toString))
          {
            act_client_routing_grp.put(client_service_path, cl_serv_actref?.reference?.shortNamePath?.toString)
            act_client_routing_grp_.put(client_service_path, cl_serv_actref?.reference?.shortNamePath?.toString)
          }
    }
        client_handle_ids.add(cl_service?.sdClientServiceHandleId)
        client_handle_ids_.add(cl_service?.sdClientServiceHandleId)
      }
    if(client_service_list.size > 0)
    {
      sort_client_service_hash.put(count, client_service_list)
      client_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
    }
      if(con_eve_grp_list.size > 0)
    {
      sort_con_eve_hash.put(count, con_eve_grp_list)
        con_eve_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
    }
       
       for(serv : sd_inst?.sdServerServices.sortBy[sdServerServiceHandleId])
       {
          var server_service_path = serv?.shortNamePath?.toString
          server_handle_ids_.add(serv?.sdServerServiceHandleId)
          
          server_services_cnt.add(serv?.shortNamePath?.toString)
         server_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>

         for(serv_timer : serv?.sdServerServiceTimerRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
         {
           
           if(!(server_timer_arr.contains((serv_timer?.reference.shortNamePath)?.toString)))
           {
             server_timer_arr.add((serv_timer?.reference.shortNamePath)?.toString)
           }
           if(!(server_Timer_ids_snp.contains((serv_timer?.reference.shortNamePath)?.toString)))
           {
             server_Timer_ids_snp.add((serv_timer?.reference.shortNamePath)?.toString)
           }          
           if(!(server_timer_arr1.contains((serv_timer?.reference))))
           {
             server_timer_arr1.add((serv_timer?.reference))
           }
           if(!(server_Timer_ids_.contains((serv_timer?.reference))))
           {
             server_Timer_ids_.add((serv_timer?.reference))
           }
           Sd_server_timer.put(iter1.toString, serv_timer?.reference.shortName)
           server_Timer_ids_map.put(iter1.shortName, server_Timer_ids_)
           
      	   
           for(eventhandler : serv?.sdEventHandlers)
           {
              for(ev_timer : eventhandler?.sdEventHandlerTimerRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
              {
                if(!(server_timer_arr.contains((ev_timer?.reference.shortNamePath)?.toString)))
               {
                 server_timer_arr.add((ev_timer?.reference.shortNamePath)?.toString)
               }
               if(!(server_Timer_ids_snp.contains((serv_timer?.reference.shortNamePath)?.toString)))
               {
                 server_Timer_ids_snp.add((serv_timer?.reference.shortNamePath)?.toString)
               }
             }
           }
           
          }
          server_Timer_ids_map1.put(iter1.shortName, server_Timer_ids_snp)
       for(Service_Group:serv?.sdServiceGroupRefs_PB?.filterVariant(iter1,sd_inst.toString)?.filterNull )
         {
         	if(!(server_Sgrp_arr.contains((Service_Group.reference.shortNamePath)?.toString)))
            {
             service_grp_cnt1 = service_grp_cnt1 + 1
             server_Sgrp_arr.add((Service_Group.reference.shortNamePath)?.toString)
            }
         	
         }
    
         for(server_caprecored : serv?.sdServerCapabilityRecords)
         {
           var server_serv_path = server_caprecored?.shortNamePath?.toString
           server_serv_path = server_serv_path?.substring(0, server_serv_path.lastIndexOf("/"))
           server_cap_rec?.put("ServerServiceCapabilityRecordKey", server_caprecored?.sdServerCapabilityRecordKey)
           server_cap_rec?.put("ServerServiceCapabilityRecordValue", server_caprecored?.
           	sdServerCapabilityRecordValue?.toString
           )
           server_capability_rec_final?.put(server_caprecored?.shortNamePath?.toString, server_cap_rec)
           server_cap_rec_list.add(server_capability_rec_final)
           server_cap_rec = new HashMap<String, String>
           server_capability_rec_final = new HashMap<String, HashMap<String, String>>

         }
     if(server_cap_rec_list.size > 0)
     {
           server_service_hash.put(server_service_path, server_cap_rec_list)
       server_service_list.add(server_service_hash)
         server_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
     }
        
         for(ev_hand : serv?.sdEventHandlers)
         {
           eve_handler_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>
           event_handle_ids.add(ev_hand?.sdEventHandlerHandleId)
           val eve_handler_path = ev_hand?.shortNamePath?.toString
           eve_handler_cnt.add(ev_hand?.shortNamePath?.toString)
           eve_handler_handle_ids.add(ev_hand?.sdEventHandlerHandleId)

       if(eve_handler_cap_rec_list.size > 0)
       {
             eve_handler_grp_hash.put(eve_handler_path, eve_handler_cap_rec_list)
         eve_handler_grp_list.add(eve_handler_grp_hash)
             eve_handler_grp_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
           }
           if(ev_hand?.sdEventHandlerUdp != null)
           {
           	for(ev_hand1 : ev_hand?.sdEventHandlerUdp?.sdEventTriggeringRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
            if(ev_hand1 != null)
            {
            	act_eve_handler_udp_routing_grp.put(eve_handler_path, ev_hand1?.reference?.shortNamePath?.toString)
                act_eve_handler_udp_routing_grp_.put(eve_handler_path, ev_hand1?.reference?.shortNamePath?.toString)
            }
            
           }
           }
            if(ev_hand?.sdEventHandlerTcp != null)
           {
           for(ev_hand2 : ev_hand?.sdEventHandlerTcp?.sdEventTriggeringRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
            act_eve_handler_tcp_routing_grp.put(eve_handler_path, ev_hand2?.reference?.shortNamePath?.toString)
            act_eve_handler_tcp_routing_grp_.put(eve_handler_path, ev_hand2?.reference?.shortNamePath?.toString)
           }
          
           for(ev_hand3 : ev_hand?.sdEventHandlerTcp?.sdEventActivationRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
             sd_eve_handler_tcp_ref_arr.put(eve_handler_path, ev_hand3?.reference?.shortNamePath?.toString)
             sd_eve_handler_tcp_ref_arr_.put(eve_handler_path, ev_hand3?.reference?.shortNamePath?.toString)
           }
           }
           if(ev_hand?.sdEventHandlerUdp != null)
           {
           for(ev_hand4 : ev_hand?.sdEventHandlerUdp?.sdEventActivationRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
             sd_eve_handler_udp_ref_arr.put(eve_handler_path, ev_hand4?.reference?.shortNamePath?.toString)
             sd_eve_handler_udp_ref_arr_.put(eve_handler_path, ev_hand4?.reference?.shortNamePath?.toString)
           }
           
           }
           if(ev_hand?.sdEventHandlerMulticast != null)
           {  
           for(ev_hand5 : ev_hand?.sdEventHandlerMulticast?.sdEventActivationRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
            
             act_eve_handler_routing_grp.put(eve_handler_path, ev_hand5?.reference?.shortNamePath?.toString)
             act_eve_handler_routing_grp_.put(eve_handler_path, ev_hand5?.reference?.shortNamePath?.toString)
           }
           for(ev_hand6 : ev_hand?.sdEventHandlerMulticast?.sdMulticastEventSoConRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
           {
            sd_eve_handler_multi_soc_con.put(eve_handler_path, ev_hand6?.reference?.shortNamePath?.toString)
            sd_eve_handler_multi_soc_con_.put(eve_handler_path, ev_hand6?.reference?.shortNamePath?.toString)
           }
           
           }
         }
              
     
     for(ser_servTcpRef : serv?.sdServerServiceTcpRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
         {
           sd_serv_tcp_ref = ser_servTcpRef?.reference?.shortNamePath
           server_service_arr.add((ser_servTcpRef?.reference?.shortNamePath)?.toString)
           for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
            {
              if(sokcon?.shortNamePath?.toString.equals(sd_serv_tcp_ref?.toString))
              {
                if((Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString)) == false)
                {
                  Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
                  sokcon?.soAdSocketConnections?.forEach
                  [
                    Soad_socket_cnt = Soad_socket_cnt + 1
                  ]
                }
              }
            }
          }
         for(ser_servUdpRef : serv?.sdServerServiceUdpRef_PB?.filterVariant(iter1,sd_inst.toString)?.toList)
         {
            sd_serv_udp_ref = ser_servUdpRef?.reference?.shortNamePath
            server_service_arr.add((ser_servUdpRef?.reference?.shortNamePath)?.toString)
            for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
            {
              if(sokcon?.shortNamePath?.toString.equals(sd_serv_udp_ref?.toString))
              {
                if(Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString) == false)
                {
                  Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
                  sokcon?.soAdSocketConnections?.forEach
                  [
                     Soad_socket_cnt = Soad_socket_cnt + 1
                  ]
               }
             }
           }
         }
         if(!(serv?.sdProvidedMethods?.sdServerServiceActivationRef_PB?.filterVariant(iter1,sd_inst.toString).nullOrEmpty))
         {
           for(serv_actref : serv?.sdProvidedMethods?.sdServerServiceActivationRef_PB?.filterVariant(iter1,sd_inst.toString))
           {
             act_server_routing_grp.put(server_service_path , serv_actref?.reference?.shortNamePath?.toString)
             act_server_routing_grp_.put(server_service_path , serv_actref?.reference?.shortNamePath?.toString)
           }
         }
         
         server_handle_ids.add(serv?.sdServerServiceHandleId)
         
         if(!serv?.sdServerServiceAllowedConsumerss_PB.nullOrEmpty)
        {
       val ServerSerallprov =  serv?.sdServerServiceAllowedConsumerss_PB       
       ServerSerallCons += filterVariant(ServerSerallprov, iter1, sd_inst.toString)?.toSet?.size	
       }
       }
       
     if(eve_handler_grp_list.size > 0)
     {
         sort_eve_handler_hash.put(count, eve_handler_grp_list)
         eve_handler_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
     }
     if(server_service_list.size > 0)
     {
         sort_server_service_hash.put(count, server_service_list)
       server_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
     }
       count = count + 1
     }
     server_handle_ids_map.put(iter1.shortName, server_handle_ids_)
     client_handle_ids_map.put(iter1.shortName, client_handle_ids_)
     con_eve_grp_handle_ids_map.put(iter1.shortName, con_eve_grp_handle_ids_)
     act_client_routing_grp_map.put(iter1.shortName, act_client_routing_grp_)
     act_server_routing_grp_map.put(iter1.shortName, act_server_routing_grp_)
     act_consumed_eve_routing_grp_map.put(iter1.shortName, act_consumed_eve_routing_grp_)
     sd_con_eve_tcp_ref_arr_map.put(iter1.shortName, sd_con_eve_tcp_ref_arr_)
     sd_con_eve_udp_ref_arr_map.put(iter1.shortName, sd_con_eve_udp_ref_arr_)
     act_eve_handler_udp_routing_grp_map.put(iter1.shortName, act_eve_handler_udp_routing_grp_)
    
     act_eve_handler_tcp_routing_grp_map.put(iter1.shortName, act_eve_handler_tcp_routing_grp_)
     sd_eve_handler_tcp_ref_arr_map.put(iter1.shortName, sd_eve_handler_tcp_ref_arr_)
     sd_eve_handler_udp_ref_arr_map.put(iter1.shortName, sd_eve_handler_udp_ref_arr_)
     
     act_eve_handler_routing_grp_map.put(iter1.shortName, act_eve_handler_routing_grp_)
     sd_eve_handler_multi_soc_con_map.put(iter1.shortName, sd_eve_handler_multi_soc_con_)
  }   
     
   def fill_sd_detailsNoVp()
   {
   	client_soc_congrp_arr = new ArrayList<String>
     client_services_cnt = new ArrayList<String>
 
     var base = 0
     count = 0
   	for(sd_inst : SdInstance)
     {
      val inst_path = sd_inst?.shortNamePath?.toString
       con_eve_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>

       Sd_GInstances_arr.add(inst_path)
       inst_uni_multicast_rx_pdu.add(sd_inst?.sdInstanceMulticastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
       inst_uni_multicast_rx_pdu.add(sd_inst?.sdInstanceUnicastRxPdu?.sdRxPduId_PB?.get(0)?.integerValue)
       for(cl_service : sd_inst?.sdClientServices)
       {
         val client_service_path = cl_service?.shortNamePath?.toString
         client_services_cnt.add(cl_service?.shortNamePath?.toString)
         client_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>

         for(cl_service_timer : cl_service?.sdClientServiceTimerRef_PB)
         {
           if(!(client_timer_arr.contains((cl_service_timer.reference.shortNamePath)?.toString)))
           {
             client_timer_cnt = client_timer_cnt + 1
             
             client_timer_arr.add((cl_service_timer.reference.shortNamePath)?.toString)
           }
         }
         
         
         for (consumed_ev : cl_service?.sdConsumedEventGroups)
         {
           for(consumed_ev_timer : consumed_ev?.sdConsumedEventGroupTimerRef_PB)
           {
            if(!(client_timer_arr.contains((consumed_ev_timer.reference.shortNamePath)?.toString)))
            {
             client_timer_cnt = client_timer_cnt + 1
             client_timer_arr.add((consumed_ev_timer .reference.shortNamePath)?.toString)
            }
           }
         }
        
         for(Service_Group:cl_service?.sdServiceGroupRefs_PB?.filterNull )
         {
         	  if(!(client_Sgrp_arr.contains((Service_Group.reference.shortNamePath)?.toString)))
            {
             service_grp_cnt0 = service_grp_cnt0 + 1
             client_Sgrp_arr.add((Service_Group.reference.shortNamePath)?.toString)
            }
         	
         }

         for(cl_serv_caprecords : cl_service?.sdClientCapabilityRecords)
         {
           var client_serv_path = cl_serv_caprecords?.shortNamePath?.toString
           client_serv_path = client_serv_path?.substring(0, client_serv_path.lastIndexOf("/"))
           client_cap_rec?.put("ClientServiceCapabilityRecordKey", cl_serv_caprecords?.
           	sdClientServiceCapabilityRecordKey
           )
           client_cap_rec?.put("ClientServiceCapabilityRecordValue", cl_serv_caprecords?.
           	sdClientServiceCapabilityRecordValue?.toString
           )
           client_capability_rec_final?.put(cl_serv_caprecords?.shortNamePath?.toString, client_cap_rec)
           client_cap_rec_list.add(client_capability_rec_final)
           client_cap_rec = new HashMap<String, String>
           client_capability_rec_final = new HashMap<String, HashMap<String, String>>
           
           
        }
    if(client_cap_rec_list.size > 0)
    {
      client_service_hash.put(client_service_path, client_cap_rec_list)
        client_service_list.add(client_service_hash)
        client_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
    }
        for(cl_servTcpRef : cl_service?.sdClientServiceTcpRef_PB?.toList)
        {
          sd_client_tcp_ref = cl_servTcpRef?.reference?.shortNamePath
          if((client_soc_congrp_arr.contains(sd_client_tcp_ref?.toString)) == false)
          {
            client_soc_congrp_arr.add(sd_client_tcp_ref?.toString)
          }
          for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
          {
            if(sokcon?.shortNamePath?.toString.equals(sd_client_tcp_ref?.toString))
            {
             if((Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString)) == false)
             {
               Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
               sokcon?.soAdSocketConnections?.forEach
               [
                 Soad_socket_cnt = Soad_socket_cnt + 1
               ]
             }
           }
         }
       }
       for(cl_servUdpRef : cl_service?.sdClientServiceUdpRef_PB?.toList)
       {
         sd_client_udp_ref = cl_servUdpRef?.reference?.shortNamePath
         if((client_soc_congrp_arr.contains(sd_client_udp_ref?.toString)) == false)
         {
           client_soc_congrp_arr.add(sd_client_udp_ref?.toString)
         }
         for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
         {
           if(sokcon?.shortNamePath?.toString.equals(sd_client_udp_ref?.toString))
           {
             if(Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString) == false)
             {
               Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
               sokcon?.soAdSocketConnections?.forEach
               [
                 Soad_socket_cnt = Soad_socket_cnt + 1
               ]
             }
           }
         }
       }
       

       consumed_eve_grp_list = new ArrayList<HashMap<String, Integer>>
       for(conevegrp : cl_service?.sdConsumedEventGroups)
       {
         con_eve_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>
         val conev_path = conevegrp?.shortNamePath?.toString
         consumed_eve_grp_cnt.add(conevegrp?.shortNamePath?.toString)
         con_eve_grp_handle_ids.add(conevegrp?.sdConsumedEventGroupHandleId)
  
     if(con_eve_cap_rec_list.size > 0)
     {
           con_eve_cl_serv_hash.put(conev_path, con_eve_cap_rec_list)
           con_eve_grp_list.add(con_eve_cl_serv_hash)
       con_eve_cl_serv_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
     }
          consumedevegrphash.put(conevegrp?.shortNamePath?.toString, conevegrp?.sdConsumedEventGroupId.intValue)
          consumed_eve_grp_list.add(consumedevegrphash)
      consumedevegrphash = new HashMap<String, Integer>()

          conevegrp?.sdConsumedEventGroupMulticastActivationRef_PB?.forEach
          [
        if(it?.reference?.shortNamePath?.toString != null)
      {
              act_consumed_eve_routing_grp.put(conev_path, it?.reference?.shortNamePath?.toString)
      }
          ]
          conevegrp?.sdConsumedEventGroupTcpActivationRef_PB?.forEach
          [
        if(it?.reference?.shortNamePath?.toString != null)
      {
              sd_con_eve_tcp_ref_arr.put(conev_path, it?.reference?.shortNamePath?.toString)
      }
          ]

          conevegrp?.sdConsumedEventGroupUdpActivationRef_PB?.forEach
          [
        if(it?.reference?.shortNamePath?.toString != null)
        {
              sd_con_eve_udp_ref_arr.put(conev_path, it?.reference?.shortNamePath?.toString)
      }
          ]
      con_ev_grp_ref = new ArrayList<String>()
          if(!(conevegrp?.sdConsumedEventGroupMulticastGroupRefs_PB.nullOrEmpty))
          {
            for(multigrp : conevegrp?.sdConsumedEventGroupMulticastGroupRefs_PB?.toList)
            {
        if(multigrp?.reference?.shortNamePath?.toString != null)
        {
                con_ev_grp_ref.add(multigrp?.reference?.shortNamePath?.toString)

                sd_client_con_ev_grp_ref = multigrp?.reference?.shortNamePath

                if((client_soc_congrp_arr.contains((multigrp?.reference?.shortNamePath)?.toString) == false))
                {
                  client_soc_congrp_arr.add((multigrp?.reference?.shortNamePath)?.toString)
                }
                for(sokcongrp : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
                {
                  if(sokcongrp?.shortNamePath?.toString.equals(sd_client_con_ev_grp_ref?.toString))
                  {
                    if(Soad_cnt_arr.contains(sokcongrp?.shortNamePath?.toString) == false)
                    {
                      Soad_cnt_arr.add(sokcongrp?.shortNamePath?.toString)
                      sokcongrp?.soAdSocketConnections?.forEach
                      [
                      Soad_socket_cnt = Soad_socket_cnt + 1
                      ]
                    }
                    Soad_client_con_ev_grp.add(sokcongrp?.shortNamePath?.toString)
                  }
                }
        }
            }
          }
      if(con_ev_grp_ref.size > 0)
      {
        sd_conevgrp_sokbaseid_hash.put(base, con_ev_grp_ref)
        base = base + con_ev_grp_ref.size
      sd_client_con_ev_grp_ref_hash.put(conev_path, sd_conevgrp_sokbaseid_hash)
      sd_conevgrp_sokbaseid_hash = new HashMap<Integer, ArrayList<String>>
      }
        }
        consumed_eve_grp_id_hash.put(client_service_path, consumed_eve_grp_list)
    if(!(cl_service?.sdConsumedMethods?.sdClientServiceActivationRef_PB.nullOrEmpty))
    {
          for(cl_serv_actref : cl_service?.sdConsumedMethods?.sdClientServiceActivationRef_PB)
          {
            act_client_routing_grp.put(client_service_path, cl_serv_actref?.reference?.shortNamePath?.toString)
          }
    }
        client_handle_ids.add(cl_service?.sdClientServiceHandleId)
      }
    if(client_service_list.size > 0)
    {
      sort_client_service_hash.put(count, client_service_list)
      client_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
    }
      if(con_eve_grp_list.size > 0)
    {
      sort_con_eve_hash.put(count, con_eve_grp_list)
        con_eve_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
    }
       for(serv : sd_inst?.sdServerServices)
       {
          var server_service_path = serv?.shortNamePath?.toString
          server_services_cnt.add(serv?.shortNamePath?.toString)
         server_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>

         for(serv_timer : serv?.sdServerServiceTimerRef_PB)
         {
           if(!(server_timer_arr.contains((serv_timer?.reference.shortNamePath)?.toString)))
           {
             server_timer_arr.add((serv_timer?.reference.shortNamePath)?.toString)
           }
                      
           if(!(server_timer_arr1.contains((serv_timer?.reference))))
           {
             server_timer_arr1.add((serv_timer?.reference))
           }
         

           for(eventhandler : serv?.sdEventHandlers)
           {
              for(ev_timer : eventhandler?.sdEventHandlerTimerRef_PB?.toList)
              {
                if(!(server_timer_arr.contains((ev_timer?.reference.shortNamePath)?.toString)))
               {
                 server_timer_arr.add((ev_timer?.reference.shortNamePath)?.toString)
               }
             }
           }
          }
          
       for(Service_Group:serv?.sdServiceGroupRefs_PB?.filterNull )
         {
         	  if(!(server_Sgrp_arr.contains((Service_Group.reference.shortNamePath)?.toString)))
            {
             service_grp_cnt1 = service_grp_cnt1 + 1
             server_Sgrp_arr.add((Service_Group.reference.shortNamePath)?.toString)
            }
         	
         }
    
         for(server_caprecored : serv?.sdServerCapabilityRecords)
         {
           var server_serv_path = server_caprecored?.shortNamePath?.toString
           server_serv_path = server_serv_path?.substring(0, server_serv_path.lastIndexOf("/"))
           server_cap_rec?.put("ServerServiceCapabilityRecordKey", server_caprecored?.sdServerCapabilityRecordKey)
           server_cap_rec?.put("ServerServiceCapabilityRecordValue", server_caprecored?.
           	sdServerCapabilityRecordValue?.toString
           )
           server_capability_rec_final?.put(server_caprecored?.shortNamePath?.toString, server_cap_rec)
           server_cap_rec_list.add(server_capability_rec_final)
           server_cap_rec = new HashMap<String, String>
           server_capability_rec_final = new HashMap<String, HashMap<String, String>>

         }
     if(server_cap_rec_list.size > 0)
     {
           server_service_hash.put(server_service_path, server_cap_rec_list)
       server_service_list.add(server_service_hash)
         server_service_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
     }
 
         for(ev_hand : serv?.sdEventHandlers)
         {
           eve_handler_cap_rec_list = new ArrayList<HashMap<String, HashMap<String, String>>>
           event_handle_ids.add(ev_hand?.sdEventHandlerHandleId)
           val eve_handler_path = ev_hand?.shortNamePath?.toString
           eve_handler_cnt.add(ev_hand?.shortNamePath?.toString)
           eve_handler_handle_ids.add(ev_hand?.sdEventHandlerHandleId)

       if(eve_handler_cap_rec_list.size > 0)
       {
             eve_handler_grp_hash.put(eve_handler_path, eve_handler_cap_rec_list)
         eve_handler_grp_list.add(eve_handler_grp_hash)
             eve_handler_grp_hash = new HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>
           }
           ev_hand?.sdEventHandlerUdp?.sdEventTriggeringRef_PB?.forEach
           [
             act_eve_handler_udp_routing_grp.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
           ev_hand?.sdEventHandlerTcp?.sdEventTriggeringRef_PB?.forEach
           [
              act_eve_handler_tcp_routing_grp.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
           ev_hand?.sdEventHandlerTcp?.sdEventActivationRef_PB?.forEach
           [
             sd_eve_handler_tcp_ref_arr.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
           ev_hand?.sdEventHandlerUdp?.sdEventActivationRef_PB?.forEach
           [
             sd_eve_handler_udp_ref_arr.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
           ev_hand?.sdEventHandlerMulticast?.sdEventActivationRef_PB?.forEach
           [
             act_eve_handler_routing_grp.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
           ev_hand?.sdEventHandlerMulticast?.sdMulticastEventSoConRef_PB?.forEach
           [
             sd_eve_handler_multi_soc_con.put(eve_handler_path, it?.reference?.shortNamePath?.toString)
           ]
         }

     for(ser_servTcpRef : serv?.sdServerServiceTcpRef_PB?.toList)
         {
           sd_serv_tcp_ref = ser_servTcpRef?.reference?.shortNamePath
           server_service_arr.add((ser_servTcpRef?.reference?.shortNamePath)?.toString)
           for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
            {
              if(sokcon?.shortNamePath?.toString.equals(sd_serv_tcp_ref?.toString))
              {
                if((Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString)) == false)
                {
                  Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
                  sokcon?.soAdSocketConnections?.forEach
                  [
                    Soad_socket_cnt = Soad_socket_cnt + 1
                  ]
                }
              }
            }
          }
         for(ser_servUdpRef : serv?.sdServerServiceUdpRef_PB?.toList)
         {
            sd_serv_udp_ref = ser_servUdpRef?.reference?.shortNamePath
            server_service_arr.add((ser_servUdpRef?.reference?.shortNamePath)?.toString)
            for(sokcon : _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
            {
              if(sokcon?.shortNamePath?.toString.equals(sd_serv_udp_ref?.toString))
              {
                if(Soad_cnt_arr.contains(sokcon?.shortNamePath?.toString) == false)
                {
                  Soad_cnt_arr.add(sokcon?.shortNamePath?.toString)
                  sokcon?.soAdSocketConnections?.forEach
                  [
                     Soad_socket_cnt = Soad_socket_cnt + 1
                  ]
               }
             }
           }
         }
         if(!(serv?.sdProvidedMethods?.sdServerServiceActivationRef_PB.nullOrEmpty))
         {
           for(serv_actref : serv?.sdProvidedMethods?.sdServerServiceActivationRef_PB)
           {
             act_server_routing_grp.put(server_service_path , serv_actref?.reference?.shortNamePath?.toString)
           }
         }
         server_handle_ids.add(serv?.sdServerServiceHandleId)
       }
     if(eve_handler_grp_list.size > 0)
     {
         sort_eve_handler_hash.put(count, eve_handler_grp_list)
         eve_handler_grp_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
     }
     if(server_service_list.size > 0)
     {
         sort_server_service_hash.put(count, server_service_list)
       server_service_list = new ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String, String>>>>>
     }
       count = count + 1
     }
   }

   def get_tcpip_domain_type()
   {
     tcpip_ipv6_support = 0

     _tcpip?.tcpIpConfig?.tcpIpLocalAddrs?.forEach
     [
       val tcpip_localadr = it?.shortNamePath
       it?.tcpIpDomainType_PB?.forEach
       [
         val tcpip_domain_type = it
         for(soad_con_grps: _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
         {
           if(Soad_cnt_arr.contains(soad_con_grps.shortNamePath?.toString))
           {
             for(soad_loc_adr : soad_con_grps?.soAdSocketLocalAddressRef_PB)
             {
               if((soad_loc_adr?.reference?.shortNamePath != null && tcpip_localadr != null) &&
               (soad_loc_adr?.reference?.shortNamePath?.toString == tcpip_localadr?.toString))
               {
                  for(inst: SdInstance)
           {
             for(iter1: inst?.sdClientServices)
             {
                for(iter2: iter1?.sdClientServiceTcpRef_PB?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2?.reference?.shortNamePath?.toString))
                 {
                  domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference.soAdSocketLocalAddressRef_PB.head.reference.
                    tcpIpDomainType_PB.head.toString
                  )
                 }
                }
                for(iter2: iter1?.sdClientServiceUdpRef_PB?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2?.reference?.shortNamePath?.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference?.soAdSocketLocalAddressRef_PB?.head?.reference?.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
                for(iter2: iter1?.sdConsumedEventGroups)
                {
                  for(iter3 : iter2.sdConsumedEventGroupMulticastGroupRefs_PB?.toList)
                  {
                    if(Soad_cnt_arr.contains(iter3?.reference?.shortNamePath?.toString))
                   {
                   domain_type_hash.put(inst.shortNamePath.toString,
                      iter3.reference?.soAdSocketLocalAddressRef_PB?.head?.reference.
                      tcpIpDomainType_PB?.head?.toString
                    )
                   }
                 }
                }
             }
             for(iter1: inst?.sdServerServices)
             {
                for(iter2: iter1?.sdServerServiceTcpRef_PB?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2.reference?.shortNamePath.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference?.soAdSocketLocalAddressRef_PB?.head?.reference.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
                for(iter2: iter1?.sdServerServiceUdpRef_PB?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2.reference?.shortNamePath?.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference.soAdSocketLocalAddressRef_PB?.head?.reference?.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
             }
           }
                 if(tcpip_domain_type?.enumValue?.toString.equals('TCPIP_AF_INET6') && tcpip_ipv6_support == 0)
                 {
                   tcpip_ipv6_support = 1
                 }
               }
             }
           }
         }
       ]
     ]
   }
   
def get_tcpip_domain_type_vp(PredefinedVariant pdv)
   {
     val domain_type_hash = new HashMap<String, String>()
     tcpip_ipv6_support = 0

     _tcpip?.tcpIpConfig?.tcpIpLocalAddrs?.forEach
     [
       val tcpip_localadr = it?.shortNamePath
       it?.tcpIpDomainType_PB?.forEach
       [
         val tcpip_domain_type = it
         for(soad_con_grps: _Soad?.soAdConfig?.soAdSocketConnectionGroups?.sortBy[it?.soAdSocketConnections?.head.soAdSocketId])
         {
           if(Soad_cnt_arr.contains(soad_con_grps.shortNamePath?.toString))
           {
             
             for(soad_loc_adr : soad_con_grps?.soAdSocketLocalAddressRef_PB)
             {
               
               if((soad_loc_adr?.reference?.shortNamePath != null && tcpip_localadr != null) &&
               (soad_loc_adr?.reference?.shortNamePath?.toString == tcpip_localadr?.toString))
               {
                  for(inst: SdInstance)
           {
             for(iter1: inst?.sdClientServices)
             {
                for(iter2: iter1?.sdClientServiceTcpRef_PB?.filterVariant(pdv,inst.toString)?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2?.reference?.shortNamePath?.toString))
                 {
                  domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference.soAdSocketLocalAddressRef_PB.head.reference.
                    tcpIpDomainType_PB.head.toString
                  )
                  
                 }
                }
                for(iter2: iter1?.sdClientServiceUdpRef_PB?.filterVariant(pdv,inst.toString)?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2?.reference?.shortNamePath?.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference?.soAdSocketLocalAddressRef_PB?.head?.reference?.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
                for(iter2: iter1?.sdConsumedEventGroups)
                {
                  for(iter3 : iter2.sdConsumedEventGroupMulticastGroupRefs_PB?.filterVariant(pdv,inst.toString)?.toList)
                  {
                    if(Soad_cnt_arr.contains(iter3?.reference?.shortNamePath?.toString))
                   {
                   domain_type_hash.put(inst.shortNamePath.toString,
                      iter3.reference?.soAdSocketLocalAddressRef_PB?.head?.reference.
                      tcpIpDomainType_PB?.head?.toString
                    )
                   }
                 }
                }
             }
             for(iter1: inst?.sdServerServices)
             {
                for(iter2: iter1?.sdServerServiceTcpRef_PB?.filterVariant(pdv,inst.toString)?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2.reference?.shortNamePath.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference?.soAdSocketLocalAddressRef_PB?.head?.reference.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
                for(iter2: iter1?.sdServerServiceUdpRef_PB?.filterVariant(pdv,inst.toString)?.toList)
                {
                  if(Soad_cnt_arr.contains(iter2.reference?.shortNamePath?.toString))
                 {
                 domain_type_hash.put(inst.shortNamePath.toString,
                    iter2.reference.soAdSocketLocalAddressRef_PB?.head?.reference?.
                    tcpIpDomainType_PB?.head?.toString
                  )
                 }
                }
             }
           }
                 if(tcpip_domain_type?.enumValue?.toString.equals('TCPIP_AF_INET6') && tcpip_ipv6_support == 0)
                 {
                   tcpip_ipv6_support = 1
                 }
               }
             }
           }
         }
       ]
     ]
     domain_type_hash_map.put(pdv.shortName,domain_type_hash)
   }
   def get_sd_service_type()
   {
     val total_size = consumed_eve_grp_cnt.size+client_services_cnt.size+
     event_handle_ids.size+server_services_cnt.size+Sd_GInstances_arr.size
     /* Design ID : SD_SDD_0362, SD_SDD_0361 */
     if(total_size <= 255)
     {
       "typedef uint8 Sd_ServicesType;"
     }
     else if(total_size >= 255 && total_size <= 65535)
     {
       "typedef uint16 Sd_ServicesType;"
     }
     else if(total_size > 65535)
     {
       "typedef uint32 Sd_ServicesType;"
     }
   }
   
   
   
   def get_sd_time_type()
   {
     SdInstance?.forEach
     [
       it?.sdServerTimers?.forEach
       [
         it?.sdServerTimerInitialOfferDelayMax_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdServerTimerInitialOfferDelayMin_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdServerTimerInitialOfferRepetitionBaseDelay_PB?.forEach
         [
           if(it != null)
           {
              time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdServerTimerInitialOfferRepetitionsMax_PB?.forEach
         [
           if(it != null)
           {
             if(it.integerValue != null)
             {
             time_type_arr.add(it.integerValue.doubleValue)
             }
           }
         ]
         it?.sdServerTimerOfferCyclicDelay_PB?.forEach
         [
            if(it != null)
            {
               time_type_arr.add(it.floatValue)
            }
         ]
         it?.sdServerTimerRequestResponseMaxDelay_PB?.forEach
         [
            if(it != null)
            {
               time_type_arr.add(it.floatValue)
            }
         ]
         it?.sdServerTimerRequestResponseMinDelay_PB?.forEach
         [
            if(it != null)
            {
               time_type_arr.add(it.floatValue)
            }
         ]
         it?.sdServerTimerTTL_PB?.forEach
         [
            if(it !=null)
            {
               time_type_arr.add(it.integerValue.doubleValue)
            }
         ]
       ]
       it?.sdClientTimers.forEach
       [
         it?.sdClientTimerInitialFindDelayMax_PB?.forEach
         [
           if(it != null)
           {
              time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdClientTimerInitialFindDelayMin_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdClientTimerInitialFindRepetitionsBaseDelay_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdClientTimerInitialFindRepetitionsMax_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.integerValue.doubleValue)
           }
         ]
         it?.sdClientTimerRequestResponseMaxDelay_PB?.forEach
         [
           if(it != null)
           {
              time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdClientTimerRequestResponseMinDelay_PB?.forEach
         [
           if(it !== null)
           {
             time_type_arr.add(it.floatValue)
           }
         ]
         it?.sdClientTimerTTL_PB?.forEach
         [
           if(it != null)
           {
             time_type_arr.add(it.integerValue.doubleValue)
           }
         ]
       ]
     ]
     time_type_arr.forEach
     [  /* Design ID : SD_SDD_0364 */
        type_defs = "typedef uint16 Sd_TimeType;"
        var sdMainFunctionCycleTime = (65535 *module.sdGeneral.sdMainFunctionCycleTime)

        if(it >= sdMainFunctionCycleTime)
        {
          /* Design ID : SD_SDD_0363 */
          type_defs = "typedef uint32 Sd_TimeType;"
        }
      ]
    }
  def void sd_config_option()
  {
    /*To sort the instances */
    var sort_client_service_hash = new TreeMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String,
    HashMap<String, String>>>>>>(sort_client_service_hash)
    var sort_server_service_hash  = new TreeMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String,
    HashMap<String, String>>>>>>(sort_server_service_hash)
    var sort_con_eve_hash = new TreeMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String, HashMap<String,
    String>>>>>>(sort_con_eve_hash)
    var sort_eve_handler_hash = new TreeMap<Integer, ArrayList<HashMap<String, ArrayList<HashMap<String,
    HashMap<String, String>>>>>>(sort_eve_handler_hash)
    sd_hst_name_length = 0
    config_opt_serv_cap_rec = new ArrayList<Object>
    config_opt_eve_handler = new ArrayList<Object>
    config_opt_client_cap_rec = new ArrayList<Object>
    config_opt_consumed_eve = new ArrayList<Object>
    config_opt_sd_inst_hstname = new ArrayList<Object>
    other_servevals = new HashMap<String, Integer>()
    other_serve_main_hash = new HashMap<String, HashMap<String, Integer>>()
    rec_cnt = 0
    index = 0

   sort_server_service_hash.forEach
   [p1, serv_service_hash|
     serv_service_hash.forEach
   [
       it.forEach
       [serv_ser_path, cap_rec_hash|
         if(cap_rec_hash.size > 0)
         {
           /* Collect the instance paths */
           var instance = serv_ser_path?.substring(0, serv_ser_path.lastIndexOf("/"))
           instance = instance?.substring(instance.lastIndexOf("/") + 1)

           /* Collect the server service paths */
           var server_service = serv_ser_path?.substring(serv_ser_path.lastIndexOf("/") + 1)
           server_service = server_service?.substring(server_service.lastIndexOf("/") + 1)

           rec_cnt = rec_cnt + 1

           config_opt_serv_cap_rec.add('0/* Sd_GaaServerServiceStatic :'+'
           '+rec_cnt+' - '+module.sdConfig.shortName+' '+
           instance+' '+server_service+' */')

           server_rec_len = 0
           server_rec_length = 0

           cap_rec_hash.forEach
           [
             server_rec_cnt = 0
             it.forEach
             [cap_rec_path, keyvalue_hash|
               var keys = ''
               var vals = ''
               otherserv = new ArrayList<Object>
               config_chars = new ArrayList<String>
               config_values = new ArrayList<String>

               keys = keyvalue_hash.get("ServerServiceCapabilityRecordKey")
               vals = keyvalue_hash.get("ServerServiceCapabilityRecordValue")

               if(!(keys.nullOrEmpty))
               {
                 config_chars.addAll(keys.split(''))
               }
               if(!(vals.nullOrEmpty))
               {
                 config_values.addAll(vals.split(''))
               }
               /*Calculate length of the key = value and the length number itself */
               server_rec_length = config_chars.size + config_values.size + 1 + 1
               server_rec_len    = server_rec_len + server_rec_length
               server_rec_cnt = server_rec_cnt + server_rec_len
             ]
           ]
           /* Count of initial 2 zeros */
           server_rec_len = server_rec_len + 2
           config_opt_serv_cap_rec_index = config_opt_total_length + 1
           config_opt_server_serv_hash.put(serv_ser_path, config_opt_serv_cap_rec_index)

           config_opt_total_length = config_opt_total_length + server_rec_cnt + 6
          
          
           if(server_rec_len > 0)
           {
             index = index + 4
             if (server_rec_len > 255)
             {
               config_opt_serv_cap_rec.add('0')
               config_opt_serv_cap_rec.add((server_rec_len/256).intValue)
               config_opt_serv_cap_rec.add(server_rec_len % 256)
               config_opt_serv_cap_rec.add('0')
               config_opt_serv_cap_rec.add('0')
               otherserv.add('0')
               otherserv.add((server_rec_len/256).intValue)
               otherserv.add(server_rec_len % 256)
               otherserv.add('0')
               otherserv.add('0')
             }
             else
             {
               config_opt_serv_cap_rec.add('0')
               config_opt_serv_cap_rec.add(server_rec_len)
               config_opt_serv_cap_rec.add('0')
               config_opt_serv_cap_rec.add('0')
               otherserv.add('0')
               otherserv.add(server_rec_len)
               otherserv.add('0')
               otherserv.add('0')
             }
           }
           fill_server_rec_options(cap_rec_hash, otherserv)
         }
       ]
   ]
   ]

  sort_eve_handler_hash.forEach
  [p1, serv_service_hash|
    serv_service_hash.forEach
    [
         it.forEach
         [eve_handler_pth, cap_rec_hash|
           if(cap_rec_hash.size > 0)
           {
             /* Collect the instance paths */
             var instance = eve_handler_pth?.substring(0, eve_handler_pth.lastIndexOf("/"))
             instance = instance?.substring(0, instance.lastIndexOf("/"))
             instance = instance?.substring(instance.lastIndexOf("/") + 1)

             /* Collect the server service paths */
             var cl_service = eve_handler_pth?.substring(0, eve_handler_pth.lastIndexOf("/"))
             cl_service = cl_service?.substring(cl_service.lastIndexOf("/") + 1)

             var eve_handler_name = eve_handler_pth
             eve_handler_name = eve_handler_name?.substring(eve_handler_name.lastIndexOf("/") + 1)

             rec_cnt = rec_cnt + 1

             config_opt_eve_handler.add('0/* Sd_GaaEvHandlerStatic :'+'
             '+rec_cnt+' - '+module.sdConfig.shortName+' '+
             instance+' '+cl_service+' '+
             eve_handler_name +'*/')

             eve_handler_rec_len = 0
             eve_handler_rec_length = 0
             cap_rec_hash.forEach
             [
               eve_handler_rec_cnt = 0
               it.forEach
               [cap_rec_path, keyvalue_hash|
                 var keys = ''
                 var vals = ''

                 otherserv = new ArrayList<Object>

                 config_chars = new ArrayList<String>
                 config_values = new ArrayList<String>

                 keys = keyvalue_hash.get("eve_handler_ServerServiceCapabilityRecordKey")
                 vals = keyvalue_hash.get("eve_handler_ServerServiceCapabilityRecordValue")

                 if(!(keys.nullOrEmpty))
                 {
                   config_chars.addAll(keys.split(''))
                 }
                 if(!(vals.nullOrEmpty))
                 {
                   config_values.addAll(vals.split(''))
                 }
                 /*Calculate length of the key = value and the length number itself */
                 eve_handler_rec_length = config_chars.size + config_values.size + 1 + 1
                 eve_handler_rec_len = eve_handler_rec_len + eve_handler_rec_length
                 eve_handler_rec_cnt  = eve_handler_rec_cnt + eve_handler_rec_len
               ]
             ]
             /* Count of initial 2 zeros */
             eve_handler_rec_len = eve_handler_rec_len + 2
             config_opt_eve_handler_index = config_opt_total_length + 1
             config_opt_eve_handler_hash.put(eve_handler_pth, config_opt_eve_handler_index)
             config_opt_total_length = config_opt_total_length + eve_handler_rec_cnt + 6

             if(eve_handler_rec_len > 0)
             {
               index = index + 4
               if (eve_handler_rec_len > 255)
               {
                 config_opt_eve_handler.add('0')
                 config_opt_eve_handler.add((eve_handler_rec_len/256).intValue)
                 config_opt_eve_handler.add(eve_handler_rec_len % 256)
                 config_opt_eve_handler.add('0')
                 config_opt_eve_handler.add('0')
                 otherserv.add('0')
                 otherserv.add((eve_handler_rec_len/256).intValue)
                 otherserv.add(eve_handler_rec_len % 256)
                 otherserv.add('0')
                 otherserv.add('0')
               }
               else
               {
                 config_opt_eve_handler.add('0')
                 config_opt_eve_handler.add(eve_handler_rec_len)
                 config_opt_eve_handler.add('0')
                 config_opt_eve_handler.add('0')
                 otherserv.add('0')
                 otherserv.add(eve_handler_rec_len)
                 otherserv.add('0')
                 otherserv.add('0')
               }
             }
             fill_eve_handler_rec_option(cap_rec_hash, otherserv)
           }
     ]
     ]
   ]
   sort_client_service_hash.forEach
   [p1, cl_service_hash|
     cl_service_hash.forEach
   [
      it.forEach
      [cl_ser_path, cap_rec_hash|
        if(cap_rec_hash.size > 0)
        {
         /* Collect the instance paths */
         var instance = cl_ser_path?.substring(0, cl_ser_path.lastIndexOf("/"))
         instance = instance?.substring(instance.lastIndexOf("/") + 1)

         /* Collect the client service paths */
         var client_service = cl_ser_path?.substring(cl_ser_path.lastIndexOf("/") + 1)
         client_service = client_service?.substring(client_service.lastIndexOf("/") + 1)

         rec_cnt = rec_cnt + 1

         config_opt_client_cap_rec.add('0/* Sd_GaaClientServiceStatic :'+'
         '+rec_cnt+' - '+module.sdConfig.shortName+' '+
         instance+' '+client_service+' */')
         client_rec_len = 0
         client_rec_length = 0
         cap_rec_hash.forEach
         [
           client_rec_cnt = 0
           it.forEach
           [cap_rec_path, keyvalue_hash|
             var keys = ''
             var vals = ''
       otherserv = new ArrayList<Object>
             config_chars = new ArrayList<String>
             config_values = new ArrayList<String>

             keys = keyvalue_hash.get("ClientServiceCapabilityRecordKey")
             vals = keyvalue_hash.get("ClientServiceCapabilityRecordValue")

             if(!(keys.nullOrEmpty))
             {
               config_chars.addAll(keys.split(''))
             }
             if(!(vals.nullOrEmpty))
             {
               config_values.addAll(vals.split(''))
             }
             /*Calculate length of the key = value and the length number itself */
             client_rec_length = config_chars.size + config_values.size + 1 + 1
             client_rec_len    = client_rec_len + client_rec_length;
             client_rec_cnt = client_rec_cnt + client_rec_len
           ]
         ]
         /* Count of initial 2 zeros */
         client_rec_len = client_rec_len + 2

         config_opt_client_cap_rec_index = config_opt_total_length + 1
         config_opt_client_serv_hash.put(cl_ser_path, config_opt_client_cap_rec_index)

         config_opt_total_length = config_opt_total_length + client_rec_cnt + 6

         if(client_rec_len > 0)
         {
           index = index + 4
           if (client_rec_len > 255)
           {
             config_opt_client_cap_rec_index = config_opt_client_cap_rec.size
             config_opt_client_cap_rec.add('0')
             config_opt_client_cap_rec.add((client_rec_len/256).intValue)
             config_opt_client_cap_rec.add(client_rec_len % 256)
             config_opt_client_cap_rec.add('0')
             config_opt_client_cap_rec.add('0')

             otherserv.add('0')
             otherserv.add((client_rec_len/256).intValue)
             otherserv.add(client_rec_len % 256)
             otherserv.add('0')
             otherserv.add('0')
           }
           else
           {
             config_opt_client_cap_rec_index = config_opt_client_cap_rec.size
             config_opt_client_cap_rec.add('0')
             config_opt_client_cap_rec.add(client_rec_len)
             config_opt_client_cap_rec.add('0')
             config_opt_client_cap_rec.add('0')

             otherserv.add('0')
             otherserv.add(client_rec_len)
             otherserv.add('0')
             otherserv.add('0')
           }
         }
         fill_client_rec_options(cap_rec_hash, otherserv)
        }
    ]
  ]
  ]
  sort_con_eve_hash.forEach
  [p1, cl_service_hash|
      cl_service_hash.forEach
      [
           it.forEach
           [con_eve_grp_pth, cap_rec_hash|
             if(cap_rec_hash.size > 0)
             {
               /* Collect the instance paths */
               var instance = con_eve_grp_pth?.substring(0, con_eve_grp_pth.lastIndexOf("/"))
               instance = instance?.substring(0, instance.lastIndexOf("/"))
               instance = instance?.substring(instance.lastIndexOf("/") + 1)

              /* Collect the server service paths */
              var cl_service = con_eve_grp_pth?.substring(0, con_eve_grp_pth.lastIndexOf("/"))
              cl_service = cl_service?.substring(cl_service.lastIndexOf("/") + 1)

              var con_eve_grp_name = con_eve_grp_pth
              con_eve_grp_name = con_eve_grp_name?.substring(con_eve_grp_name.lastIndexOf("/") + 1)

              rec_cnt = rec_cnt + 1

              config_opt_consumed_eve.add('0/* Sd_GaaConsumedEvGrpStatic :'+' '+rec_cnt+' - '+
                module.sdConfig.shortName+' '+instance+' '+cl_service+' '+con_eve_grp_name +'*/')

              con_eve_rec_len = 0
              con_eve_rec_length = 0
              cap_rec_hash.forEach
              [
                con_eve_rec_cnt = 0
                it.forEach
                [cap_rec_path, keyvalue_hash|
                  var keys = ''
                  var vals = ''

            otherserv = new ArrayList<Object>
                  config_chars = new ArrayList<String>
                  config_values = new ArrayList<String>
                  keys = keyvalue_hash.get("Con_eve_ClientServiceCapabilityRecordKey")
                  vals = keyvalue_hash.get("Con_eve_ClientServiceCapabilityRecordValue")

                  if(!(keys.nullOrEmpty))
                  {
                    config_chars.addAll(keys.split(''))
                  }
                  if(!(vals.nullOrEmpty))
                  {
                    config_values.addAll(vals.split(''))
                  }
                  /*Calculate length of the key = value and the length number itself */
                  con_eve_rec_length = config_chars.size + config_values.size + 1 + 1
                  con_eve_rec_len = con_eve_rec_len + con_eve_rec_length
                  con_eve_rec_cnt  = con_eve_rec_cnt + con_eve_rec_len
               ]
             ]
             /* Count of initial 2 zeros */
             con_eve_rec_len = con_eve_rec_len + 2

             config_opt_consumed_eve_index = config_opt_total_length + 1
             config_opt_con_eve_hash.put(con_eve_grp_pth, config_opt_consumed_eve_index)

             config_opt_total_length = config_opt_total_length + con_eve_rec_cnt + 6

              if(con_eve_rec_len > 0)
              {
                index = index + 4
                if (con_eve_rec_len > 255)
                {
                  config_opt_consumed_eve.add('0')
                  config_opt_consumed_eve.add((con_eve_rec_len/256).intValue)
                  config_opt_consumed_eve.add(con_eve_rec_len % 256)
                  config_opt_consumed_eve.add('0')
                  config_opt_consumed_eve.add('0')
                  otherserv.add('0')
                  otherserv.add((con_eve_rec_len/256).intValue)
                  otherserv.add(con_eve_rec_len % 256)
                  otherserv.add('0')
                  otherserv.add('0')
                }
                else
                {
                  config_opt_consumed_eve.add('0')
                  config_opt_consumed_eve.add(con_eve_rec_len)
                  config_opt_consumed_eve.add('0')
                  config_opt_consumed_eve.add('0')
                  otherserv.add('0')
                  otherserv.add(con_eve_rec_len)
                  otherserv.add('0')
                  otherserv.add('0')
                }
              }
              fill_con_eve_rec_option(cap_rec_hash, otherserv)
            }
        ]
     ]
   ]
     if(!Pbvc_list.nullOrEmpty)
 {
       	for(iter1:Pbvc_list)
    {
   if(Sd_GInstances_arr.size > 0)
   {
     for(instances : Sd_GInstances_arr.toSet)
     {
       rec_cnt = rec_cnt + 1
       for(sd_inst : SdInstance)
       {
         config_values = new ArrayList<String>
         if(instances == sd_inst?.shortNamePath?.toString)
         {
       val  sd_inst_hstname = sd_inst?.sdInstanceHostname_PB?.filterVariant(iter1, module?.sdConfig?.toString )?.toSet
           //for(sd_inst_hstname : sd_inst?.sdInstanceHostname_PB?.filterVariant(iter1, module?.sdConfig?.toString )?.toSet)
           if(sd_inst_hstname.head != null)
           {
             config_values.addAll(sd_inst_hstname?.head?.toString.split(''))
             sd_hst_name_length = config_values.size

             config_opt_sd_inst_hstname.add('0/* InstanceHostname :'+'
              '+rec_cnt+' - '+module?.sdConfig?.shortName+' '+
              sd_inst?.shortName+' */')

             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(sd_hst_name_length + 12)
             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(sd_hst_name_length + 9)
             config_opt_sd_inst_hstname.add("(uint8)'h'")
             config_opt_sd_inst_hstname.add("(uint8)'o'")
             config_opt_sd_inst_hstname.add("(uint8)'s'")
             config_opt_sd_inst_hstname.add("(uint8)'t'")
             config_opt_sd_inst_hstname.add("(uint8)'n'")
             config_opt_sd_inst_hstname.add("(uint8)'a'")
             config_opt_sd_inst_hstname.add("(uint8)'m'")
             config_opt_sd_inst_hstname.add("(uint8)'e'")
             config_opt_sd_inst_hstname.add("(uint8)'='")

             config_opt_inst_hstnm_index = config_opt_total_length + 1
             config_opt_inst_hash.put(instances?.toString, config_opt_inst_hstnm_index)

             config_opt_total_length = config_opt_total_length + sd_hst_name_length + 12 + 4
           }
       if(config_opt_sd_inst_hstname.size > 0)
           {
             config_values.forEach
             [
               config_opt_sd_inst_hstname.add("(uint8)'"+it+"'")
             ]
              if(sd_inst_hstname.head != null)
             {
               config_opt_sd_inst_hstname.add(0)
             }
           }
          }
        }
      }
    }
    }
    
    }
    else
    {
    	  if(Sd_GInstances_arr.size > 0)
   {
     for(instances : Sd_GInstances_arr)
     {
       rec_cnt = rec_cnt + 1
       for(sd_inst : SdInstance)
       {
         config_values = new ArrayList<String>
         if(instances == sd_inst?.shortNamePath?.toString)
         {
           
           for(sd_inst_hstname : sd_inst?.sdInstanceHostname_PB?.toList)
           {
             config_values.addAll(sd_inst_hstname?.toString.split(''))
             sd_hst_name_length = config_values.size

             config_opt_sd_inst_hstname.add('0/* InstanceHostname :'+'
              '+rec_cnt+' - '+module?.sdConfig?.shortName+' '+
              sd_inst?.shortName+' */')

             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(sd_hst_name_length + 12)
             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(0)
             config_opt_sd_inst_hstname.add(sd_hst_name_length + 9)
             config_opt_sd_inst_hstname.add("(uint8)'h'")
             config_opt_sd_inst_hstname.add("(uint8)'o'")
             config_opt_sd_inst_hstname.add("(uint8)'s'")
             config_opt_sd_inst_hstname.add("(uint8)'t'")
             config_opt_sd_inst_hstname.add("(uint8)'n'")
             config_opt_sd_inst_hstname.add("(uint8)'a'")
             config_opt_sd_inst_hstname.add("(uint8)'m'")
             config_opt_sd_inst_hstname.add("(uint8)'e'")
             config_opt_sd_inst_hstname.add("(uint8)'='")

             config_opt_inst_hstnm_index = config_opt_total_length + 1
             config_opt_inst_hash.put(instances?.toString, config_opt_inst_hstnm_index)

             config_opt_total_length = config_opt_total_length + sd_hst_name_length + 12 + 4
           }
       if(config_opt_sd_inst_hstname.size > 0)
           {
             config_values.forEach
             [
               config_opt_sd_inst_hstname.add("(uint8)'"+it+"'")
             ]
             for(sd_inst_hstname : sd_inst?.sdInstanceHostname_PB?.toList)
             {
               config_opt_sd_inst_hstname.add(0)
             }
           }
          }
        }
      }
    }
    }
  
  }
  def fill_client_rec_options(ArrayList<HashMap<String, HashMap<String, String>>>cap_record,
    ArrayList<Object> otherserv)
    {
      cap_record.forEach
      [
        it.forEach
        [cap_rec_path, keyvalue_hash|
          other_servevals = new HashMap<String, Integer>
          config_chars = new ArrayList<String>
          config_values = new ArrayList<String>
          var keys = ''
          var vals = ''
          var length = 0
          config_chars = new ArrayList<String>
          config_values = new ArrayList<String>
          var cliserv_path = cap_rec_path?.substring(0, cap_rec_path.lastIndexOf("/"))

          keys = keyvalue_hash.get("ClientServiceCapabilityRecordKey")
          vals = keyvalue_hash.get("ClientServiceCapabilityRecordValue")
          otherserv_flag = 0
      if(keys == "otherserv")
      {
        otherserv_flag = 1
      }
          if(!(keys.nullOrEmpty))
          {
            config_chars.addAll(keys.split(''))
          }
          if(!(vals.nullOrEmpty))
          {
            config_values.addAll(vals.split(''))
          }
          /*Calculate length of the key = value */
          length = config_chars.size + config_values.size+1

          /* Fill length of key = value in array config_opt_client_cap_rec */
          config_opt_client_cap_rec.add(length)
          otherserv.add(length)

          /* Fill all keys in array config_opt_client_cap_rec */
          for(chars : config_chars)
          {
            if(chars != '')
            {
              config_opt_client_cap_rec.add("(uint8)'"+chars+"'")

              otherserv.add("'"+chars+"'")
            }
          }
          /* Fill '=' in array config_opt_client_cap_rec */
          config_opt_client_cap_rec.add("(uint8)'='")
          otherserv.add("'='")

      if(!config_values.nullOrEmpty)
      {
            /* Fill all values in array config_opt_client_cap_rec */
            for(value : config_values)
            {
              if(value != '')
              {
                config_opt_client_cap_rec.add("(uint8)'"+value+"'")
          otherserv.add("'"+value+"'")
          if(otherserv_flag == 1)
          {
          other_servevals.put("OtherservKeyIndex", otherserv.indexOf("'"+config_values.get(0)+"'"))
          }
          else
          {
            
          }
              }
            }
          }
      else
      {
        if(otherserv_flag == 1)
      {
        other_servevals.put("OtherservKeyIndex", otherserv.size)
      }
      else
      {
        
      }
      }
      if(otherserv_flag == 1)
      {
      other_servevals.put("OtherservKeyLength", config_values.size)
      other_serve_main_hash.put(cliserv_path, other_servevals)
            other_servevals = new HashMap<String, Integer>()
          otherserv_flag = 0
      }
        ]
      ]
      /* Fill 0 in array config_opt_client_cap_rec */
      config_opt_client_cap_rec.add(0)
    }
    def fill_server_rec_options(ArrayList<HashMap<String, HashMap<String, String>>>cap_record,
      ArrayList<Object> otherserv)
    {
      cap_record.forEach
      [
        other_servevals = new HashMap<String, Integer>
        it.forEach
        [cap_rec_path, keyvalue_hash|
          config_chars = new ArrayList<String>
          config_values = new ArrayList<String>
          var keys = ''
          var vals = ''
          var length = 0
          config_chars = new ArrayList<String>
          config_values = new ArrayList<String>
          var serv_path = cap_rec_path?.substring(0, cap_rec_path.lastIndexOf("/"))
          keys = keyvalue_hash.get("ServerServiceCapabilityRecordKey")
          vals = keyvalue_hash.get("ServerServiceCapabilityRecordValue")
      otherserv_flag = 0
      if(keys == "otherserv")
      {
        otherserv_flag = 1
      }
          if(!(keys.nullOrEmpty))
          {
            config_chars.addAll(keys.split(''))
          }
          if(!(vals.nullOrEmpty))
          {
            config_values.addAll(vals.split(''))
          }

          /*Calculate length of the key = value */
          length = config_chars.size + config_values.size+1

          /* Fill length of key = value in array config_opt_serv_cap_rec */
          config_opt_serv_cap_rec.add(length)
      otherserv.add(length)
          /* Fill all keys in array config_opt_serv_cap_rec */
          for(chars : config_chars)
          {
            if(chars != '')
            {
              config_opt_serv_cap_rec.add("(uint8)'"+chars+"'")
        otherserv.add("'"+chars+"'")
            }
          }
          /* Fill '=' in array config_opt_serv_cap_rec */
          config_opt_serv_cap_rec.add("(uint8)'='")
          otherserv.add("'='")
      if(!config_values.nullOrEmpty)
      {
            /* Fill all values in array config_opt_serv_cap_rec */
            for(value : config_values)
            {
              if(value != '')
              {
          config_opt_serv_cap_rec.add("(uint8)'"+value+"'")
          otherserv.add("'"+value+"'")
          if(otherserv_flag == 1)
          {
            other_servevals.put("OtherservKeyIndex", otherserv.indexOf("'"+config_values.get(0)+"'"))
          }
          else
          {
            
          }
              }
            }
      }
      else
      {
        if(otherserv_flag == 1)
      {
        other_servevals.put("OtherservKeyIndex", otherserv.size)
      }
        else
        {
          
        }
      }
      if(otherserv_flag == 1)
      {
      other_servevals.put("OtherservKeyLength", config_values.size)
      other_serve_main_hash.put(serv_path, other_servevals)
            other_servevals = new HashMap<String, Integer>()
      otherserv_flag = 0
      }
        ]
     ]
     /* Fill 0 in array config_opt_serv_cap_rec */
     config_opt_serv_cap_rec.add(0)
   }
  def fill_con_eve_rec_option(ArrayList<HashMap<String, HashMap<String, String>>>cap_record,
    ArrayList<Object> otherserv)
  {
    cap_record.forEach
    [
      other_servevals = new HashMap<String, Integer>
      it.forEach
      [cap_rec_path, keyvalue_hash|
        config_chars = new ArrayList<String>
        config_values = new ArrayList<String>
        var keys = ''
        var vals = ''
        var length = 0
        config_chars = new ArrayList<String>
        config_values = new ArrayList<String>

        var consevent_path = cap_rec_path?.substring(0, cap_rec_path.lastIndexOf("/"))
        keys = keyvalue_hash.get("Con_eve_ClientServiceCapabilityRecordKey")
        vals = keyvalue_hash.get("Con_eve_ClientServiceCapabilityRecordValue")
        otherserv_flag = 0
    if(keys == "otherserv")
    {
      otherserv_flag = 1
    }
        if(!(keys.nullOrEmpty))
        {
          config_chars.addAll(keys.split(''))
        }
        if(!(vals.nullOrEmpty))
        {
          config_values.addAll(vals.split(''))
        }
        /*Calculate length of the key = value */
        length = config_chars.size + config_values.size+1

        /* Fill length of key = value in array config_opt_consumed_eve */
        config_opt_consumed_eve.add(length)
        otherserv.add(length)
        /* Fill all keys in array config_opt_consumed_eve */
        for(chars : config_chars)
        {
          if(chars != '')
          {
            config_opt_consumed_eve.add("(uint8)'"+chars+"'")
      otherserv.add("'"+chars+"'")
          }
        }
        /* Fill '=' in array config_opt_consumed_eve */
        config_opt_consumed_eve.add("(uint8)'='")
        otherserv.add("'='")
    if(!config_values.nullOrEmpty)
    {
          /* Fill all values in array config_opt_consumed_eve */
          for(value : config_values)
          {
            if(value != '')
            {
              config_opt_consumed_eve.add("(uint8)'"+value+"'")
          otherserv.add("'"+value+"'")
          if(otherserv_flag == 1)
          {
            other_servevals.put("OtherservKeyIndex", otherserv.indexOf("'"+config_values.get(0)+"'"))
          }
          else
          {
            
          }
            }
          }
    }
    else
    {
      if(otherserv_flag == 1)
      {
        other_servevals.put("OtherservKeyIndex", otherserv.size)
      }
      else
      {
        
      }
    }
    if(otherserv_flag == 1)
    {
        other_servevals.put("OtherservKeyLength", config_values.size)
      other_serve_main_hash.put(consevent_path, other_servevals)
          other_servevals = new HashMap<String, Integer>
      otherserv_flag = 0
    }
      ]
    ]
    /* Fill 0 in array config_opt_consumed_eve */
    config_opt_consumed_eve.add(0)
  }

   def fill_eve_handler_rec_option(ArrayList<HashMap<String, HashMap<String, String>>>cap_record,
     ArrayList<Object> otherserv)
   {
     cap_record.forEach
     [
     other_servevals = new HashMap<String, Integer>
       it.forEach
       [cap_rec_path, keyvalue_hash|
         config_chars = new ArrayList<String>
         config_values = new ArrayList<String>
         var keys = ''
         var vals = ''
         var length = 0
         config_chars = new ArrayList<String>
         config_values = new ArrayList<String>

         var evehandler_path = cap_rec_path?.substring(0, cap_rec_path.lastIndexOf("/"))
         keys = keyvalue_hash.get("eve_handler_ServerServiceCapabilityRecordKey")
         vals = keyvalue_hash.get("eve_handler_ServerServiceCapabilityRecordValue")
         otherserv_flag = 0
     if(keys == "otherserv")
     {
      otherserv_flag = 1
     }
         if(!(keys.nullOrEmpty))
         {
           config_chars.addAll(keys.split(''))
         }
         if(!(vals.nullOrEmpty))
         {
           config_values.addAll(vals.split(''))
         }
         /*Calculate length of the key = value */
         length = config_chars.size + config_values.size+1

         /* Fill length of key = value in array config_opt_eve_handler */
         config_opt_eve_handler.add(length)
         otherserv.add(length)

         /* Fill all keys in array config_opt_eve_handler */
         for(chars : config_chars)
         {
           if(chars != '')
           {
             config_opt_eve_handler.add("(uint8)'"+chars+"'")
       otherserv.add("'"+chars+"'")
           }
         }
         /* Fill '=' in array config_opt_eve_handler */
         config_opt_eve_handler.add("(uint8)'='")
         otherserv.add("'='")

     if(!config_values.nullOrEmpty)
     {
           /* Fill all values in array config_opt_eve_handler */
           for(value : config_values)
           {
             if(value != '')
             {
               config_opt_eve_handler.add("(uint8)'"+value+"'")
            otherserv.add("'"+value+"'")
            if(otherserv_flag == 1)
            {
              other_servevals.put("OtherservKeyIndex", otherserv.indexOf("'"+config_values.get(0)+"'"))
            }
           else
           {
              
            }
             }
      }
        }
    else
    {
      if(otherserv_flag == 1)
      {
        other_servevals.put("OtherservKeyIndex", otherserv.size)
      }
      else
      {
        
      }
    }
    if(otherserv_flag == 1)
    {
        other_servevals.put("OtherservKeyLength", config_values.size)
      other_serve_main_hash.put(evehandler_path, other_servevals)
        other_servevals = new HashMap<String, Integer>
      otherserv_flag = 0
    }
      ]
    ]
    /* Fill 0 in array config_opt_eve_handler */
    config_opt_eve_handler.add(0)
  }

  def get_config_opt_consumed_eve()
  {
     return config_opt_consumed_eve
  }
   def get_config_opt_serv_cap_rec()
   {
     return config_opt_serv_cap_rec
   }
   def get_config_opt_eve_handler()
   {
     return config_opt_eve_handler
   }
   def get_config_opt_inst_hstname()
   {
     return config_opt_sd_inst_hstname
   }
   def get_config_opt_total_length()
   {
     return config_opt_total_length
   }
   def get_config_opt_inst_hstnm_index()
   {
     return config_opt_inst_hash
   }
   def get_config_opt_client_cap_rec()
   {
     return config_opt_client_cap_rec
   }
   def get_config_opt_client_cap_rec_index()
   {
     return config_opt_client_serv_hash
   }
   def get_config_opt_serv_cap_rec_index()
   {
     return config_opt_server_serv_hash
   }
   def get_config_opt_consumed_eve_index()
   {
     return config_opt_con_eve_hash
   }
   def get_config_opt_event_handler_index()
   {
     return config_opt_eve_handler_hash
   }
   def get_server_service_arr()
   {
     return server_service_arr
   }
   def get_client_soc_congrp_arr()
   {
     return client_soc_congrp_arr
   }
   def get_sd_con_eve_tcp_ref()
   {
     return sd_con_eve_tcp_ref_arr
   }
   def get_sd_con_eve_tcp_ref_arr_map()
   {
     return sd_con_eve_tcp_ref_arr_map
   }
   
   def get_sd_con_eve_udp_ref_arr_map()
   {
     return sd_con_eve_udp_ref_arr_map
   }
   def get_sd_con_eve_udp_ref()
   {
     return sd_con_eve_udp_ref_arr
   }
   def get_sd_eve_handler_tcp_ref_arr()
   {
     return sd_eve_handler_tcp_ref_arr
   }
   def get_act_eve_handler_udp_routing_grp_map()
   {
   	return act_eve_handler_udp_routing_grp_map
   }
   def get_act_eve_handler_tcp_routing_grp_map()
   {
   	return act_eve_handler_tcp_routing_grp_map
   }
   def get_sd_eve_handler_tcp_ref_arr_map()
   {
   	return sd_eve_handler_tcp_ref_arr_map
   }
   def get_sd_eve_handler_udp_ref_arr_map()
   {
   	return sd_eve_handler_udp_ref_arr_map
   }
   def get_act_eve_handler_routing_grp_map()
   {
   	return act_eve_handler_routing_grp_map
   }
   def get_sd_eve_handler_multi_soc_con_map()
   {
   	return sd_eve_handler_multi_soc_con_map
   }
   def get_sd_eve_handler_udp_ref_arr()
   {
     return sd_eve_handler_udp_ref_arr
   }
   def get_server_services_cnt()
   {
     return server_services_cnt
   }
   def get_client_services_cnt()
   {
     return client_services_cnt
   }
   def get_server_timer_arr()
   {
     return server_timer_arr
   }
   def get_server_timer_arr1()
   {
     return server_timer_arr1
   }
   def get_server_timer_arr1_pb()
   {
     if(!(Pbvc_list.nullOrEmpty))
     {
     server_timer_cnt_pb = server_timer_arr1.size * Pbvc_list.size
     return server_timer_cnt_pb
     }
     
   }
   
     
   
   def get_client_timer_arr()
   {
     return client_timer_arr
   }
   def get_service_group_arr(){
   	val List = module.sdConfig.sdServiceGroups_PB
   	return List.size
   }
   def get_event_handle_ids()
   {
     return event_handle_ids
   }
   def get_consumed_eve_grp_cnt()
   {
     return consumed_eve_grp_cnt
   }
   def get_server_handle_ids()
   {
     return server_handle_ids
   }
   def get_client_handle_ids()
   {
     return client_handle_ids
   }
   def get_SerGrp_handle_ids()
   {
     return SerGrp_handle_ids
   }
   
   def get_no_of_Instances()
   {
     return Sd_GInstances_arr
   }
   def get_act_cl_routing_grp()
   {
     return act_client_routing_grp
   }
   def get_act_ser_routing_grp()
   {
     return act_server_routing_grp
   }
   def get_act_consumed_eve_routing_grp()
   {
     return act_consumed_eve_routing_grp
   }
   def get_act_eve_handler_routing_grp()
   {
     return act_eve_handler_routing_grp
   }
   def get_sd_eve_handler_multi_soc_con()
   {
     return sd_eve_handler_multi_soc_con
   }
   def get_act_eve_handler_udp_routing_grp()
   {
     return act_eve_handler_udp_routing_grp
   }
   def get_act_eve_handler_tcp_routing_grp()
   {
     return act_eve_handler_tcp_routing_grp
   }
   def get_evhandler_timer_cnt()
   {
     return evhandler_timer_cnt
   }
   def get_client_timer_cnt_pb()
   {
     return client_timer_cnt_pb
   }
   def get_server_timer_cnt_vp()
   {
     return server_timer_cnt_vp
   }
   def get_client_timer_cnt()
   { 
   	
   	if(!Pbvc_list.nullOrEmpty)
   	{ 
   		return client_timer_cnt_pb
    }
    else
    {
   	  return client_timer_cnt
    }
    
   }
   def get_Soad_client_con_ev_grp()
   {
     return Soad_client_con_ev_grp
   }
   def get_sd_con_eve_grp_hash()
   {
     return sd_client_con_ev_grp_ref_hash
   }
   def get_clientserallowprovs()
   {
     
     return clientserallowprovs
   }
   def get_consumed_eve_grp_id_hash()
   {
     return consumed_eve_grp_id_hash
   }
   def get_server_handle_ids_map()
   {
    return server_handle_ids_map
   }
   def get_client_handle_ids_map()
   {
    return client_handle_ids_map
   }
   
   def get_act_client_routing_grp_map()
   {
    return act_client_routing_grp_map
   }
   def get_act_consumed_eve_routing_grp_map()
   {
    return act_consumed_eve_routing_grp_map
   }
   def get_act_server_routing_grp_map()
   {
    return act_server_routing_grp_map
   }
   def get_con_eve_grp_handle_ids()
   {
     return con_eve_grp_handle_ids
   }
   def get_con_eve_grp_handle_ids_map()
   {
    return con_eve_grp_handle_ids_map
   }
   def get_client_Timer_ids_map()
   {
    return client_Timer_ids_map
   }
   def get_con_eve_grp_Timer_ids_map()
   {
    return con_eve_grp_Timer_ids_map
   }
   def get_server_Timer_ids_map()
   {
    return server_Timer_ids_map
   }
   def get_server_Timer_ids_map1()
   {
    return server_Timer_ids_map1
   }
   def get_Soad_cnt_arr()
   {
     return Soad_cnt_arr
   }
   def get_inst_uni_multicast_rx_pdu()
   {
     return inst_uni_multicast_rx_pdu
   }
   
   def get_inst_uni_multicast_rx_pdu_map()
   {
     return inst_uni_multicast_rx_pdu_map
   }
   def get_eve_handler_cnt()
   {
      return eve_handler_cnt
   }
   def get_otherservKeyLength()
   {
     return otherservKeyLength
   }
   def get_otherservKeyIndex()
   {
     return other_serve_main_hash
   }
   def domain_type_ipv4()
   {
      return domain_type_hash
   }
   def domain_type_ipv4_vp()
   {
      return domain_type_hash_map
   }
   def get_Soad_socket_cnt()
   {
     return Soad_socket_cnt
   }
   
   def  get_service_grp_arr()
   {
   	return client_Sgrp_arr
   }
   
   def get_service_grp_arr1()
   {
   	return server_Sgrp_arr
   	
   }
   
    def get_server_arry1()
   {
   	return server_Sgrp_arr
   	
   }
   
  /*  def get_blacklisted_grp_arr()
   {
   	for (bl:_Sd.sdConfig.sdInstances)
   	{
   		for(bl2:bl.sdClientServices)
   		{
   			blacklisted_grp_cnt=bl2.sdBlacklistedVersions_PB.size
   		}
   	}
   	return blacklisted_grp_cnt
   	
   }*/
}
