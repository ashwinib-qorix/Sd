/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name     : SdMapping.xtend
 *
 * Description   : It Provides rules for harmonizing configuration for Sd Module.
 *
 */

/*
 * Revision History:
 * Date            Changed By             Description
 * 07-July-2025    Samarth Golwalker  Migration Release R24-11.

 */
package com.kpit.c4k.bsw.sd.mapping

import autosar40.ecucdescription.EcucModuleConfigurationValues
import autosar40.genericstructure.generaltemplateclasses.arobject.ARObject
import autosar40.genericstructure.generaltemplateclasses.tagwithoptionalvalue.TagWithOptionalValue
import autosar40.system.fibex.fibex4ethernet.ethernettopology.ApplicationEndpoint
import autosar40.system.fibex.fibex4ethernet.ethernettopology.Ipv4Configuration
import autosar40.system.fibex.fibex4ethernet.ethernettopology.Ipv6Configuration
import autosar40.system.fibex.fibex4ethernet.ethernettopology.NetworkEndpoint
import autosar40.system.fibex.fibex4ethernet.ethernettopology.NetworkEndpointAddress
import autosar40.system.fibex.fibex4ethernet.ethernettopology.TcpTp
import autosar40.system.fibex.fibex4ethernet.ethernettopology.TransportProtocolConfiguration
import autosar40.system.fibex.fibex4ethernet.ethernettopology.UdpTp
import autosar40.system.fibex.fibex4ethernet.serviceinstances.AbstractServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ConsumedEventGroup
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ConsumedProvidedServiceInstanceGroup
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ConsumedServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.EventGroupControlTypeEnum
import autosar40.system.fibex.fibex4ethernet.serviceinstances.InitialSdDelayConfig
import autosar40.system.fibex.fibex4ethernet.serviceinstances.PduActivationRoutingGroup
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ProvidedServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.RequestResponseDelay
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SocketAddress
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdClientEventGroupTimingConfig
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdClientServiceInstanceConfig
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdServerServiceInstanceConfig
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipServiceVersion
import autosar40.system.fibex.fibex4ethernet.serviceinstances.StaticSocketConnection
import autosar40.system.fibex.fibexcore.corecommunication.CommunicationDirectionType
import autosar40.system.fibex.fibexcore.corecommunication.GeneralPurposePdu
import autosar40.system.fibex.fibexcore.corecommunication.IPduPort
import autosar40.system.fibex.fibexcore.corecommunication.PduTriggering
import com.kpit.c4k.bsw.ecuc.mapping.EcuCMapping
import com.kpit.c4k.core.model.ModelIndex
import com.kpit.c4k.ecuc.mapping.BaseEcucMapping
import com.kpit.c4k.ecuc.mapping.Context
import com.kpit.c4k.ecuc.mapping.EcucMappingExtensions
import com.kpit.c4k.ecuc.mapping.SubContext
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdBlocklistedVersions
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientCapabilityRecord
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceAllowedProvider
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdConsumedEventGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdConsumedMethods
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientTimer
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdInstanceMulticastRxPdu
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdInstanceTxPdu
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdInstanceUnicastRxPdu
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdEventHandler
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdProvidedMethods
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerTimer
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdServiceGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdGeneral
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdRoutingGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdSocketConnectionGroup
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdSocketConnectionGroup.SoAdSocketConnection
import gautosar.ggenericstructure.ginfrastructure.GARObject
import java.io.Serializable
import java.util.HashMap
import org.eclipse.emf.ecore.EObject
import java.util.HexFormat
import static extension com.kpit.c4k.core.model.extensions.ReferrableExtensions.*
import static extension org.apache.commons.lang.Validate.*
import java.lang.annotation.Repeatable
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdServerEventGroupTimingConfig
import autosar40.system.fibex.fibex4ethernet.serviceinstances.EventHandler
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdEventHandler.SdEventHandlerTimerRef
import autosar40.adaptiveplatform.general.UploadableDesignElement

class SdMapping extends BaseEcucMapping {

var nSdInstanceUnicastRxPduId = 0
var nSdInstanceMulticastRxPduId = 0

def dispatch init(Sd it)
{
	createSdConfig[
		ruleId="KSAR_ECUC_SD_00003"
	]
	createSdGeneral[
		ruleId="KSAR_ECUC_SD_00002"
	]
}
  def dispatch init(SdConfig it) {
    createSdInstance [
      ruleId = "KSAR_ECUC_SD_00084"
      shortName = getUniqueShortName("SdInstance_0")
   val _headNetworkEndPoint = model.findAll(NetworkEndpoint)
  _headNetworkEndPoint?.forEach[Hst |
  	if(!Hst?.fullyQualifiedDomainName.isNullOrEmpty )
{  createSdInstanceHostname[ 
  	 ruleId = "ECUC_SD_00012"
  	 
  	 value =  Hst?.fullyQualifiedDomainName?.toString
  ]
  
  }
]
    ]
    val service = model.findAll(ConsumedProvidedServiceInstanceGroup)
    service.forEach[Service_ |
	 createSdServiceGroup[
    	ruleId = "ECUC_SD_00134"
        context = Service_

    	]
    	
    ]
   /*  createSdCapabilityRecordMatchCallout[
     	ruleId = "ECUC_SD_00124"
     	
     	createSdCapabilityRecordMatchCalloutName[
     		ruleId = "ECUC_SD_00125"
     	]
     ]
     */
  }
@Context(ConsumedProvidedServiceInstanceGroup)
def dispatch init (SdServiceGroup it)
{
	val ruke = context =>[notNull]
	
	createSdServiceGroupHandleId[
    		ruleId="KSAR_ECUC_SD_00135"
    		value  = 0
    	]
}
def dispatch init(SdGeneral it)
{
 createSdDevErrorDetect[
 	ruleId="KSAR_ECUC_SD_00006"
 ]
 createSdMainFunctionCycleTime[
 	ruleId="KSAR_ECUC_SD_00008"
 ]
 createSdSetRemAddrOfClientRxMulticastSoCon[
 	ruleId="KSAR_ECUC_SD_00139"
 ]	
 createSdSubscribeEventgroupRetryEnable[
 	ruleId="KSAR_ECUC_SD_00131"
 ]
 createSdVersionInfoApi[
 	ruleId="KSAR_ECUC_SD_00007"
 ]
}
  def dispatch init(SdInstance it) {
  	
  	val sdConsumedInstances =   model.findAll(ConsumedServiceInstance)
    val sdProvidedInstances = model.findAll(ProvidedServiceInstance)
    sdConsumedInstances.filter[autoRequire==true || autoRequire == false].sortBy[shortName].forEach [ serviceInstance |
      createSdClientService [
        ruleId = "ECUC_SD_00005"
        shortName = getUniqueShortName("ClientService_") + serviceInstance.shortName
        context = serviceInstance
        
    ]
 ]


 val someIpClientInstances = model.findAll(SomeipSdClientServiceInstanceConfig)
 
 for(someIpInstance:someIpClientInstances)
 {
 	val sdTimerGroup = sdConsumedInstances.filter[autoRequire==true || autoRequire == false].map[sdClientTimerConfigs?.map[someipSdClientServiceInstanceConfig]]
 	.filterNull.flatten.filter[it==someIpInstance]
 	
 	if(sdTimerGroup?.size > 0)
 	{
 		createSdClientTimer[
 			 ruleId="ECUC_SD_00043"
 			shortName ="SdClientTimer_"+getUniqueShortName(someIpInstance)
 			context = someIpInstance
 			
 		if(someIpInstance.isSetServiceFindTimeToLive){
    createSdClientTimerTTL [
      ruleId = "ECUC_SD_00075"
      value = someIpInstance.serviceFindTimeToLive.intValue
    ]
    }
 		]
 	}
 	
 }
 
  val someIpClientEventInstances = model.findAll(SomeipSdClientEventGroupTimingConfig)
 
 for(someIpInstance_:someIpClientEventInstances)
 {
 	 val inster = someIpInstance_
 	val sdTimerGroup = sdConsumedInstances.head.consumedEventGroups.filter[it.autoRequire == true].map[it.sdClientTimerConfigs?.map[it.someipSdClientEventGroupTimingConfig]].filterNull.filter[it==someIpInstance_]
 	
 	createSdClientTimer[
 			 ruleId="ECUC_SD_00043"
 			shortName ="SdClientTimer_"+getUniqueShortName(someIpInstance_)
 			context = someIpInstance_
 		 
 	 	 if(someIpInstance_.isSetTimeToLive){
    createSdClientTimerTTL [
      ruleId = "ECUC_SD_00075"
      value = someIpInstance_.timeToLive.intValue
    ]
    }
 		]
 	
 	
 }


    sdProvidedInstances.sortBy[shortName].forEach [serviceInstance |
      createSdServerService [
        ruleId = "ECUC_SD_00004"
        shortName = getUniqueShortName("SdServerService_") + serviceInstance.shortName
        context = serviceInstance
        
      ]
    
    ] 
  val someIpServerInstaces=model.findAll(SomeipSdServerServiceInstanceConfig) 
  val psi = model.findAll(ProvidedServiceInstance)
  psi.forEach[P |
  	if(!P.sdServerTimerConfigs.isNullOrEmpty)
 { 	
  for(someIpInstances: someIpServerInstaces)   
  {
  
  	val sdTimerGroup=sdProvidedInstances.map[sdServerTimerConfigs?.map[someipSdServerServiceInstanceConfig]].filterNull.flatten.filter[it==someIpInstances]
  	if(sdTimerGroup?.size > 0)
  	{
  		createSdServerTimer[
  			ruleId="ECUC_SD_00035"
  			shortName="SdServerTimer_"+getUniqueShortName(someIpInstances)
  			context= someIpInstances
  			subContextCSI = P
  		]
  	}
  }
  
  }
  ]
 val someIpServerInstaces_EVENT=model.findAll(SomeipSdServerEventGroupTimingConfig) 
 
  for(someIpInstances_EVENT:someIpServerInstaces_EVENT)   
  {

  	
  		createSdServerTimer[
  			ruleId="ECUC_SD_00035"
  			shortName="SdServerTimer_"+getUniqueShortName(someIpInstances_EVENT)
  			context = someIpInstances_EVENT
  			      createSdServerTimerRequestResponseMaxDelay [
        ruleId = "ECUC_SD_00114"
        value = someIpInstances_EVENT?.requestResponseDelay?.maxValue
      ]

        createSdServerTimerRequestResponseMinDelay [
        ruleId = "ECUC_SD_00115"
        value = someIpInstances_EVENT.requestResponseDelay?.minValue


      ]
      createSdServerTimerTTL[
      	ruleId = "ECUC_SD_00037"
      	value = 1
      	
      ]
  		]
  	}

  
  
 
 

    model.findAll(PduTriggering).forEach [ pdutrigger |
 	var Ports = pdutrigger.IPduPorts
    val genpdu1 = (pdutrigger.IPdu as GeneralPurposePdu)
 	if (Ports.size == 1)
 	{	
 	   pdutrigger.getIPduPorts.filter[communicationDirection == CommunicationDirectionType.IN].forEach [ port |
 	   createSdInstanceUnicastRxPdu [
        ruleId = "ECUC_SD_00027"
        shortName = getUniqueShortName(genpdu1.shortName + "_SdInstanceUnicastRxPdu")
        context = genpdu1
      ]
     ]
    }
   ]

 model.findAll(PduTriggering).forEach [ pdutrigger |
 	val genpdu = (pdutrigger.IPdu as GeneralPurposePdu)
 	pdutrigger.getIPduPorts.filter[communicationDirection == CommunicationDirectionType.OUT].forEach [ port |
 		  createSdInstanceTxPdu [
        ruleId = "ECUC_SD_00030"
        shortName = getUniqueShortName(genpdu.shortName + "_SdInstanceTxPdu")
        context = genpdu
      ]
  
 		
 	]
 ]
     model.findAll(PduTriggering).forEach [ pdutrigger |
 	var Ports = pdutrigger.IPduPorts
    val genpdu = (pdutrigger.IPdu as GeneralPurposePdu)
 	if (Ports.size > 1)
 	{
 	  pdutrigger.getIPduPorts.filter[communicationDirection == CommunicationDirectionType.IN].forEach [ port |
      createSdInstanceMulticastRxPdu [
        ruleId = "ECUC_SD_00081"
        shortName = getUniqueShortName(genpdu.shortName + "_SdInstanceMulticastRxPdu")
        context = genpdu
       
      ]
     ]
    }
  ]

    }
 

   @Context(GeneralPurposePdu)
	def dispatch init(SdInstanceMulticastRxPdu it) {
		val generalPurposePdu = context => [notNull]
		val pduTriggerings = model.findAll(PduTriggering).filterNull
		val Gpdu = pduTriggerings.findFirst[it.IPdu.shortName == generalPurposePdu.shortName]
		if (generalPurposePdu != null)
		{
			createSdRxPduId [
				ruleId = "KSAR_ECUC_SD_00028"
				value = getSdInstanceMulticastRxPduId
			]
            if (Gpdu != null) {
			createSdRxPduRef [
				ruleId = "KSAR_ECUC_SD_00029"
				reference = EcuCMapping.findPduByContext(Gpdu, Gpdu.IPduPorts?.head, null)
			]
		}
	}
	
}
   
  
     @Context(GeneralPurposePdu)
	def dispatch init(SdInstanceUnicastRxPdu it) {
		val pdu = context => [notNull]
		val pduTriggerings = model.findAll(PduTriggering).filterNull

		createSdRxPduId [
			ruleId = "KSAR_ECUC_SD_00082"
			value = getSdInstanceUnicastRxPduId
		]
		
        val Gpdu = pduTriggerings.findFirst[it.IPdu.shortName == pdu.shortName]
		if (pdu != null) {
			createSdRxPduRef [
				ruleId = "KSAR_ECUC_SD_00083"
				reference = EcuCMapping.findPduByContext(Gpdu, Gpdu.inPorts.head, pdu)
			]
		}
	}
	
	
	@Context(GeneralPurposePdu)
	def dispatch init(SdInstanceTxPdu it) {
		val generalPurposePdu = context => [notNull]
		val pduTriggerings = model.findAll(PduTriggering).filterNull
		val Gpdu = pduTriggerings.findFirst[it.IPdu.shortName == generalPurposePdu.shortName]
		if (generalPurposePdu != null)
		{
		createSdTxPduRef [
			ruleId = "KSAR_ECUC_SD_00109"
			reference = EcuCMapping.findPduByContext(Gpdu, Gpdu.outPorts.head, generalPurposePdu)
		]
		
		}
	}

	

    @Context(UploadableDesignElement)
    @SubContext(role ="CSI",value=ProvidedServiceInstance)
    def dispatch init(SdServerTimer it) {
      val sdServerConfig_ = context => [notNull]
      val sdServerConfig = subContextCSI
      if(sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.offerCyclicDelay > 0 )
      {
      	createSdServerTimerOfferCyclicDelay [
        ruleId = "ECUC_SD_00076"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.offerCyclicDelay
      ]
      }
      createSdServerTimerRequestResponseMaxDelay [
        ruleId = "ECUC_SD_00114"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.requestResponseDelay?.maxValue
      ]

        createSdServerTimerRequestResponseMinDelay [
        ruleId = "ECUC_SD_00115"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.requestResponseDelay?.minValue


      ]
      if(sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.initialOfferBehavior != null)
      {
      	createSdServerTimerInitialOfferDelayMax [
        ruleId = "ECUC_SD_00039"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.initialOfferBehavior?.initialDelayMaxValue
      ]
     
      }
      
      createSdServerTimerTTL [
        ruleId = "ECUC_SD_00037"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.serviceOfferTimeToLive.intValue
      ]
   
      
      if(sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialDelayMaxValue != null)
      {
      	createSdServerTimerInitialOfferRepetitionsMax [
        ruleId = "ECUC_SD_00040"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialDelayMaxValue.intValue
      ]
      
      }
      if(sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialDelayMinValue != null)
      {
      	createSdServerTimerInitialOfferDelayMin [
        ruleId = "ECUC_SD_00038"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialDelayMinValue
      ]
      }
	  if(sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialRepetitionsBaseDelay != null)
	  {
	  	createSdServerTimerInitialOfferRepetitionBaseDelay [
        ruleId = "ECUC_SD_00041"
        value = sdServerConfig?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig.initialOfferBehavior?.initialRepetitionsBaseDelay
      ]
      
      }
    
  }

  @Context(ConsumedServiceInstance)
  @SubContext(role = "connection", value = StaticSocketConnection)
  @SubContext(role = "bundle", value = StaticSocketConnection)

  def dispatch init(SdClientService it) {
    val consumedServiceInstance = context => [notNull]
    if (consumedServiceInstance != null) {
    if(consumedServiceInstance.isSetInstanceIdentifier) {
   
      createSdClientServiceInstanceId [
        ruleId = "ECUC_SD_00022"
       
        value = Long.parseLong(consumedServiceInstance.instanceIdentifier).intValue
      ]
      }
      consumedServiceInstance.blocklistedVersions.forEach  [ blockListed |
      createSdBlocklistedVersions [
        ruleId = "ECUC_SD_00141"
        context = blockListed
      ]
      ]
 
 val Maj = model.findAll(AbstractServiceInstance)
      if(consumedServiceInstance.isSetMinorVersion) {
      createSdClientServiceMinorVersion [
        ruleId = "ECUC_SD_00071"
        value =  Long.parseLong(consumedServiceInstance.minorVersion)
      ]    
      }

      if(consumedServiceInstance.isSetMajorVersion) {
      createSdClientServiceMajorVersion [
        ruleId = "ECUC_SD_00070"
      
        
        value = consumedServiceInstance?.majorVersion.longValue.intValue
     
        
        
      ]
      }
      
     if(consumedServiceInstance.isSetServiceIdentifier) {
      createSdClientServiceId [
        ruleId = "ECUC_SD_00020"
        value = consumedServiceInstance.serviceIdentifier.intValue
      ]      
      }

       createSdClientServiceAutoRequire[
       	
       	ruleId="ECUC_SD_00143"
       	value = consumedServiceInstance?.autoRequire
       ]
   if (consumedServiceInstance.isSetVersionDrivenFindBehavior)
    {   createSdVersionDrivenFindBehavior[
    	ruleId="ECUC_SD_00140"
    	value = consumedServiceInstance?.versionDrivenFindBehavior?.toString
       ]
     
       }
       
      createSdClientServiceTimerRef [
        ruleId = "ECUC_SD_00103"
        reference = findSdClientTimerByContext(consumedServiceInstance?.sdClientTimerConfigs?.head?.someipSdClientServiceInstanceConfig)
      ]

      consumedServiceInstance.capabilityRecords.forEach [ capabilityRec |
        createSdClientCapabilityRecord [
          ruleId = "ECUC_SD_00072"
          shortName = getUniqueShortName("SdClientCapabilityRecord_")
          context = capabilityRec
        ]
      ]

      createSdClientServiceHandleId [
        ruleId = "KSAR_ECUC_SD_00079"
        value = nextId
      ]
	  
  	val group = model.findAll(ConsumedProvidedServiceInstanceGroup)


group.forEach[CSI |
	
	 
	 
	 CSI?.consumedServiceInstances?.forEach[  csi |
	 	if(csi?.consumedServiceInstance == consumedServiceInstance )
	{
		createSdServiceGroupRef[
			ruleId = "ECUC_SD_00137"
			reference = findSdServiceGroupByContext(csi?.consumedProvidedServiceInstanceGroup)
			
		]
		
		}
		]
		
	
	
]
consumedServiceInstance.allowedServiceProviders.forEach[ al |
   	createSdClientServiceAllowedProvider[
   		ruleId = "ECUC_Sd_00147"
   		shortName = getUniqueShortName("SdClientAllowedServiceProvider_" +it.index )
   		
   		   val fetch = model.findAll(ApplicationEndpoint)
   		   val net = model.findAll(NetworkEndpointAddress)
      	   	val ipv4 = model.findAll(Ipv4Configuration)
      	   	val ipv6 = model.findAll(Ipv6Configuration)
      	if(ipv6.head?.ipv6Address != null)
    {
		createSdIpAddressType[
  			ruleId = "ECUC_Sd_00149"
  			
         
		value = "SD_AF_INET6"
  	]
  	
  	  	fetch?.head?.networkEndpoint?.networkEndpointAddress?.forEach[Addr |

  	
  		createSdIpAddress[
  			ruleId = "ECUC_Sd_00148"
  			print(Addr?.toString)
  			value = ipv6.head.ipv6Address.toString
  		]
   		
   	]
   	}
   	else if(ipv4.head?.ipv4Address != null)
   	{
   		createSdIpAddressType[
  			ruleId = "ECUC_Sd_00149"
  			
         
		value = "SD_AF_INET"
  	]
  	
  	  	fetch?.head?.networkEndpoint?.networkEndpointAddress?.forEach[Addr |

  	
  		createSdIpAddress[
  			ruleId = "ECUC_Sd_00148"
  			print(Addr?.toString)
  			value = ipv4.head.ipv4Address.toString
  		]
   		
   	]
   	}
   	]
      	]
        
consumedServiceInstance?.localUnicastAddress?.forEach[Unicast |
	  if  (Unicast.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof TcpTp )
	  {
	  	
	  	createSdClientServiceTcpRef[
	  	ruleId = "ECUC_SD_00100"
        reference = getSoAdSocketConnectionGroup(Unicast?.applicationEndpoint)	
	  		
	  	]
	  }
	    if  (Unicast.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof UdpTp )
	  {
	  	
	  	createSdClientServiceUdpRef[
	  	ruleId = "ECUC_SD_00101"
        reference = getSoAdSocketConnectionGroup(Unicast?.applicationEndpoint)	
	  		
	  	]
	  	
	  	}
	
]


      
      
      
      
       
      
      val endPoint1 = consumedServiceInstance.eventMulticastSubscriptionAddress
     endPoint1?.forEach[Multi_ |
      	
        if (Multi_?.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof UdpTp)
        {
      
        createSdClientServiceMulticastRef [
        ruleId = "ECUC_Sd_00145"
        
       
   reference = getSoAdSocketConnectionGroup(Multi_?.applicationEndpoint)

      ]
      
       }
      ]
    

       

  
  val sdeventGroup=model.findAll(ConsumedEventGroup)
     sdeventGroup.forEach [ eventGroup |
        createSdConsumedEventGroup [
          ruleId = "ECUC_SD_00056"
          shortName = getUniqueShortName("SdConsumedEventGroup_") + eventGroup.shortName
          context = eventGroup
          
  
        ]
      ]
      
 	      /**FIX ME: revisit the mapping logic*/
      val serviceInstance = model.findAll(AbstractServiceInstance)
      consumedServiceInstance.methodActivationRoutingGroups?.forEach[ Al |
        createSdConsumedMethods [
          ruleId = "ECUC_SD_00099"
          shortName = "SdConsumedMethods_" + consumedServiceInstance.shortName
          createSdClientServiceActivationRef[
          	ruleId ="ECUC_SD_00102"
            reference = EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,Al)as SoAdRoutingGroup
          	
          ]
        ]
        ]
  
   
     } 

   } 
   

@Context(SomeipServiceVersion)
def dispatch init(SdBlocklistedVersions it)
{
	val blocklisted = context =>[notNull]
	createSdBlocklistedMinorVersions[
		ruleId = "ECUC_SD_00142"
		value = blocklisted .minorVersion
		 
	]

}

@Context(ApplicationEndpoint)
def dispatch init(SdClientServiceAllowedProvider it)
{
	val fe = model.findAll(Ipv4Configuration)
	val ipaddress = context =>[notNull]
	

	createSdIpAddress[
		ruleId = "ECUC_Sd_00148"
		value = fe.head?.ipv4Address?.toString
	
	]
	
	createSdIpAddressType[
		ruleId = "ECUC_Sd_00149"
		value = ipaddress?.adminData?.toString
	]
	
}
  @Context(TagWithOptionalValue)
  def dispatch init(SdClientCapabilityRecord it) {
    val tagwithOpVal = context => [notNull]
    createSdClientServiceCapabilityRecordValue [
      ruleId = "ECUC_SD_00074"
      value = tagwithOpVal.value
    ]

    createSdClientServiceCapabilityRecordKey [
      ruleId = "ECUC_SD_00073"
      value = tagwithOpVal.key
    ]
  }

  @Context(ConsumedEventGroup)
  def dispatch init(SdConsumedMethods it) {

    val consumedServiceInstance = context => [notNull]
    createSdClientServiceActivationRef [
      ruleId = "KSAR_ECUC_SD_00102"
    reference = EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,consumedServiceInstance?.consumedServiceInstance.methodActivationRoutingGroups?.head)as SoAdRoutingGroup
    ]
  }


  @Context(ConsumedEventGroup)
  def dispatch init(SdConsumedEventGroup it) {

    val consumedEventGroup = context => [notNull]
    createSdConsumedEventGroupTimerRef [
        ruleId = "ECUC_SD_00107"
      reference = findSdClientTimerByContext(consumedEventGroup?.sdClientTimerConfigs?.head?.someipSdClientEventGroupTimingConfig)
      ]
      
     createSdConsumedEventGroupAutoRequire[
     	ruleId="ECUC_SD_00144"
     	value = consumedEventGroup.autoRequire
     ]
      createSdConsumedEventGroupHandleId [
        ruleId = "KSAR_ECUC_SD_00116"
        value = nextId
      ]

    if(consumedEventGroup.isSetEventGroupIdentifier) {
    createSdConsumedEventGroupId [
      ruleId = "ECUC_SD_00057"
        value = consumedEventGroup.eventGroupIdentifier.intValue
    ]
    }
 consumedEventGroup.pduActivationRoutingGroups?.forEach[CMulti |
 
 	if(CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_MULTICAST )
 	{
 		createSdConsumedEventGroupMulticastActivationRef[
 			ruleId = "ECUC_SD_00106"
 			
 			reference =  EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,CMulti)as SoAdRoutingGroup
 		]
 	}
 	
 ]  
 consumedEventGroup?.eventMulticastAddress?.forEach[CoMult |
 	if(CoMult?.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof UdpTp)
 	{
 		createSdConsumedEventGroupMulticastGroupRef
 		[
 			ruleId = "ECUC_SD_00119"
 			reference = getSoAdSocketConnectionGroup(CoMult?.applicationEndpoint)
 			
 		]
 	}
 ]
 
 consumedEventGroup.pduActivationRoutingGroups?.forEach[CMulti |
 
 	if((CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_MULTICAST) ||(CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_UNICAST) || (CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_AND_TRIGGER_UNICAST)  )
 	{
 		createSdConsumedEventGroupTcpActivationRef[
 			ruleId = "ECUC_SD_00105"
 			
 			reference =  EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,CMulti)as SoAdRoutingGroup
 		]
 	}
 	
 ]  
 consumedEventGroup.pduActivationRoutingGroups?.forEach[CMulti |
 
 	if((CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_MULTICAST) ||(CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_UNICAST) || (CMulti?.eventGroupControlType == EventGroupControlTypeEnum?.ACTIVATION_AND_TRIGGER_UNICAST)  )
 	{
 		createSdConsumedEventGroupUdpActivationRef[
 			ruleId = "ECUC_SD_00104"
 			
 			reference =  EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,CMulti)as SoAdRoutingGroup
 		]
 	}
 	
 ]  

  }  


  @Context(UploadableDesignElement)
  def dispatch init(SdClientTimer it) {
    val sdClientConfig = context => [notNull]
   
    val requestResponseDelay=model.findAll(RequestResponseDelay)
val retry = model.findAll(SomeipSdClientEventGroupTimingConfig)
     createSdSubscribeEventgroupRetryDelay[
     	ruleId="ECUC_SD_00133"
     	value = retry.head.subscribeEventgroupRetryDelay
     	
     ]
     
     createSdSubscribeEventgroupRetryMax[
     	ruleId="ECUC_SD_00132"
     	value = retry.head.subscribeEventgroupRetryMax.intValue
     ]
  
    if(requestResponseDelay.head.maxValue!= null)
    {
    	createSdClientTimerRequestResponseMaxDelay [
      	ruleId = "ECUC_SD_00036"
      	value = requestResponseDelay.head.maxValue
    ]
    }
    
    if(requestResponseDelay.head.minValue != null)
    {
    	createSdClientTimerRequestResponseMinDelay [
        ruleId = "ECUC_SD_00064"
        value = requestResponseDelay.head.minValue
    ]
    
    }
val delay =  model?.findAll(InitialSdDelayConfig)
   if(delay.head?.initialDelayMinValue != null) {
    createSdClientTimerInitialFindDelayMin [
      ruleId = "ECUC_SD_00044"
      value = delay?.head?.initialDelayMinValue?.doubleValue    
    ]
    }


  if(delay.head?.initialDelayMaxValue != null){
    createSdClientTimerInitialFindDelayMax [
      ruleId = "ECUC_SD_00063"
      value = delay.head?.initialDelayMaxValue?.doubleValue
    ]
    }

   if(delay.head?.initialRepetitionsBaseDelay != null){
    createSdClientTimerInitialFindRepetitionsBaseDelay [
      ruleId = "ECUC_SD_00047"
      value = delay.head?.initialRepetitionsBaseDelay
    ]
    }

    if(delay.head?.initialRepetitionsMax != null){
    createSdClientTimerInitialFindRepetitionsMax [
      ruleId = "ECUC_SD_00046"
      value = delay.head?.initialRepetitionsMax?.intValue
    ]
    }

  }


  @Context(ProvidedServiceInstance)
  @SubContext(role = "connection", value = StaticSocketConnection)
  @SubContext(role = "bundle", value = StaticSocketConnection)
  def dispatch init(SdServerService it) {
    val providedServiceInstance = context => [notNull]
    if (providedServiceInstance != null) {
      
     val serverconfig=model.findAll(AbstractServiceInstance)
      if(providedServiceInstance.isSetMajorVersion){
      createSdServerServiceMajorVersion [
        ruleId = "ECUC_SD_00068"
        value =providedServiceInstance.majorVersion.intValue
      ]
      }
      
         

      createSdServerServiceAutoAvailable[
      	ruleId="ECUC_SD_00138"
      	value = providedServiceInstance?.autoAvailable
      ]

      if(providedServiceInstance.isSetMinorVersion){
      createSdServerServiceMinorVersion [
        ruleId = "ECUC_SD_00069"
        value = providedServiceInstance.minorVersion
      ]
      }
      
      
      if(providedServiceInstance.isSetServiceIdentifier) {
      createSdServerServiceId [
        ruleId = "ECUC_SD_00009"
        value = providedServiceInstance.serviceIdentifier.intValue
      ]
      }

      val serviceInstance = model.findAll(AbstractServiceInstance)
      if (serviceInstance.contains(providedServiceInstance)) {
        createSdProvidedMethods [
          ruleId = "ECUC_SD_00087"
          shortName = "SdProvidedMethods_" + providedServiceInstance.shortName
          context = providedServiceInstance
        ]


 
       
        val serviceInstance1 = model.findAll(AbstractServiceInstance)
        if (serviceInstance1.contains(providedServiceInstance))
        if(providedServiceInstance.isSetInstanceIdentifier){
        createSdServerServiceInstanceId [
          ruleId = "ECUC_SD_00011"
          value = providedServiceInstance.instanceIdentifier.intValue
        ]
        }
      }
    }
    
    providedServiceInstance.allowedServiceConsumers.forEach[ al |
   	createSdServerServiceAllowedConsumers[
   		ruleId = "ECUC_Sd_00155"
   		shortName = "SdServerServiceAllowedConsumers_"+ it.index
   		
   		   val fetch = model.findAll(ApplicationEndpoint)
      	   	val ipv4 = model.findAll(Ipv4Configuration)
      	   	val ipv6 = model.findAll(Ipv6Configuration)
      	if(ipv6.head?.ipv6Address != null)
    {
		createSdIpAddressType[
  			ruleId = "ECUC_Sd_00149"
  			
         
		value = "SD_AF_INET6"
  	]
  	
  	  	fetch?.head?.networkEndpoint?.networkEndpointAddress?.forEach[Addr |

  	
  		createSdIpAddress[
  			ruleId = "ECUC_Sd_00148"
  			value = ipv6.head.ipv6Address.toString
  		]
   		
   	]
   	}
   	else if(ipv4.head?.ipv4Address != null)
   	{
   		createSdIpAddressType[
  			ruleId = "ECUC_Sd_00149"
  			
         
		value = "SD_AF_INET"
  	]
  	
  	  	fetch?.head?.networkEndpoint?.networkEndpointAddress?.forEach[Addr |

  	
  		createSdIpAddress[
  			ruleId = "ECUC_Sd_00148"
  			value = ipv4.head.ipv4Address.toString
  		]
   		
   	]
   	}
   	]
      	]
   
      providedServiceInstance.eventHandlers.forEach [ event |
        createSdEventHandler [
          ruleId = "ECUC_SD_00055"
          shortName = getUniqueShortName("SdEventHandler_") + event.shortName
          context = event?.providedServiceInstance

  
         
        ]
      ]

      if(!(providedServiceInstance?.sdServerTimerConfigs.isNullOrEmpty))
    {    createSdServerServiceTimerRef [
        ruleId = "ECUC_SD_00086"
      reference = findSdServerTimerByContext(providedServiceInstance?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig,null)
      ]
      
      }


      createSdServerServiceHandleId [
        ruleId = "KSAR_ECUC_SD_00110"
        value = nextId
      ]

      providedServiceInstance.capabilityRecords.forEach [ record |
        createSdServerCapabilityRecord [
          ruleId = "ECUC_SD_00032"
          shortName = getUniqueShortName("SdServerCapabilityRecord_")
          context = record
        ]
      ]
val group = model.findAll(ConsumedProvidedServiceInstanceGroup)


group.forEach[CSI |
	
	 
	 
	 CSI?.providedServiceInstances?.forEach[  psi |
	 	if(psi?.providedServiceInstance == providedServiceInstance )
	{
		createSdServiceGroupRef[
			ruleId = "ECUC_SD_00136"
			reference = findSdServiceGroupByContext(psi?.consumedProvidedServiceInstanceGroup)
			
		]
		
		}
		]
		
	
	
]
       
       

 

if(providedServiceInstance.isSetLoadBalancingPriority)
{
	createSdServerServiceLoadBalancingPriority[
		ruleId = "ECUC_SD_00129"
		value = providedServiceInstance.loadBalancingPriority.intValue

	]
}
if(providedServiceInstance.isSetLoadBalancingWeight)
{
	createSdServerServiceLoadBalancingWeight[
		ruleId = "ECUC_SD_00130"
		value = providedServiceInstance.loadBalancingWeight.intValue
	]
}

   

       
    providedServiceInstance?.localUnicastAddress?.forEach[ Unicast |
  	if(Unicast?.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof TcpTp)
  	{
  		createSdServerServiceTcpRef[
  			ruleId = "KSAR_ECUC_SD_00088"
        reference = getSoAdSocketConnectionGroup(Unicast?.applicationEndpoint)
  			
  		]
  	}
  ]     
       
  providedServiceInstance?.localUnicastAddress?.forEach[ Unicast |
  	if(Unicast?.applicationEndpoint?.socketAddress?.applicationEndpoint?.tpConfiguration instanceof UdpTp)
  	{
  		createSdServerServiceUdpRef[
  			ruleId = "ECUC_SD_00089"
        reference = getSoAdSocketConnectionGroup(Unicast?.applicationEndpoint)
  			
  		]
  	}
  ]


 

    }
  



  @Context(ProvidedServiceInstance)
  def dispatch init( SdEventHandler it) {

     val providedServiceInstance = context => [notNull]
     var routinggroup = PduActivationRoutingGroup 
       var config=model.findAll(ApplicationEndpoint)
       var tpConfig = config
  providedServiceInstance?.eventHandlers?.forEach[Multi_|
  	Multi_?.pduActivationRoutingGroups?.forEach[ Multi |
  	if((Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.ACTIVATION_MULTICAST)|| (Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.ACTIVATION_UNICAST)||(Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.ACTIVATION_AND_TRIGGER_UNICAST)||(Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.TRIGGER_UNICAST))
  	{
  		createSdEventHandlerMulticast[
  		ruleId = "ECUC_SD_00094"
  		createSdEventActivationRef[
  			ruleId = "ECUC_SD_00096"
  			reference = EcucMappingExtensions?.findByEcucMappingContext(SoAdRoutingGroup,Multi) as SoAdRoutingGroup
  			
  		
  		]
 
createSdMulticastEventSoConRef[
	ruleId= "ECUC_SD_00118"
	reference = EcucMappingExtensions?.findByEcucMappingContext(SoAdSocketConnection,Multi_?.eventMulticastAddress?.head?.applicationEndpoint,null,null) 
	
]
	
  		]
  		createSdEventHandlerTcp[
  			ruleId = "ECUC_SD_00093"
  			createSdEventActivationRef[
  				ruleId = "ECUC_SD_00096"
  				reference =  EcucMappingExtensions?.findByEcucMappingContext(SoAdRoutingGroup,Multi) as SoAdRoutingGroup
  			]
  			
  			if((Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.TRIGGER_UNICAST)|| (Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.ACTIVATION_AND_TRIGGER_UNICAST))
  			{
  				createSdEventTriggeringRef[
  					ruleId = "ECUC_SD_00095"
  				reference =  EcucMappingExtensions?.findByEcucMappingContext(SoAdRoutingGroup,Multi) as SoAdRoutingGroup
  					
  				]
  			}
  			
  		]
  		
  		 		createSdEventHandlerUdp[
  			ruleId = "ECUC_SD_00092"
  			createSdEventActivationRef[
  				ruleId = "ECUC_SD_00096"
  				reference =  EcucMappingExtensions?.findByEcucMappingContext(SoAdRoutingGroup,Multi) as SoAdRoutingGroup
  			]
  			
  			if((Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.TRIGGER_UNICAST)|| (Multi?.eventGroupControlType  == EventGroupControlTypeEnum?.ACTIVATION_AND_TRIGGER_UNICAST))
  			{
  				createSdEventTriggeringRef[
  					ruleId = "ECUC_SD_00095"
  				reference =  EcucMappingExtensions?.findByEcucMappingContext(SoAdRoutingGroup,Multi) as SoAdRoutingGroup
  					
  				]
  			}
  			
  		]
  			
  			}	
  		
  		]
  		
  
  	
  ]
      createSdEventHandlerHandleId[
      	ruleId="KSAR_ECUC_SD_00112"
      	
      ]
      
          createSdEventHandlerEventGroupId[
     	ruleId="ECUC_SD_00061"
     	value = providedServiceInstance?.eventHandlers?.head?.eventGroupIdentifier?.intValue
     ]
    
      createSdEventHandlerTimerRef [
        ruleId = "ECUC_SD_00113"
        reference = findSdServerTimerByContext(providedServiceInstance.eventHandlers?.head?.sdServerEgTimingConfigs?.head?.someipSdServerEventGroupTimingConfig,null)
         
	
      ]
      
      createSdEventHandlerMulticastThreshold[
      	ruleId="ECUC_SD_00097"
      	value = providedServiceInstance?.eventHandlers?.head?.multicastThreshold?.intValue
      ]

      


  }
	
  @Context(ProvidedServiceInstance)
  def dispatch init(SdProvidedMethods it) {

    val providedServiceInstance = context => [notNull]
    
    createSdServerServiceActivationRef [
    ruleId = "ECUC_SD_00090"
      reference = EcucMappingExtensions.findByEcucMappingContext(SoAdRoutingGroup,providedServiceInstance?.methodActivationRoutingGroups?.head)as SoAdRoutingGroup

    ]

  }

  @Context(TagWithOptionalValue)
  def dispatch init(SdServerService.SdServerCapabilityRecord it) {
  	val tagWithOptionalVal = context => [notNull]
    createSdServerCapabilityRecordKey[
      ruleId = "ECUC_SD_00033"
      value = tagWithOptionalVal.key
    ]

    createSdServerCapabilityRecordValue [
      ruleId = "ECUC_SD_00034"
      value = tagWithOptionalVal.value
    ]
  }


  
 def getSoAdSocketConnectionGroup(ApplicationEndpoint  endPoint){
 
      val socket = model.findAll(StaticSocketConnection).findFirst[socketAddress.applicationEndpoint == endPoint]
      val socketBundle = model.findAll(StaticSocketConnection).findFirst[socketAddress.applicationEndpoint == endPoint]
      val CSI = model.findAll(ApplicationEndpoint).findFirst[socketAddress.applicationEndpoint == endPoint]
      var subContext = new HashMap<String, EObject>
      val string = new HashMap<String, Serializable>
      if (socket != null) {
    	subContext.put("connection", null);
    }
    if (socketBundle != null) {
    	subContext.put("bundle", socketBundle);
    }
    if(CSI != null)
    {
    	subContext.put("CSI",CSI)
    }
    if (subContext.isEmpty()) {
    	subContext = null;
    }
    
    if (CSI != null) {
     return EcucMappingExtensions.findByEcucMappingContext
    (SoAdSocketConnectionGroup, 
    	socket.socketAddress, socket.socketAddress, null, null);
  }
  
  }
  

/*
* This function finds whether SocketConnectionIpduIdentifier is present inside 
* SocketConnectionBundle 
* or SocketConnection for generation of parameter 
* SoAdRxSocketConnOrSocketConnBundleRef or 
* SoAdTxSocketConnOrSocketConnBundleRef
*/ 
	def ARObject getConnectionOrBundle(StaticSocketConnection identifier) {
		return model.findAll(StaticSocketConnection).findFirst[	IPduIdentifiers.contains(identifier)] ?:
			model.findAll(StaticSocketConnection).findFirst[IPduIdentifiers.contains(identifier)]
}
  



  def toConsumedEventGroupTcpActivation(ConsumedEventGroup evntGroup) {
    var applEndPoint = evntGroup?.consumedServiceInstance?.applicationEndpoint
    if (isType(TcpTp, applEndPoint)) {
      return evntGroup.pduActivationRoutingGroups.findFirst [
        eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_UNICAST)
      ]
    }
  }

  def isType(Class<?> class1, ApplicationEndpoint applEndPoint) {
    var bVal = false
    if (class1.isInstance(applEndPoint?.tpConfiguration)) {
      bVal = true
    }
    return bVal
  }

  def toConsumedEventGroupMulticastActivation(ConsumedEventGroup evntGroup) {
    return evntGroup.pduActivationRoutingGroups.findFirst [
      eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_MULTICAST)
    ]
  }

  def toConsumedEventGroupUdpActivation(ConsumedEventGroup evntGroup) {
    var applEndPoint = evntGroup?.consumedServiceInstance?.applicationEndpoint
    if (isType(UdpTp, applEndPoint)) {
      return evntGroup.pduActivationRoutingGroups.findFirst [
        eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_UNICAST)
      ]
    }
  }
  def toEventHandlerMulticastActivation (ConsumedEventGroup evntGroup ){
    {
      return evntGroup.pduActivationRoutingGroups.findFirst [
        (eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_UNICAST)) ||
                (eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_MULTICAST))||
                    (eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_AND_TRIGGER_UNICAST))
              ]
            }
          }
          
    def toEventHandlerMulticastTriggering (ConsumedEventGroup evntGroup ){
    {
      return evntGroup.pduActivationRoutingGroups.findFirst [
        (eventGroupControlType.equals(EventGroupControlTypeEnum.TRIGGER_UNICAST)) ||
                    (eventGroupControlType.equals(EventGroupControlTypeEnum.ACTIVATION_AND_TRIGGER_UNICAST))
              ]
            }
          }
          
          
          
    def Iterable<IPduPort> getOutPorts(PduTriggering pduTriggering)
  {
    if(pduTriggering == null) return null

    return pduTriggering.getIPduPorts.sortBy[shortName].filter [communicationDirection == 
    	CommunicationDirectionType.OUT
    ]
  }

  def Iterable<IPduPort> getInPorts(PduTriggering pduTriggering)
  {
    if(pduTriggering == null) return null
    return pduTriggering.getIPduPorts.sortBy[shortName].filter [communicationDirection == CommunicationDirectionType.IN]
  }
  def TransportProtocolConfiguration toUdpOrTcp(GARObject context) {
    if (context instanceof SocketAddress) {
      var tpConfig = context?.applicationEndpoint?.tpConfiguration
      return tpConfig
    } else if (context instanceof StaticSocketConnection) {
      var tpConfig = context.socketAddress?.applicationEndpoint?.tpConfiguration
      return tpConfig
    }
  }
  	def getSdInstanceUnicastRxPduId() {
		return nSdInstanceUnicastRxPduId++
	}
	
	def getSdInstanceMulticastRxPduId() {
		return nSdInstanceMulticastRxPduId++
	}

  /**************************** Auto Select Method ***************************/
  override doAutoSelect(ModelIndex model) {
    return ((model.findFirst(SomeipSdServerServiceInstanceConfig) != null)||
      (model.findFirst(SomeipSdClientServiceInstanceConfig) != null) || (model.findFirst(ConsumedServiceInstance) != null)||
      (model.findFirst(ProvidedServiceInstance) != null))
  }
  
  override regenerateHandleIds(EcucModuleConfigurationValues module) {
  if (module instanceof Sd) {
      module.regenerateSdClientServiceHandleId
      module.regenerateSdConsumedEventGroupHandleId
      module.regenerateSdServerServiceHandleId
      module.regenerateSdEventHandlerHandleId
      
      
    }
    }
    
   def regenerateSdClientServiceHandleId(Sd sd) {
   
    sd.sdConfig.sdInstances.map[sdClientServices]?.flatten?.forEach[it, newIndex | sdClientServiceHandleId = newIndex]
    
   }
   
   def regenerateSdConsumedEventGroupHandleId(Sd sd){
   	sd.sdConfig.sdInstances.map[sdClientServices]?.flatten?.map[sdConsumedEventGroups]?.flatten?.forEach[
   		it, newIndex | sdConsumedEventGroupHandleId = newIndex
   	]
   }
   
   def regenerateSdServerServiceHandleId(Sd sd){
   	sd.sdConfig.sdInstances.map[sdServerServices]?.flatten?.forEach[it, newIndex | sdServerServiceHandleId = newIndex]
   }
   
   def regenerateSdEventHandlerHandleId(Sd sd){
   	sd.sdConfig.sdInstances.map[sdServerServices]?.flatten?.map[sdEventHandlers]?.flatten?.forEach[
   		it, newIndex | sdEventHandlerHandleId = newIndex
   	]
   }
   def regenerateSdServiceGroupHandleId(Sd sd) 
   {
   	sd.sdConfig?.sdServiceGroups_PB?.filterNull?.forEach[it,newIndex | sdServiceGroupHandleId = newIndex]
   }
}
