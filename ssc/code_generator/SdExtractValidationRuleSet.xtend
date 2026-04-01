/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name    : SdExtractValidationRuleSet.xtend
 *
 * Description  : This file contains all validation error checking methods.
 */


/*
 * Revision History:
 * Date            Changed By             Description
 * 07-July-2025    Samarth Golwalker  Migration Release R24-11.

 */
package com.kpit.c4k.bsw.sd.validation

import autosar40.system.fibex.fibex4ethernet.serviceinstances.AbstractServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ConsumedServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.ProvidedServiceInstance
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdClientServiceInstanceConfig
import autosar40.system.fibex.fibex4ethernet.ethernettopology.NetworkEndpoint
import autosar40.system.fibex.fibex4ethernet.serviceinstances.RequestResponseDelay
import autosar40.system.fibex.fibex4ethernet.serviceinstances.SomeipSdServerServiceInstanceConfig

import com.kpit.c4k.core.validation.rules.ValidationRule
import com.kpit.c4k.core.validation.rules.ValidationRuleset
import java.util.ArrayList
import org.eclipse.emf.validation.internal.modeled.model.validation.ModeEnum
import org.eclipse.emf.validation.model.ConstraintSeverity



import static extension org.eclipse.emf.validation.internal.modeled.model.validation.ModeEnum.*
import static extension org.eclipse.emf.validation.model.ConstraintSeverity.*

class SdExtractValidationRuleSet extends ValidationRuleset{

/*
 *  Design ID: SD_SDD_6001
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17001,
    name="Check for autoRequire",
    description="To validate autoRequire for Harmonization of 
                 SdClientServiceAutoRequire Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_1(ConsumedServiceInstance AutoRequire ){
    
    if (AutoRequire.autoRequire === null)
    {
        return #["The SdClientServiceAutoRequire (ECUC_SD_00143 ) shall be harmonized with 
        default value false consider from SWS for SdClientService corresponding "
        +AutoRequire.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +AutoRequire.shortName]
        
    }
  }

/*
 *  Design ID: SD_SDD_6002
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17002,
    name="Check for capabilityRecord",
    description="To validate autoRequire for Harmonization of 
                 SdClientServiceCapabilityRecordKey Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_2(ConsumedServiceInstance capabilityrecords_ ){
 var errmsg = new ArrayList<String>()
 if(!capabilityrecords_?.capabilityRecords?.nullOrEmpty)
 {
 	
 	for (Cap :capabilityrecords_?.capabilityRecords)
 	{
 		if(Cap?.key?.nullOrEmpty )
 		{
 		errmsg?.add("The M2 Parameter TagWithOptionalValue.key is required to harmonize
               mandatory ECUC parameter SdClientServiceCapabilityRecordKey (ECUC_SD_00073).
               configure attribute SdClientCapabilityRecord for "+capabilityrecords_.shortName+" in ECUC Extract")
 		}
 		
 	
 	}
 }
 		


    if(errmsg.size >= 1){
     return #[errmsg.join(" ")]} 	
 
    

 

 
}

/*
 *  Design ID: SD_SDD_6003
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17003,
    name="Check for SdClientServiceAllowedProvider",
    description="To validate networkEndpoint for Harmonization of 
                 SdClientServiceAllowedProvider Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_3(ConsumedServiceInstance ConsumedAllowed ){
 var errmsg = new ArrayList<String>()
 if(!ConsumedAllowed?.allowedServiceProviders?.nullOrEmpty)
 {
 	
 	for (Cap :ConsumedAllowed?.allowedServiceProviders)
 	{
 		if(Cap?.networkEndpoint === null)
 		{
 		errmsg?.add("The M2 Parameter ApplicationEndpoint.networkEndpoint is required to harmonize
                     mandatory ECUC parameter SdClientServiceAllowedProvider (ECUC_Sd_00148).
                     configure attribute SdClientServiceAllowedProvider for "+ConsumedAllowed.shortName+" in ECUC Extract")
 		}
 		
 
 		
 	}
 }
 		


  
 
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}   

 

 
}


/*
 *  Design ID: SD_SDD_6004
 *  description: Check for SdClientServiceId.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17004,
    name="Check for serviceIdentifier",
    description="To validate ConsumedServiceInstance.serviceIdentifier for Harmonization of 
                SdClientServiceId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_4(ConsumedServiceInstance ServiceIdentifier ){

 if(ServiceIdentifier?.serviceIdentifier === null)
 		{
 		   return #["The SdClientServiceId (ECUC_SD_00020 ) shall be harmonized with 
         value between 0 to 65534 consider from SWS  for SdClientServiceId corresponding "
        +ServiceIdentifier.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +ServiceIdentifier.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID: SD_SDD_6005
 *  description: Check for SdClientServiceInstanceId.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17005,
    name="Check for InstanceIdentifier",
    description="To validate ConsumedServiceInstance.InstanceIdentifier for Harmonization of 
                SdClientServiceInstanceId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_5(ConsumedServiceInstance InstanceIdentifier ){

 if(InstanceIdentifier?.instanceIdentifier?.nullOrEmpty)
 		{
 		   return #["The SdClientServiceInstanceId (ECUC_SD_00022 ) shall be harmonized with 
         value between 0 to 65535 consider from SWS  for SdClientServiceInstanceId corresponding "
        +InstanceIdentifier.shortName+ "as attribute SdClientServiceInstanceId is not configured for"
        +InstanceIdentifier.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}


/*
 *  Design ID: SD_SDD_6006
 *  description: Check for SdClientServiceMajorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17006,
    name="Check for majorVersion",
    description="To validate :AbstractServiceInstance.majorVersion for Harmonization of 
                SdClientServiceMajorVersion  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_6(ConsumedServiceInstance Major ){

 if(Major?.majorVersion?.intValue > 255)
 		{
 		   return #["The SdClientMajorVersion(ECUC_SD_00070 ) shall be harmonized with 
         value between 0 .. 254 consider from SWS  for SdClientServiceMajorVersion corresponding "
        +Major.shortName+ "as attribute SdClientServiceMajorVersion is not configured for"
        +Major.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID: SD_SDD_6007
 *  description: Check for SdClientServiceMinorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17007,
    name="Check for minorVersion",
    description="To validate ConsumedServiceInstance.minorVersion for Harmonization of 
                SdClientServiceMinorVersion  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_7(ConsumedServiceInstance Minor ){

     if(Minor?.minorVersion?.toString > "255" )
 		{
 		   return #["The SdClientServiceMinorVersion (ECUC_SD_00071 ) shall be harmonized with 
         value between 0 .. 254 consider from SWS  for SdClientServiceMinorVersion corresponding "
        +Minor.shortName+ "as attribute SdClientServiceMinorVersion is not configured for"
        +Minor.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}


/*
 *  Design ID: SD_SDD_6008
 *  description: Check for SdClientTimer.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17008,
    name="Check for sdClientTimerConfigs",
    description="To validate ConsumedServiceInstance.sdClientTimerConfigs for Harmonization of 
                SdClientTimer  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_8(ConsumedServiceInstance Minor ){

 if(Minor?.sdClientTimerConfigs?.head?.someipSdClientServiceInstanceConfig === null)
 		{
 		   return #["The SdClientTimer (ECUC_SD_00043 ) shall be harmonized  
          consider from SWS  for SdClientTimer corresponding "
        +Minor.shortName+ "as attribute SdClientTimer is not configured for"
        +Minor.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID: SD_SDD_6009
 *  description: Check for SdConsumedEventGroupAutoRequire.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17009,
    name="Check for ConsumedEventGroup.autoRequire",
    description="To validate ConsumedEventGroup.autoRequire for Harmonization of 
                SdConsumedEventGroupAutoRequire  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_9(ConsumedServiceInstance Consumed ){
 var errmsg = new ArrayList<String>()
 if(!Consumed?.consumedEventGroups?.nullOrEmpty)
 {
 	
 	for (Cap :Consumed?.consumedEventGroups)
 	{
 		if(Cap?.autoRequire === null)
 		{
 		errmsg?.add("The SdConsumedEventGroupAutoRequire (ECUC_SD_00144 ) shall be harmonized with 
        default value false consider from SWS  for SdConsumedEventGroupAutoRequire corresponding "
        +Cap.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +Cap.shortName)
                  
 		}
 		
 
 		
 	}
 }
 	
 	
 	
 		
 
 		
  if(errmsg.size >= 1){
     return #[errmsg.join(" ")]} 	
 
}

/*
 *  Design ID: SD_SDD_6010
 *  description: Check for SdClientServiceMajorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17010,
    name="Check for ConsumedEventGroup.eventGroupIdentifier",
    description="To validate ConsumedEventGroup.eventGroupIdentifier for Harmonization of 
                SdConsumedEventGroupId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_10(ConsumedServiceInstance Consumed ){
 var errmsg = new ArrayList<String>()
 if(!Consumed?.consumedEventGroups?.nullOrEmpty)
 {
 	
 	for (Cap :Consumed?.consumedEventGroups)
 	{
 		print(Cap?.eventGroupIdentifier?.intValue)
 		if((Cap?.eventGroupIdentifier?.intValue > 65534  ))
 		{
 		errmsg?.add("The SdConsumedEventGroupId (ECUC_SD_00057 ) shall be harmonized with 
        default value false consider from SWS  for eventGroupIdentifier corresponding "
        +Cap.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +Cap.shortName)
                  
 		}
 		
 
 		
 	}
 }
  if(errmsg.size >= 1){
     return #[errmsg.join(" ")]} 
 }
 	
/*
 *  Design ID: SD_SDD_6011
 *  description: Check for SdClientServiceMajorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17011,
    name="Check for ConsumedEventGroup.pduActivationRoutingGroup",
    description="To validate pduActivationRoutingGroup for Harmonization of 
                SdConsumedEventGroupMulticastActivationRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_11(ConsumedServiceInstance Consumed ){
 var errmsg = new ArrayList<String>()
 if(!Consumed?.consumedEventGroups?.nullOrEmpty)
 {
 	
 	for (Cap :Consumed?.consumedEventGroups)
 	{
 		if(Cap?.pduActivationRoutingGroups === null)
 		{
 			
 			   
 				errmsg?.add("The SdConsumedEventGroupMulticastActivationRef (ECUC_SD_00106 ) shall be harmonized with 
        default value false consider from SWS  for SdConsumedEventGroup corresponding "
        +Cap.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +Cap.shortName)
 		
 		
                  
 		}
 		
 
 		
 	}
 } 	
 	
 		
 
  if(errmsg.size >= 1){
     return #[errmsg.join(" ")]} 		
 	
 
}

/*
 *  Design ID: SD_SDD_6012
 *  description: Check for SdConsumedEventGroupTimerRef.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17012,
    name="Check for SdConsumedEventGroupTimerRef",
    description="To validate sdClientTimerConfig Mapping Rule Mapping T for Harmonization of 
                SdConsumedEventGroupTimerRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_12(ConsumedServiceInstance Consumed ){
 var errmsg = new ArrayList<String>()
 if(!Consumed?.consumedEventGroups?.nullOrEmpty)
 {
 	
 	for (Cap :Consumed?.consumedEventGroups)
 	{
 		if(Cap?.sdClientTimerConfigs?.head.someipSdClientEventGroupTimingConfig === null)
 		{
 			
 			   
 				errmsg?.add("The SdConsumedEventGroupTimerRef (ECUC_SD_00107 ) shall be harmonized with 
        default value false consider from SWS  for SdConsumedEventGroup corresponding "
        +Cap.shortName+ "as attribute ConsumedServiceInstance is not configured for"
        +Cap.shortName)
 		
 		
                  
 		}
 		
 
 		
 	}
 } 	
 	
 		
 
 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]} 		
 	
 
}

/*
 *  Design ID: SD_SDD_6013
 *  description: Check for SdClientServiceActivationRef.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17013,
    name="Check for SdConsumedMethods",
    description="To validate AbstractServiceInstance.methodActivationRoutingGroup Mapping Rule Mapping T for Harmonization of 
                SdClientServiceActivationRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_13(ConsumedServiceInstance Consumed ){
 var errmsg = new ArrayList<String>()
 if(Consumed?.methodActivationRoutingGroups?.nullOrEmpty)
 {
 	

 			
 	
 		   return #["The methodActivationRoutingGroup (ECUC_SD_00102 ) shall be harmonized  
          consider from SWS  for SdClientServiceActivationRef corresponding "
        +Consumed.shortName+ "as attribute SdClientSdClientServiceActivationRef Timer is not configured for"
        +Consumed.shortName]
 		
 		
                  
 		
 		
 
 		
 	}
 	
 	}
 	
 	/*
 *  Design ID: SD_SDD_6014
 *  description: Check for SdClientServiceMajorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17014,
    name="Check for SdClientTimer",
    description="To validate :SomeipSdClientServiceInstanceConfig.serviceFindTimeToLive Mapping Rule Mapping  for Harmonization of 
                SdClientTimerTTL  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_14(SomeipSdClientServiceInstanceConfig Consumed ){
 var errmsg = new ArrayList<String>()
 if((Consumed?.serviceFindTimeToLive?.intValue )=== 0 ||(Consumed?.serviceFindTimeToLive?.intValue > 16777215))
 {
 	

 			
 	
 		   return #["The serviceFindTimeToLive (ECUC_SD_00075 ) shall be harmonized  
          consider from SWS  for SdClientTimerTTL corresponding "
        +Consumed.shortName+ "as attribute SdClientTimerTTL Timer is not configured for"
        +Consumed.shortName]
 		
 		
                  
 		
 		
 
 		
 	}
 	
 	}
 
 /*
 *  Design ID: SD_SDD_6015
 *  description: Check for SdEventHandlerEventGroupId.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17015,
    name="Check for SdEventHandlerEventGroupId",
    description="To validate eventGroupIdentifier Mapping Rule Mapping T for Harmonization of 
                SdEventHandlerEventGroupId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_15(ProvidedServiceInstance    PSI){
 var errmsg = new ArrayList<String>()
 if(!PSI?.eventHandlers.nullOrEmpty)
 {
 	
for(Eventgrp:PSI?.eventHandlers)
{
	if(Eventgrp?.eventGroupIdentifier?.intValue > 65534)
	{
		   errmsg.add("The EventHandler.eventGroupIdentifier (ECUC_SD_00061 ) shall be harmonized  
          consider from SWS  for SdEventHandlerEventGroupId corresponding "
        +Eventgrp.shortName+ "as attribute SdEventHandlerEventGroupId Timer is not configured for"
        +Eventgrp.shortName)
	}
}
 			
 	
 		
 		
 		
                  
 		
 		
 
 		
 	}
 	 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}
 
 	
 		
 
 		
 	
 

}

/*
 *  Design ID:
 *  description: Check for multicastThreshold.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17016,
    name="Check for SdEventHandlerMulticastThreshold",
    description="To validate multicastThreshold Mapping Rule Mapping T for Harmonization of 
                SdEventHandlerMulticastThreshold  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_16(ProvidedServiceInstance    PSI){
 var errmsg = new ArrayList<String>()
 if(!PSI?.eventHandlers.nullOrEmpty)
 {
 	
for(Eventgrp:PSI?.eventHandlers)
{
	if(Eventgrp?.multicastThreshold?.intValue > 65534)
	{
		   errmsg.add("The EventHandler.multicastThreshold (ECUC_SD_00097 ) shall be harmonized  
          consider from SWS  for SdEventHandlerMulticastThreshold corresponding "
        +Eventgrp.shortName+ "as attribute multicastThreshold is not configured for"
        +Eventgrp.shortName)
	}
}
 			
 	
 		
 		
 		
                  
 		
 		
 
 		
 	}
 	 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}
 
 	
 		
 
 		
 	
 

}

/*
 *  Design ID: SD_SDD_6017
 *  description: Check for multicastThreshold.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17017,
    name="Check for SdMulticastEventSoConRef",
    description="To validate eventGroupIdentifier Mapping Rule Mapping T for Harmonization of 
                SdMulticastEventSoConRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_17(ProvidedServiceInstance    PSI){
 var errmsg = new ArrayList<String>()
 if(!PSI?.eventHandlers.nullOrEmpty)
 {
 	
for(Eventgrp:PSI?.eventHandlers)
{
	if(Eventgrp?.eventMulticastAddress?.head?.applicationEndpoint === null)
	
	{
	  
				 errmsg.add("The eventMulticastAddress (ECUC_SD_00118 ) shall be harmonized  
          consider from SWS  for SdMulticastEventSoConRef corresponding "
        +Eventgrp.shortName+ "as attribute multicastThreshold is not configured for"
        +Eventgrp.shortName)}
			
			
		
		  
		
	}
}
 			
 	
 		
 		
 		
                  
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}
 	
 		
 
 		
 	}
 	
 
 
 	
 		
 
 		
/*
 *  Design ID: SD_SDD_6018
 *  description: Check for multicastThreshold.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17018,
    name="Check for SdEventHandlerMulticastThreshold",
    description="To validate eventGroupIdentifier Mapping Rule Mapping T for Harmonization of 
                SdEventHandlerEventGroupId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_18(AbstractServiceInstance    PSI){
 var errmsg = new ArrayList<String>()
 if(PSI?.methodActivationRoutingGroups.nullOrEmpty)
 {
 	

	
	  
				 errmsg.add("The methodActivationRoutingGroup (ECUC_SD_00090 ) shall be harmonized  
          consider from SWS  for ECUC SdServerServiceActivationRef corresponding "
        +PSI.shortName+ "as attribute methodActivationRoutingGroup is not configured for"
        +PSI.shortName)
			
			
		
		  
		
	
}
 			
 	
 		
 		
 		
                  
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}
 	
 		
 
 		
 	} 	
 	
 	
 	
/*
 *  Design ID:
 *  description: Check for SdServerCapabilityRecordKey.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17019,
    name="Check for capabilityRecord",
    description="To validate autoRequire for Harmonization of 
                 SdServerCapabilityRecordKey Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_19(ProvidedServiceInstance capabilityrecords_ ){
 var errmsg = new ArrayList<String>()
 if(!capabilityrecords_?.capabilityRecords?.nullOrEmpty)
 {
 	
 	for (Cap :capabilityrecords_?.capabilityRecords)
 	{
 		if(Cap?.key?.toString?.nullOrEmpty)
 		{
 		errmsg?.add("The M2 Parameter TagWithOptionalValue.key is required to harmonize
               mandatory ECUC parameter SdServerCapabilityRecordKey (ECUC_SD_00033).
               configure attribute SdClientCapabilityRecord for "+capabilityrecords_.shortName+" in ECUC Extract")
 		}
 		
 		
 		
 	}
 }
 		


  
    

 
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}
 	
 
}

 /*
 *  Design ID: SD_SDD_6020
 *  description: Check for ApplicationEndpoint.
 *  @param : SdServerServiceAllowedConsumers 
 *  @return: String
 */

  @ValidationRule(
    code=17020,
    name="Check for SdServerServiceAllowedConsumers",
    description="To validate networkEndpoint for Harmonization of 
                 SdIpAddress Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_20(ProvidedServiceInstance ConsumedAllowed ){
 var errmsg = new ArrayList<String>()
 if(!ConsumedAllowed?.allowedServiceConsumers?.nullOrEmpty)
 {
 	
 	for (Cap :ConsumedAllowed?.allowedServiceConsumers)
 	{
 		if(Cap?.networkEndpoint === null)
 		{
 		errmsg?.add("The M2 Parameter ApplicationEndpoint.networkEndpoint is required to harmonize
               mandatory ECUC parameter SdIpAddress (ECUC_Sd_00148).
               configure attribute SdServerServiceAllowedConsumers for "+ ConsumedAllowed.shortName+" in ECUC Extract")
 		}
 		}
 }
 		


  
 
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}   

 

 
}


 /*
 *  Design ID: SD_SDD_6021
 *  description: Check for networkEndpoint.
 *  @param : SdIpAddressType 
 *  @return: String
 */

  @ValidationRule(
    code=17021,
    name="Check for NetworkEndpoint",
    description="To validate networkEndpoint for Harmonization of 
                 SdIpAddress Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_21(ProvidedServiceInstance ConsumedAllowed ){
 var errmsg = new ArrayList<String>()
 if(!ConsumedAllowed?.allowedServiceConsumers?.nullOrEmpty )
 {
 	
 	for (Cap :ConsumedAllowed?.allowedServiceConsumers)
 	{
 		if(Cap?.networkEndpoint?.networkEndpointAddress === null)
 		{
 		errmsg?.add("The M2 Parameter ApplicationEndpoint.networkEndpoint is required to harmonize
               mandatory ECUC parameter SdIpAddressType (ECUC_Sd_00149).
               configure attribute SdServerServiceAllowedConsumers for "+ConsumedAllowed.shortName+" in ECUC Extract")
 		}
 		
 
 		
 	}
 }
 		


  
 
 			 if(errmsg.size >= 1){
     return #[errmsg.join(" ")]
 	
 	}   

 

 
}
 /*
 *  Design ID: SD_SDD_6022
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17022,
    name="Check for autoRequire",
    description="To validate autoRequire for Harmonization of 
                 SdServerServiceAutoAvailable Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_22(ProvidedServiceInstance AutoRequire ){
    
    if (AutoRequire.autoAvailable === null)
    {
        return #["The SdServerServiceAutoAvailable (ECUC_SD_00138 ) shall be harmonized with 
        default value false consider from SWS  for SdClientService corresponding "
        +AutoRequire.shortName+ "as attribute ProvidedServiceInstance is not configured for"
        +AutoRequire.shortName]
        
    }
  }

 /*
 *  Design ID: SD_SDD_6023
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17023,
    name="Check for :ProvidedServiceInstance.serviceIdentifier",
    description="To validate :ProvidedServiceInstance.serviceIdentifier for Harmonization of 
                 SdServerServiceId Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_23(ProvidedServiceInstance AutoRequire ){
    
    if (AutoRequire.serviceIdentifier === null)
    {
        return #["The ProvidedServiceInstance.serviceIdentifier (ECUC_SD_00009 ) shall be harmonized with 
        default value false consider from SWS  for SdServerServiceId corresponding "
        +AutoRequire.shortName+ "as attribute  ProvidedServiceInstance.serviceIdentifier is not configured for"
        +AutoRequire.shortName]
        
    }
  }

/*
 *  Design ID: SD_SDD_6024
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17024,
    name="Check for :ProvidedServiceInstance.instanceIdentifier",
    description="To validate :ProvidedServiceInstance.instanceIdentifier for Harmonization of 
                 SdServerServiceInstanceId Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_24(ProvidedServiceInstance AutoRequire ){
    
    if (AutoRequire?.instanceIdentifier?.intValue > 65534)
    {
        return #["The::ProvidedServiceInstance.instanceIdentifier (ECUC_SD_00011 ) shall be harmonized with 
        default value false consider from SWS  for SdServerServiceInstanceId corresponding "
        +AutoRequire.shortName+ "as attribute  ProvidedServiceInstance.instanceIdentifier is not configured for"
        +AutoRequire.shortName]
        
    }
  }

/*
 *  Design ID: SD_SDD_6025
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: Strings
 */

  @ValidationRule(
    code=17025,
    name="Check for AbstractServiceInstance.majorVersion",
    description="To validate AbstractServiceInstance.majorVersion for Harmonization of 
                 SdServerServiceMajorVersion Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_25(ProvidedServiceInstance AutoRequire ){
    
    if (AutoRequire.majorVersion?.intValue > 254)
    {
        return #["The::ProvidedServiceInstance.majorVersion (ECUC_SD_00068 ) shall be harmonized with 
        default value false consider from SWS  for SdServerServiceMajorVersion corresponding "
        +AutoRequire.shortName+ "as attribute AbstractServiceInstance.majorVersion is not configured for"
        +AutoRequire.shortName]
        
    }
  }


/*
 *  Design ID: SD_SDD_6026
 *  description: Check for Sd_ClientService.
 *  @param : AutoRequire 
 *  @return: String
 */

  @ValidationRule(
    code=17026,
    name="Check for AbstractServiceInstance.minorVersion",
    description="To validate :ProvidedServiceInstance.minorVersion for Harmonization of 
                 SdServerServiceMinorVersion Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_26(ProvidedServiceInstance AutoRequire ){
 
    if (AutoRequire.minorVersion. longValue > (4294967295L)  )
    {
    	 
        return #["The ProvidedServiceInstance.minorVersion (ECUC_SD_00069 ) shall be harmonized  
         consider from SWS  for SdServerServiceMinorVersion corresponding "
        +AutoRequire.shortName+ "as attribute AbstractServiceInstance.minorVersion is not configured for"
        +AutoRequire.shortName]
        
    }
  }



/*
 *  Design ID: SD_SDD_6027
 *  description: Check for sdServerTimerConfig.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17027,
    name="Check for sdClientTimerConfigs",
    description="To validate ProvidedServiceInstance.sdServerTimerConfig for Harmonization of 
                SdServerServiceTimerRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_27(ProvidedServiceInstance PSI ){

 if(PSI?.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig=== null)
 		{
 		   return #["The sdServerTimer (ECUC_SD_00086 ) shall be harmonized  
          consider from SWS  for sdServerTimer corresponding "
        +PSI.shortName+ "as attribute sdServerTimerConfigs is not configured for"
        +PSI.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID: SD_SDD_6028
 *  description: Check for RequestResponseDelay.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17028,
    name="Check for RequestResponseDelay",
    description="To validate maxValue for Harmonization of 
                SdServerTimerRequestResponseMaxDelay  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_28(ProvidedServiceInstance Minor ){

       if(Minor.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.requestResponseDelay?.maxValue  > 16777215)
 		{
 		   return #["The SdServerTimer (ECUC_SD_00114 ) shall be harmonized  
          consider from SWS  for SdServerTimerRequestResponseMaxDelay corresponding "
        +Minor?.shortName+ "as attribute maxValue is not configured for"
        +Minor?.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID: SD_SDD_6029
 *  description: Check for SdClientServiceMajorVersion.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17029,
    name="Check for minValue",
    description="To validate ProvidedServiceInstance.sdServerTimerConfig for Harmonization of 
                SdServerTimerRequestResponseMinDelay  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_29(ProvidedServiceInstance Minor ){

 if(Minor.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.requestResponseDelay?.minValue  > 16777215)
 		{
 		   return #["The minValue (ECUC_SD_00115 ) shall be harmonized  
          consider from SWS  for SdServerTimerRequestResponseMinDelay corresponding "
        +Minor.shortName+ "as attribute minValue is not configured for"
        +Minor.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}


/*
 *  Design ID: SD_SDD_6030
 *  description: Check for SdServerTimerTTL.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17030,

    name="Check for SdServerTimerTTL",
    description="To validate :SomeipSdServerServiceInstanceConfig.ServiceOfferTimeToLive
 for Harmonization of SdServerServiceTimerRef  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_30(ProvidedServiceInstance Minor ){

if(Minor.sdServerTimerConfigs?.head?.someipSdServerServiceInstanceConfig?.serviceOfferTimeToLive  > 16777215)
 		{
 		   return #["The :SomeipSdServerServiceInstanceConfig.serviceOfferTimeToLive (ECUC_SD_00037 ) shall be harmonized  
          consider from SWS  for SdServerTimerTTL corresponding "
        +Minor.shortName+ "as attribute serviceOfferTimeToLive is not configured for"
        +Minor.shortName]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

/*
 *  Design ID:
 *  description: Check for InstanceIdentifier.
 *  @param : serviceIdentifier 
 *  @return: String
 */

  @ValidationRule(
    code=17031,

    name="Check for InstanceIdentifier",
    description="To validate ConsumedServiceInstance.InstanceIdentifier for Harmonization of 
                SdClientServiceInstanceId  Parameter",
    message="{0}",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.INFO)

  def static Object[] Ecu_ExtractValidation_Rule_34(ConsumedServiceInstance InstanceIdentifier ){

 if(!InstanceIdentifier?.instanceIdentifier?.nullOrEmpty)
 		{
 			if(InstanceIdentifier?.instanceIdentifier.startsWith("0x"))
 		   return #["The SdClientServiceInstanceId (ECUC_SD_00022 ) shall be harmonized with 
         value between 0 to 65535 consider from SWS  for SdClientServiceInstanceId corresponding "
        +InstanceIdentifier.shortName+ "as attribute SdClientServiceInstanceId is not configured for"
        +InstanceIdentifier.shortName+"The given input should be in integer form eg.1234 not in 0x1234"]
 		}
 	
 	
 	
 		
 
 		
 	
 
}

}






