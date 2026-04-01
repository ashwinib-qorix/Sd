/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name     : SdValidation.xtend
 *
 * Description   : This file includes validation checks for Sd module.
 *
 */

/*
 * Revision History:
 * Date            Changed By             Description
 * 07-July-2025    Samarth Golwalker  Migration Release R24-11.

 */


package com.kpit.c4k.bsw.sd.validation

import com.kpit.c4k.core.extensions.NumberExtensions
import com.kpit.c4k.core.model.AutosarModelExtensions
import com.kpit.c4k.core.validation.rules.ValidationRule
import com.kpit.c4k.core.validation.rules.ValidationRuleset
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceTcpRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceTimerRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdClientServiceUdpRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdConsumedEventGroup.SdConsumedEventGroupMulticastGroupRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdClientService.SdConsumedEventGroup.SdConsumedEventGroupTimerRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdInstanceMulticastRxPdu.SdRxPduRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdInstanceTxPdu.SdTxPduRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdEventHandler.SdEventHandlerTimerRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdServerServiceTcpRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdServerServiceTimerRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdInstance.SdServerService.SdServerServiceUdpRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdPduRoute.SoAdTxPduRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdSocketConnectionGroup.SoAdSocketLocalAddressRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.SoAd.SoAdConfig.SoAdSocketRoute.SoAdSocketRouteDest.SoAdRxPduRef
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.TcpIp
import com.kpit.c4k.ecuc.vh.VariantHandlingExtensions
import java.util.ArrayList
import org.eclipse.emf.validation.internal.modeled.model.validation.ModeEnum
import org.eclipse.emf.validation.model.ConstraintSeverity

import static extension org.eclipse.emf.validation.internal.modeled.model.validation.ModeEnum.*
import static extension org.eclipse.emf.validation.model.ConstraintSeverity.*
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd.SdConfig.SdServiceGroup
//import com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdGeneral.SdSecurityEventRefs.SEV_SOME_IP_SD_DUPLICATE_OFFER
//import com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdGeneral.SdSecurityEventRefs

class SdValidation extends ValidationRuleset {

  static extension VariantHandlingExtensions = VariantHandlingExtensions.INSTANCE
  static extension NumberExtensions = NumberExtensions.INSTANCE
  static extension AutosarModelExtensions = AutosarModelExtensions.INSTANCE


    /*
    * Design ID : SD_SDD_0329
    * (ERR171051)Domain for the parameter 'SoAdSocketLocalAddressRef' should be same in all the reference of
    * 'SoAdSocketConnectionGroup'.
    */
    @ValidationRule( code=171051, name="SoAdSocketLocalAddressRef is configured with same domain type in all reference
    of SoAdSocketConnectionGroup.",
   description="Check if SoAdSocketLocalAddressRef is configured with same domain type in all reference of
    SoAdSocketConnectionGroup.",
   message="Domain for the parameter 'SoAdSocketLocalAddressRef' should be same "+
         "in all the reference of 'SoAdSocketConnectionGroup' in instance : {0}.",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] SoAdSocketLocalAddressRef_domain(Sd sd)
  {
     var String str = ''
     var int pbvclistsize = 0
     val soad = sd.AUTOSAR.findFirstElement(SoAd)
     val tcpip = sd.AUTOSAR.findFirstElement(TcpIp)
     var SoAdSocketLocalAddressRef_DomainType = new ArrayList<String>()
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

     if(pbvclistsize > 0)
     {
        var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
      for(itr : pbvclist)
      {
       for(instance : sd?.sdConfig?.sdInstances)
       {
       for(serverservice : instance?.sdServerServices)
       {
          var serverservicetcpref = serverservice?.sdServerServiceTcpRef_PB?.filterVariant(itr).head as 
          SdServerServiceTcpRef
          if(serverservicetcpref !== null)
          {
          var soadAddr = serverservicetcpref?.reference?.soAdSocketLocalAddressRef_PB?.filterVariant(itr).head as 
          SoAdSocketLocalAddressRef
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(serverservicetcpref?.reference?.shortName?.toString))
            {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName.toString) )
                    {
                        var domaintype = tcpiplocaladdr?.tcpIpDomainType_PB?.filterVariant(itr).head
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                    }
                  }
              }
            }
            }



          var serverserviceudpref = serverservice?.sdServerServiceUdpRef_PB?.filterVariant(itr)?.head as 
          SdServerServiceUdpRef
          if(serverserviceudpref !== null)
          {
          var soadAddr = serverserviceudpref?.reference?.soAdSocketLocalAddressRef_PB?.filterVariant(itr)?.head as 
          SoAdSocketLocalAddressRef
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(serverserviceudpref?.reference?.shortName?.toString))
            {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                        var domaintype = tcpiplocaladdr.tcpIpDomainType_PB?.filterVariant(itr).head
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                    }
                  }
              }
            }
            }
       }

      for(clientservice : instance?.sdClientServices)
      {
          var clientservicetcpref = clientservice?.sdClientServiceTcpRef_PB?.filterVariant(itr).head as 
          SdClientServiceTcpRef
          if(clientservicetcpref !== null)
          {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(clientservicetcpref?.reference?.shortName?.toString))
            {
                 var soadAddr = clientservicetcpref.reference?.soAdSocketLocalAddressRef_PB?.filterVariant(itr).head as 
                 SoAdSocketLocalAddressRef
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                        var domaintype = tcpiplocaladdr?.tcpIpDomainType_PB?.filterVariant(itr).head
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                    }
                  }
              }
            }
          }


          var clientserviceudpref = clientservice?.sdClientServiceUdpRef_PB?.filterVariant(itr).head as 
          SdClientServiceUdpRef
          if(clientserviceudpref !== null)
          {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(clientserviceudpref?.reference?.shortName?.toString))
            {
                  var soadAddr = clientserviceudpref.reference?.soAdSocketLocalAddressRef_PB?.filterVariant(itr).head as 
                  SoAdSocketLocalAddressRef
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                        var domaintype = tcpiplocaladdr?.tcpIpDomainType_PB?.filterVariant(itr).head
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                    }
                  }
              }
            }
          }


           for(consumedeventgroup: clientservice?.sdConsumedEventGroups)
           {
             if(consumedeventgroup?.sdConsumedEventGroupMulticastGroupRefs_PB?.filterVariant(itr).size != 0)
             {
              var multicastgroupref = consumedeventgroup?.sdConsumedEventGroupMulticastGroupRefs_PB?.
              filterVariant(itr).head as 
              SdConsumedEventGroupMulticastGroupRef
              for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
              {
             if (socongroup?.shortName?.toString.equals(multicastgroupref?.reference?.shortName?.toString))
             {
                  var soadAddr = multicastgroupref?.reference.soAdSocketLocalAddressRef_PB?.filterVariant(itr).head as 
                  SoAdSocketLocalAddressRef
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                        var domaintype = tcpiplocaladdr?.tcpIpDomainType_PB?.filterVariant(itr).head
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                    }
                  }
               }
             }
            }

           }

       }

       if (SoAdSocketLocalAddressRef_DomainType.contains("TCPIP_AF_INET") &&
                    SoAdSocketLocalAddressRef_DomainType.contains("TCPIP_AF_INET6"))
       {
         str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+instance.shortName.toString+','
         SoAdSocketLocalAddressRef_DomainType = new ArrayList
       }

       SoAdSocketLocalAddressRef_DomainType = new ArrayList
    }
    }
     if(str != '')
     {
      str = str.substring(0,str.length()-1)
      str = str.replace(",",",\n")
      return #[str]
      }
   }

     else
     {
      for(instance : sd?.sdConfig?.sdInstances)
      {
      for(serverservice : instance?.sdServerServices)
      {
        for(serverservicetcpref : serverservice?.sdServerServiceTcpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(serverservicetcpref?.reference?.shortName?.toString))
            {
              for (soadAddr : serverservicetcpref.reference?.soAdSocketLocalAddressRef_PB)
                {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName.toString) )
                    {
                      for (domaintype : tcpiplocaladdr?.tcpIpDomainType_PB)
                      {
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                      }
                    }
                  }
              }
              }
            }
           }


        for(serverserviceudpref : serverservice?.sdServerServiceUdpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(serverserviceudpref?.reference?.shortName?.toString))
            {
              for (soadAddr : serverserviceudpref?.reference?.soAdSocketLocalAddressRef_PB)
                {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                      for (domaintype : tcpiplocaladdr.tcpIpDomainType_PB)
                      {
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                      }
                    }
                  }
              }
              }
            }
           }

       }

      for(clientservice : instance?.sdClientServices)
      {
        for(clientservicetcpref : clientservice?.sdClientServiceTcpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(clientservicetcpref?.reference?.shortName?.toString))
            {
              for (soadAddr : clientservicetcpref.reference?.soAdSocketLocalAddressRef_PB)
                {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                      for (domaintype : tcpiplocaladdr?.tcpIpDomainType_PB)
                      {
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                      }
                    }
                  }
              }
              }
            }
           }


        for(clientserviceudpref : clientservice?.sdClientServiceUdpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if (socongroup?.shortName?.toString.equals(clientserviceudpref?.reference?.shortName?.toString))
            {
              for (soadAddr : clientserviceudpref.reference?.soAdSocketLocalAddressRef_PB)
                {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                      for (domaintype : tcpiplocaladdr?.tcpIpDomainType_PB)
                      {
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                      }
                    }
                  }
              }
              }
            }
           }


           for(consumedeventgroup: clientservice?.sdConsumedEventGroups)
           {
             for(multicastgroupref : consumedeventgroup?.sdConsumedEventGroupMulticastGroupRefs_PB)
             {
              for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
              {
             if (socongroup?.shortName?.toString.equals(multicastgroupref?.reference?.shortName?.toString))
             {
              for (soadAddr : multicastgroupref?.reference.soAdSocketLocalAddressRef_PB)
                {
                  for(tcpiplocaladdr : tcpip?.tcpIpConfig?.tcpIpLocalAddrs)
                  {
                    if (soadAddr?.reference?.shortName?.toString.equals(tcpiplocaladdr?.shortName?.toString))
                    {
                      for (domaintype : tcpiplocaladdr?.tcpIpDomainType_PB)
                      {
                        SoAdSocketLocalAddressRef_DomainType.add(domaintype?.value)
                      }
                    }
                  }
                 }
               }
            }
             }

           }

       }

       if (SoAdSocketLocalAddressRef_DomainType.contains("TCPIP_AF_INET") &&
                    SoAdSocketLocalAddressRef_DomainType.contains("TCPIP_AF_INET6"))
       {
         str = str+instance.shortName.toString+','
       }

       SoAdSocketLocalAddressRef_DomainType = new ArrayList
    }

    if(str != '')
    {
      str = str.substring(0,str.length()-1)
      str = str.replace(",",",\n")
      return #[str]
      }
   }
  }

  /*
   * Design ID : SD_SDD_0330
   * (ERR171052)SoAdSocketTcp or SoAdSocketUdp should be configured in the
   * container 'SoAdSocketConnectionGroup'
   */

  @ValidationRule( code=171052, name="SoAdSocketTcp or SoAdSocketUdp should be configured in the container
    SoAdSocketConnectionGroup referred.",description="
  Either SoAdSocketTcp
  or SoAdSocketUdp
  should configured
  in the container'SoAdSocketConnectionGroup'
  depending upon
  where it
  is referred.",message="{0}",mode=ModeEnum.LIVE,severity=ConstraintSeverity.ERROR)def

  static Object[] SoAdSocketTcpUdp(Sd sd)
  {
    var int pbvclistsize = 0
    val soad = sd.AUTOSAR.findFirstElement(SoAd)
    var ArrayList_tcp = new ArrayList<String>()
    var ArrayList_udp = new ArrayList<String>()
    var err52 = new ArrayList<String>()

     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
     for(itr : pbvclist)
     {
     for(instance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : instance?.sdServerServices)
      {
          var serverservicetcpref = serverservice?.sdServerServiceTcpRef_PB?.filterVariant(itr).head as 
          SdServerServiceTcpRef
          for(socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(serverservicetcpref?.reference?.shortName?.toString))
            {
            if(socongroup?.soAdSocketProtocol?.soAdSocketTcp === null && !ArrayList_tcp.contains(socongroup?.
            	shortName?.toString
            ))
            {
                err52.add("SoAdSocketTcp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                  ArrayList_tcp.add(socongroup?.shortName?.toString)
                err52.add("\n\r")
              }
            }
          }



          var serverserviceudpref = serverservice?.sdServerServiceUdpRef_PB?.filterVariant(itr).head as 
          SdServerServiceUdpRef
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(serverserviceudpref?.reference?.shortName?.toString))
            {
              if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
              	shortName?.toString
              ))
              {
                err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_udp.add(socongroup?.shortName?.toString)
              }
           }
          }

       }

      for(clientservice : instance?.sdClientServices)
      {
        var clientservicetcpref = clientservice?.sdClientServiceTcpRef_PB?.filterVariant(itr).head as 
        SdClientServiceTcpRef
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(clientservicetcpref?.reference?.shortName?.toString))
             {
              if(socongroup?.soAdSocketProtocol?.soAdSocketTcp === null && !ArrayList_tcp.contains(socongroup?.
              	shortName?.toString
              ))
             {
                err52.add("SoAdSocketTcp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_tcp.add(socongroup?.shortName?.toString)
               }
             }
           }


         var clientserviceudpref = clientservice?.sdClientServiceUdpRef_PB?.filterVariant(itr).head as 
         SdClientServiceUdpRef
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(clientserviceudpref?.reference?.shortName?.toString))
             {
             if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
             	shortName?.toString
             ))
             {
                err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_udp.add(socongroup?.shortName?.toString)
               }
             }
           }


           for(consumedeventgroup: clientservice?.sdConsumedEventGroups)
           {
            var multicastgroupref = consumedeventgroup?.sdConsumedEventGroupMulticastGroupRefs_PB?.
            filterVariant(itr).head as SdConsumedEventGroupMulticastGroupRef
               for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
             {
               if(socongroup?.shortName?.toString.equals(multicastgroupref?.reference?.shortName?.toString))
               {
                if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
                	shortName?.toString
                ))
                {
                    err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                      socongroup?.shortName?.toString+";\n")
                    err52.add("\n\r")
                    ArrayList_udp.add(socongroup?.shortName?.toString)
                  }
                }
              }
               }
         }
         }
         }

       if(!(err52.nullOrEmpty))
       {
         return #[err52]
       }
    }
    else
    {

     for(instance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : instance?.sdServerServices)
      {
        for(serverservicetcpref : serverservice?.sdServerServiceTcpRef_PB)
        {
          for(socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(serverservicetcpref?.reference?.shortName?.toString))
            {
            if(socongroup?.soAdSocketProtocol?.soAdSocketTcp === null && !ArrayList_tcp.contains(socongroup?.
            	shortName?.toString
            ))
            {
                err52.add("SoAdSocketTcp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                  ArrayList_tcp.add(socongroup?.shortName?.toString)
                err52.add("\n\r")
              }
            }
          }
        }


        for(serverserviceudpref : serverservice?.sdServerServiceUdpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(serverserviceudpref?.reference?.shortName?.toString))
            {
              if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
              	shortName?.toString
              ))
              {
                err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_udp.add(socongroup?.shortName?.toString)
              }
           }
          }
        }

       }

      for(clientservice : instance?.sdClientServices)
      {
        for(clientservicetcpref : clientservice?.sdClientServiceTcpRef_PB)
        {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(clientservicetcpref?.reference?.shortName?.toString))
             {
             if(socongroup?.soAdSocketProtocol?.soAdSocketTcp === null && !ArrayList_tcp.contains(socongroup?.
             	shortName?.toString
             ))
             {
                err52.add("SoAdSocketTcp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_tcp.add(socongroup?.shortName?.toString)
               }
             }
           }
         }


         for(clientserviceudpref : clientservice?.sdClientServiceUdpRef_PB)
         {
          for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
          {
            if(socongroup?.shortName?.toString.equals(clientserviceudpref?.reference?.shortName?.toString))
             {
             if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
             	shortName?.toString
             ))
             {
                err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                  socongroup?.shortName?.toString+";\n")
                err52.add("\n\r")
                ArrayList_udp.add(socongroup?.shortName?.toString)
               }
             }
           }
          }


           for(consumedeventgroup: clientservice?.sdConsumedEventGroups)
           {
             for(multicastgroupref : consumedeventgroup?.sdConsumedEventGroupMulticastGroupRefs_PB)
             {
               for (socongroup: soad?.soAdConfig?.soAdSocketConnectionGroups)
             {
               if(socongroup?.shortName?.toString.equals(multicastgroupref?.reference?.shortName?.toString))
               {
                if(socongroup?.soAdSocketProtocol?.soAdSocketUdp === null && !ArrayList_udp.contains(socongroup?.
                	shortName?.toString
                ))
                {
                    err52.add("SoAdSocketUdp should be configured in sub container SoAdSocketProtocol of "+
                      socongroup?.shortName?.toString+";\n")
                    err52.add("\n\r")
                    ArrayList_udp.add(socongroup?.shortName?.toString)
                  }
                }
              }
               }

             }
         }
         }

       if(!(err52.nullOrEmpty))
       {
         return #[err52]
       }
    }
  }

  /*
   * Design ID : SD_SDD_0367,SD_SDD_0331
   * (ERR171053)value configured for 'ServerServiceHandleId' parameter in
   * container 'ServerService'
   * should be sequential and Within range from 0 to 65535.
   */
  @ValidationRule(
   code=171053,
   name="server service handleid sequential.",
   description="Check value of ServerServiceHandleId starts from zero , Within range from 0 to 65535 and is sequential",
   message="The value configured for 'ServerServiceHandleId' parameter in 'ServerService' container "+
         "should be sequential,Within range from 0 to 65535 and starting from <0> for each instance of <SdConfig>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
    def static boolean serverservicehandleid_sequential(Sd  _sd)
  {
    var returnval = false
    var server_service_handleid = new ArrayList<Integer>()

    for(_sdInstance : _sd?.sdConfig?.sdInstances)
    {
      for(serverservice : _sdInstance?.sdServerServices)
      {
        server_service_handleid.add(serverservice?.sdServerServiceHandleId.intValue)
      }
    }

      if(server_service_handleid.nullOrEmpty)
      {
        returnval = true
      }

      else if(server_service_handleid.hasSequentialElements && server_service_handleid.contains(0))
      {
           returnval = true
      }
      else if(server_service_handleid.contains(65536))
      {
      	  returnval = false
      }
      else
      {
           returnval = false
      }

      return(returnval)

  }

  /*
   * Design ID : SD_SDD_0367,SD_SDD_0331
   * (ERR171057)value configured for 'ClientServiceHandleId' parameter in
   * container 'ClientService'
   * should be sequential.
   */
  @ValidationRule( code=171057, name="client service handleid sequential.",
   description="Check value of ClientServiceHandleId starts from zero and is sequential and it should be within range 0 to 65535",
   message="The value configured for 'ClientServiceHandleId' parameter in 'ClientService' container "+
         "should be sequential,within range 0 to 65535 and starting from <0> for each instance of <SdConfig>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean clientservicehandleid_sequential(Sd  _sd)
  {
    var returnval = false
    var client_service_handleid = new ArrayList<Integer>()

    for(_sdInstance : _sd?.sdConfig?.sdInstances)
    {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        client_service_handleid.add(clientservice?.sdClientServiceHandleId.intValue)
      }
    }

      if(client_service_handleid.nullOrEmpty)
      {
        returnval = true
      }

      else if((client_service_handleid.hasSequentialElements) && client_service_handleid.contains(0))
      {
           returnval = true
      }
      else if (client_service_handleid.contains(65536))
      	{
      		returnval = false
      	}
      
      else
      {
           returnval = false
      }

      return(returnval)
  }

  /*
   * Design ID : SD_SDD_0348
   * (ERR171059)value configured for 'ConsumedEventGroupHandleId' parameter in
   * container 'ConsumedEventGroup'
   * should be sequential.
   */
  @ValidationRule( code=171059, name="Consumed EventGroup handleid sequential.",
   description="Check value of ConsumedEventGroupHandleId starts from zero and is sequential",
   message="The value configured for 'ConsumedEventGroupHandleId' parameter in 'ConsumedEventGroup' container "+
         "should be sequential and starting from <0> for each instance of <SdConfig>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean ConsumedEventGroupHandleId_sequential(Sd  _sd)
  {
     var returnval = false
    var consumed_eventgroup_handleid = new ArrayList<Integer>()

    for(_sdInstance : _sd?.sdConfig?.sdInstances)
    {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(consumedeventgroup : clientservice?.sdConsumedEventGroups)
        {
        consumed_eventgroup_handleid.add(consumedeventgroup?.sdConsumedEventGroupHandleId.intValue)
        }
      }
    }

      if(consumed_eventgroup_handleid.nullOrEmpty)
      {
        returnval = true
      }

      else if(consumed_eventgroup_handleid.hasSequentialElements && consumed_eventgroup_handleid.contains(0))
      {
        returnval = true
      }

      else
      {
         returnval = false
      }

        return(returnval)
  }

  /*
   * Design ID : SD_SDD_0349
   * (ERR171060)value configured for 'EventHandlerHandleId' parameter in container
   * 'EventHandler'
   * should be sequential.
   */
  @ValidationRule( code=171060, name="EventHandler handleid sequential,should be within range from 0 to 65535.",
   description="Check value of EventHandlerHandleId starts from zero,should be within range from 0 to 65535 and is sequential",
   message="The value configured for 'EventHandlerHandleId' parameter in 'EventHandler' container "+
         "should be sequential, should be within range from 0 to 65535 and starting from <0> for each instance of <SdConfig>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean EventHandlerHandleId_sequential(Sd  _sd)
  {
     var returnval = false
    var eventhandler_handleid = new ArrayList<Integer>()

    for(_sdInstance : _sd?.sdConfig?.sdInstances)
    {
      for(serverservice : _sdInstance?.sdServerServices)
      {
        for(eventhandler : serverservice?.sdEventHandlers)
        {
        eventhandler_handleid.add(eventhandler?.sdEventHandlerHandleId.intValue)
        }
      }

    }

     if(eventhandler_handleid.nullOrEmpty)
     {
       returnval = true
     }

      else if(eventhandler_handleid.hasSequentialElements && eventhandler_handleid.contains(0))
      {
        returnval = true
      }
      else if (eventhandler_handleid.contains(65536))
      {
        returnval = false
      }
      
      else
      {
        returnval = false
      }

        return(returnval)
  }

  /*
   * Design ID : SD_SDD_0367, SD_SDD_0365,SD_SDD_0331
   * (ERR171054)value configured for SdRxPduId parameter in container
   * SdInstanceUnicastRxPdu & SdInstanceMulticastRxPdu
   * should be sequential.
   */
  @ValidationRule(
      code=171054,
      name="SdRxPduId inside SdInstanceUnicastRxPd & SdInstanceMulticastRxPdu is sequential.",
      description="Check value of SdRxPduId in Container SdInstanceUnicastRxPdu & SdInstanceMulticastRxPdu starts from
         zero and is sequential",
      message="{0}",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] UnicastRxPdId_sequential(Sd  sd)
  {
    var int pbvclistsize = 0
    var returnval = false
    var str =''
    var unicast_multicast_rxpdid = new ArrayList<Integer>()

     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
      var str_temp = ''
     for(itr : pbvclist)
     {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
        var unicastrxpdid = _sdInstance?.sdInstanceUnicastRxPdu.sdRxPduId_PB.filterVariant(itr).head
        var multicastrxpdid = _sdInstance?.sdInstanceMulticastRxPdu.sdRxPduId_PB.filterVariant(itr).head

        unicast_multicast_rxpdid.add(unicastrxpdid?.integerValue)
        unicast_multicast_rxpdid.add(multicastrxpdid?.integerValue)
     }

      if(unicast_multicast_rxpdid.nullOrEmpty)
      {
        returnval = true
      }

      else if(unicast_multicast_rxpdid.hasSequentialElements && unicast_multicast_rxpdid.contains(0))
      {
         returnval = true
      }

      else
      {
        returnval = false
        str_temp = str_temp+itr?.matchingCriterion.shortName+','
      }

         unicast_multicast_rxpdid = new ArrayList
    }
      if(str_temp != '')
      {
        str = 'The value configured for SdRxPduId parameter in container SdInstanceUnicastRxPd & SdInstanceMulticastRxPdu should be sequential and start from <0> for each instance of Variant: '+str_temp
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }

    else
    {
    for(_sdInstance : sd?.sdConfig?.sdInstances)
    {
      for(unicastrxpdid : _sdInstance?.sdInstanceUnicastRxPdu.sdRxPduId_PB)
      {
        unicast_multicast_rxpdid.add(unicastrxpdid?.integerValue)
      }

      for(multicastrxpdid : _sdInstance?.sdInstanceMulticastRxPdu.sdRxPduId_PB)
      {
        unicast_multicast_rxpdid.add(multicastrxpdid?.integerValue)
      }

    }

      if(unicast_multicast_rxpdid.nullOrEmpty)
      {
        returnval = true
      }

      else if(unicast_multicast_rxpdid.hasSequentialElements && unicast_multicast_rxpdid.contains(0))
      {
         returnval = true
      }

      else
      {
        returnval = false
      }

      if(returnval == false)
      {
        str = 'The value configured for SdRxPduId parameter in container SdInstanceUnicastRxPd & SdInstanceMulticastRxPdu should be sequential and start from <0> for each instance of <SdConfig>'
        return #[str]
      }
 }
 }

  /*
   * Design ID : SD_SDD_0352
   * (ERR171055) Value of ServerTimerTTL referred in Server Service should be non
   * zero.
   */
  @ValidationRule( code=171055, name="Non Zero Server Timer",
   description="Check Server Timer is non zero",
   message="The value configured for 'ServerTimerTTL' parameter in {0} "+
    "should not be 0",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] server_ttl_nonzero(Sd sd)
  {
    var int pbvclistsize = 0
    var flag = 0
    var str =''
    var instance_serverttl_path = new ArrayList<String>()

     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
     for(itr : pbvclist)
     {
      for(instance : sd?.sdConfig?.sdInstances)
      {
        for(server : instance?.sdServerServices)
       {
        var servertimer = server?.sdServerServiceTimerRef_PB?.filterVariant(itr)?.head as SdServerServiceTimerRef
        var serverttl = servertimer?.reference.sdServerTimerTTL_PB?.filterVariant(itr)?.head

        if(serverttl?.integerValue == 0 && !instance_serverttl_path.contains(servertimer.reference.shortName))
        {
           flag = 1
           instance_serverttl_path.add(servertimer.reference.shortName)
        }

     for(eventhandler : server?.sdEventHandlers)
     {
        var eventhandlertimer = eventhandler?.sdEventHandlerTimerRef_PB?.filterVariant(itr)?.head as SdEventHandlerTimerRef
        var eventhandlerttl = eventhandlertimer?.reference?.sdServerTimerTTL_PB?.filterVariant(itr).head

           if(eventhandlerttl?.integerValue == 0 && !instance_serverttl_path.contains(eventhandlertimer.reference.shortName))
           {
             flag = 1
             instance_serverttl_path.add(eventhandlertimer.reference.shortName)
           }

     }
    }
      if(!instance_serverttl_path.nullOrEmpty)
     {
       str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+instance.shortName+', Timer: '+instance_serverttl_path.join(',')+'; '
       instance_serverttl_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]

      }
      }
    else
    {
    for(instance : sd?.sdConfig?.sdInstances)
    {
    for(server : instance?.sdServerServices)
    {
     for(servertimer : server?.sdServerServiceTimerRef_PB)
     {
      for(serverttl : servertimer?.reference.sdServerTimerTTL_PB)
      {
        if(serverttl?.integerValue == 0 && !instance_serverttl_path.contains(servertimer.reference.shortName))
        {
           flag = 1
           instance_serverttl_path.add(servertimer.reference.shortName)
        }
      }
     }

     for(eventhandler : server?.sdEventHandlers)
     {
       for(eventhandlertimer : eventhandler?.sdEventHandlerTimerRef_PB)
       {
         for(eventhandlerttl : eventhandlertimer?.reference?.sdServerTimerTTL_PB)
         {
           if(eventhandlerttl?.integerValue == 0 && !instance_serverttl_path.contains(
           	eventhandlertimer.reference.shortName
           ))
           {
             flag = 1
             instance_serverttl_path.add(eventhandlertimer.reference.shortName)
           }
         }
       }

     }
    }
    if(!instance_serverttl_path.nullOrEmpty)
    {
      str = str+'Instance: '+instance.shortName+', Timer: '+instance_serverttl_path.join(',')+'; '
      instance_serverttl_path = new ArrayList
      }
    }

      if(flag != 0)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]

      }
    }

  }

  /*
   * Design ID : SD_SDD_0332
   * (ERR171067) Value of ClientTimerTTL referred in Client Service should be non
   * zero.
   */
  @ValidationRule( code=171067, name="Non Zero CLient Timer",
   description="Check Client Timer is non zero",
   message="The value configured for 'ClientTimerTTL' parameter in {0}"+
    "should not be 0",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] client_ttl_nonzero(Sd  sd)
  {
    var int pbvclistsize = 0
    var flag = 0
    var str = ''
    var instance_clientttl_path = new ArrayList<String>()
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
    var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
    for ( itr : pbvclist)
    {
    for(_sdInstance : sd?.sdConfig?.sdInstances)
   {
    for(client : _sdInstance?.sdClientServices)
    {
        var clienttimer = client?.sdClientServiceTimerRef_PB?.filterVariant(itr).head  as SdClientServiceTimerRef
        var clientttl = clienttimer.reference?.sdClientTimerTTL_PB?.filterVariant(itr).head

        if(clientttl?.integerValue == 0 && !instance_clientttl_path.contains(clienttimer.reference.shortName))
        {
           flag = 1
           instance_clientttl_path.add(clienttimer.reference.shortName)
        }

     for (consumedev : client?.sdConsumedEventGroups)
     {
        var consumedevtimer = consumedev?.sdConsumedEventGroupTimerRef_PB?.filterVariant(itr).head as 
        SdConsumedEventGroupTimerRef
        var consumedevttl = consumedevtimer.reference?.sdClientTimerTTL_PB?.filterVariant(itr).head

        if(consumedevttl?.integerValue == 0 && !instance_clientttl_path.contains(consumedevtimer.reference.shortName))
        {
           flag = 1
           instance_clientttl_path.add(consumedevtimer.reference.shortName)
        }
     }
   }
      if(!instance_clientttl_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', Timer: '+instance_clientttl_path.join(',')+'; '
      instance_clientttl_path = new ArrayList
      }
   }
    }
       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {

   for(_sdInstance : sd?.sdConfig?.sdInstances)
   {
    for(client : _sdInstance?.sdClientServices)
    {
     for(clienttimer : client?.sdClientServiceTimerRef_PB)
     {
      for(clientttl : clienttimer.reference?.sdClientTimerTTL_PB)
      {
        if(clientttl?.integerValue == 0 && !instance_clientttl_path.contains(clienttimer.reference.shortName))
        {
           flag = 1
           instance_clientttl_path.add(clienttimer.reference.shortName)
        }
       }
      }

     for (consumedev : client?.sdConsumedEventGroups)
     {
      for(consumedevtimer : consumedev?.sdConsumedEventGroupTimerRef_PB)
      {
       for(consumedevttl : consumedevtimer.reference?.sdClientTimerTTL_PB)
       {
        if(consumedevttl?.integerValue == 0 && !instance_clientttl_path.contains(consumedevtimer.reference.shortName))
        {
           flag = 1
           instance_clientttl_path.add(consumedevtimer.reference.shortName)
        }
       }
      }
     }
   }
      if(!instance_clientttl_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', Timer: '+instance_clientttl_path.join(',')+'; '
      instance_clientttl_path = new ArrayList
      }

   }

      if(flag != 0)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0349
   * (ERR171056) Value of ClientTimerRequestResponseMinDelay should be configured
   * in ClientTimer.
   */

  @ValidationRule( code=171056, name="ClientTimerRequestResponseMinDelay is configured in ClientTimer.",
   description="Check if ClientTimerRequestResponseMinDelay is configured in Container ClientTimer",
   message="The parameter 'ClientTimerRequestResponseMinDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerRequestResponseMinDelay_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
        for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
          SdClientServiceTimerRef
          if(clienttimerref?.reference?.sdClientTimerRequestResponseMinDelay_PB?.filterVariant(itr).size == 0 &&
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
            clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerreqresmindelay = clienttimerref.reference.sdClientTimerRequestResponseMinDelay_PB?.
            filterVariant(itr).head
            if(clienttimerreqresmindelay?.floatValue === null && !clienttimer_path.contains(clienttimerref.
            	reference.shortName
            ))
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
          if(clienttimerref.reference.sdClientTimerRequestResponseMinDelay_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
            clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerreqresmindelay : clienttimerref.reference.sdClientTimerRequestResponseMinDelay_PB)
            {
            if(clienttimerreqresmindelay?.floatValue === null && !clienttimer_path.contains(clienttimerref.
            	reference.shortName
            ))
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0342
   * (ERR171068) Value of ClientTimerInitialFindDelayMax should be configured in
   * ClientTimer.
   */
  @ValidationRule( code=171068, name="ClientTimerInitialFindDelayMax is configured in ClientTimer.",
   description="Check if ClientTimerInitialFindDelayMax is configured in Container ClientTimer",
   message="The parameter 'ClientTimerInitialFindDelayMax' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerInitialFindDelayMax_configured(Sd sd)
  {
      var int pbvclistsize = 0
      var clienttimer_path = new ArrayList<String>()
      var flag = 0
      var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
       for(_sdInstance : sd?.sdConfig?.sdInstances)
      {
      for(clientservice : _sdInstance?.sdClientServices)
      {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
          SdClientServiceTimerRef
          if(clienttimerref.reference.sdClientTimerInitialFindDelayMax_PB.filterVariant(itr).size == 0 &&
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
            clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerinitfinddelaymax = clienttimerref.reference.sdClientTimerInitialFindDelayMax_PB?.
            filterVariant(itr).head
            if(clienttimerinitfinddelaymax?.floatValue === null && !clienttimer_path.contains(
            	clienttimerref.reference.shortName
            ))
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
        str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
        clienttimer_path = new ArrayList
      }
      }
      }
       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
        }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
          if(clienttimerref.reference.sdClientTimerInitialFindDelayMax_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
            clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerinitfinddelaymax : clienttimerref.reference.sdClientTimerInitialFindDelayMax_PB)
            {
            if(clienttimerinitfinddelaymax?.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
        str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
        clienttimer_path = new ArrayList
      }
      }

      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0343
   * (ERR171069) Value of ClientTimerInitialFindDelayMin should be configured in
   * ClientTimer.
   */
  @ValidationRule( code=171069, name="ClientTimerInitialFindDelayMin is configured in ClientTimer.",
   description="Check if ClientTimerInitialFindDelayMin is configured in Container ClientTimer",
   message="The parameter 'ClientTimerInitialFindDelayMin' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerInitialFindDelayMin_configured(Sd  sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var str =''
    var flag = 0
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
      for(itr : pbvclist)
      {
       for(_sdInstance : sd?.sdConfig?.sdInstances)
       {
       for(clientservice : _sdInstance?.sdClientServices)
       {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
          SdClientServiceTimerRef
          if(clienttimerref.reference.sdClientTimerInitialFindDelayMin_PB.filterVariant(itr).size == 0 &&
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
            clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerinitfinddelaymin = clienttimerref?.reference?.sdClientTimerInitialFindDelayMin_PB?.
            filterVariant(itr).head
            if(clienttimerinitfinddelaymin?.floatValue === null && !clienttimer_path.contains(clienttimerref.
            	reference.shortName
            ))
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
       if(!clienttimer_path.nullOrEmpty)
       {
        str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
        clienttimer_path = new ArrayList
       }
       }
       }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
          if(clienttimerref.reference.sdClientTimerInitialFindDelayMin_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerinitfinddelaymin : clienttimerref.reference.sdClientTimerInitialFindDelayMin_PB)
            {
            if(clienttimerinitfinddelaymin.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
       if(!clienttimer_path.nullOrEmpty)
       {
        str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
        clienttimer_path = new ArrayList
       }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0333
   * (ERR171070) Value of ServerTimerInitialOfferDelayMax should be configured in
   * ServerTimer.
   */
  @ValidationRule( code=171070, name="ServerTimerInitialOfferDelayMax is configured in ServerTimer.",
   description="Check if ServerTimerInitialOfferDelayMax is configured in Container ServerTimer",
   message="The parameter 'ServerTimerInitialOfferDelayMax' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ServerTimerInitialOfferDelayMax_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var servertimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
        for(_sdInstance : sd?.sdConfig?.sdInstances)
      {
      for(Serverservice : _sdInstance?.sdServerServices)
      {
          var servertimerref = Serverservice?.sdServerServiceTimerRef_PB?.filterVariant(itr).head
          if(servertimerref.reference.sdServerTimerInitialOfferDelayMax_PB.filterVariant(itr).size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
            servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
               var servertimerinitofferdelaymax = servertimerref.reference.sdServerTimerInitialOfferDelayMax_PB?.
               filterVariant(itr).head
               if(servertimerinitofferdelaymax?.floatValue === null && !servertimer_path.contains(servertimerref.
               	reference.shortName
               ))
               {
                 flag = 1
                 servertimer_path.add(servertimerref.reference.shortName)
               }
          }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(Serverservice : _sdInstance?.sdServerServices)
      {
        for(servertimerref : Serverservice?.sdServerServiceTimerRef_PB)
        {
          if(servertimerref.reference.sdServerTimerInitialOfferDelayMax_PB.size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
            servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
              for(servertimerinitofferdelaymax : servertimerref.reference.sdServerTimerInitialOfferDelayMax_PB)
              {

               if(servertimerinitofferdelaymax?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
                 flag = 1
                 servertimer_path.add(servertimerref.reference.shortName)
               }
              }
          }
        }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }

      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0333
   * (ERR171071) Value of ServerTimerInitialOfferDelayMin should be configured in
   * ServerTimer.
   */
  @ValidationRule( code=171071, name="ServerTimerInitialOfferDelayMin is configured in ServerTimer.",
   description="Check if ServerTimerInitialOfferDelayMin is configured in Container ServerTimer",
   message="The parameter 'ServerTimerInitialOfferDelayMin' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ServerTimerInitialOfferDelayMin_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var servertimer_path = new ArrayList<String>()
    var flag = 0
     var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
       for(_sdInstance : sd?.sdConfig?.sdInstances)
      {
      for(serverservice : _sdInstance?.sdServerServices)
      {
          var servertimerref = serverservice?.sdServerServiceTimerRef_PB?.filterVariant(itr).head as 
          SdServerServiceTimerRef
          if(servertimerref.reference.sdServerTimerInitialOfferDelayMin_PB.filterVariant(itr).size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
            servertimer_path.add(servertimerref.reference.shortName)
          }
          else
          {
               var servertimerinitofferdelaymin = servertimerref.reference.sdServerTimerInitialOfferDelayMin_PB?.
               filterVariant(itr).head
               if(servertimerinitofferdelaymin?.floatValue === null && !servertimer_path.contains(servertimerref.
               	reference.shortName
               ))
               {
                 flag = 1
                 servertimer_path.add(servertimerref.reference.shortName)
               }
          }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }

    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : _sdInstance?.sdServerServices)
      {
        for(servertimerref : serverservice?.sdServerServiceTimerRef_PB)
        {
          if(servertimerref.reference.sdServerTimerInitialOfferDelayMin_PB.size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
            servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
              for(servertimerinitofferdelaymin : servertimerref.reference.sdServerTimerInitialOfferDelayMin_PB)
              {

               if(servertimerinitofferdelaymin?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
                 flag = 1
                 servertimer_path.add(servertimerref.reference.shortName)
               }
              }
          }
        }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }

      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0353
   * (ERR171072) Value of ServerTimerOfferCyclicDelay should be configured in
   * ServerTimer.
   */
  @ValidationRule( code=171072, name="ServerTimerOfferCyclicDelay is configured in ServerTimer.",
   description="Check if ServerTimerOfferCyclicDelay is configured in Container ServerTimer",
   message="The parameter 'ServerTimerOfferCyclicDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ServerTimerOfferCyclicDelay_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var servertimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
         for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : _sdInstance?.sdServerServices)
      {
          var servertimerref = serverservice?.sdServerServiceTimerRef_PB?.filterVariant(itr).head as 
          SdServerServiceTimerRef
          if(servertimerref.reference.sdServerTimerOfferCyclicDelay_PB.filterVariant(itr).size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
              servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
               var servertimeroffercyclicdelay = servertimerref.reference.sdServerTimerOfferCyclicDelay_PB.
               filterVariant(itr).head
               if(servertimeroffercyclicdelay?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
               flag = 1
               servertimer_path.add(servertimerref.reference.shortName)
               }
          }
      }
       if(!servertimer_path.nullOrEmpty)
       {
       str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }
       }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : _sdInstance?.sdServerServices)
      {
        for(servertimerref : serverservice?.sdServerServiceTimerRef_PB)
        {
            if(servertimerref.reference.sdServerTimerOfferCyclicDelay_PB.size == 0 && 
            	!servertimer_path.contains(servertimerref.reference.shortName)
            )
          {
            flag = 1
              servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
              for(servertimeroffercyclicdelay : servertimerref.reference.sdServerTimerOfferCyclicDelay_PB)
              {

               if(servertimeroffercyclicdelay?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
               flag = 1
               servertimer_path.add(servertimerref.reference.shortName)
               }
              }
          }
        }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }


  /*
   * Design ID : SD_SDD_0351
   * (ERR171073) Value of ServerTimerInitialOfferRepetitionBaseDelay should be
   * configured in ServerTimer.
   */
  @ValidationRule( code=171073, name="ServerTimerInitialOfferRepetitionBaseDelay is configured in ServerTimer.",
   description="Check if ServerTimerInitialOfferRepetitionBaseDelay is configured in Container ServerTimer",
   message="The parameter 'ServerTimerInitialOfferRepetitionBaseDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ServerTimerInitialOfferRepetitionBaseDelay_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var servertimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
         for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : _sdInstance?.sdServerServices)
      {
          var servertimerref = serverservice?.sdServerServiceTimerRef_PB?.filterVariant(itr).head as 
          SdServerServiceTimerRef
          if(servertimerref.reference.sdServerTimerInitialOfferRepetitionBaseDelay_PB.filterVariant(itr).size == 0 &&
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
              servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
               var servertimerofferrepetbasedelay = servertimerref.reference.
               sdServerTimerInitialOfferRepetitionBaseDelay_PB?.filterVariant(itr).head
               if(servertimerofferrepetbasedelay?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
               flag = 1
               servertimer_path.add(servertimerref.reference.shortName)
               }
          }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }
       }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(serverservice : _sdInstance?.sdServerServices)
      {
        for(servertimerref : serverservice?.sdServerServiceTimerRef_PB)
        {
          if(servertimerref.reference.sdServerTimerInitialOfferRepetitionBaseDelay_PB.size == 0 && 
          	!servertimer_path.contains(servertimerref.reference.shortName)
          )
          {
            flag = 1
              servertimer_path.add(servertimerref.reference.shortName)
          }

          else
          {
              for(servertimerofferrepetbasedelay :
                servertimerref.reference.sdServerTimerInitialOfferRepetitionBaseDelay_PB)
              {

               if(servertimerofferrepetbasedelay?.floatValue === null && 
               	!servertimer_path.contains(servertimerref.reference.shortName)
               )
               {
               flag = 1
               servertimer_path.add(servertimerref.reference.shortName)
               }
              }
          }
        }
      }
       if(!servertimer_path.nullOrEmpty)
       {
        str = str+'Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
        servertimer_path = new ArrayList
       }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0344
   * (ERR171074) Value of ClientTimerInitialFindRepetitionsBaseDelay should be
   * configured in ClientTimer.
   */
  @ValidationRule( code=171074, name="ClientTimerInitialFindRepetitionsBaseDelay is configured in ClientTimer.",
   description="Check if ClientTimerInitialFindRepetitionsBaseDelay is configured in Container ClientTimer",
   message="The parameter 'ClientTimerInitialFindRepetitionsBaseDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerInitialFindRepetitionsBaseDelay_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
        for(_sdInstance : sd?.sdConfig?.sdInstances)
        {
        for(clientservice : _sdInstance?.sdClientServices)
         {
            var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
            SdClientServiceTimerRef
            if(clienttimerref.reference.sdClientTimerInitialFindRepetitionsBaseDelay_PB.filterVariant(itr).size == 0 &&
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerinitfindreptbasedelay = clienttimerref.reference.
            sdClientTimerInitialFindRepetitionsBaseDelay_PB.filterVariant(itr).head
            if(clienttimerinitfindreptbasedelay?.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
       if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
      }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
            if(clienttimerref.reference.sdClientTimerInitialFindRepetitionsBaseDelay_PB.size == 0 && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerinitfindreptbasedelay :
              clienttimerref.reference.sdClientTimerInitialFindRepetitionsBaseDelay_PB)
            {
            if(clienttimerinitfindreptbasedelay?.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
       if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0345
   * (ERR171075) Value of ClientTimerInitialFindRepetitionsMax should be
   * configured in ClientTimer.
   */
  @ValidationRule( code=171075, name="ClientTimerInitialFindRepetitionsMax is configured in ClientTimer.",
   description="Check if ClientTimerInitialFindRepetitionsMax is configured in Container ClientTimer",
   message="The parameter 'ClientTimerInitialFindRepetitionsMax' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerInitialFindRepetitionsMax_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
         for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
          SdClientServiceTimerRef
          if(clienttimerref.reference.sdClientTimerInitialFindRepetitionsMax_PB.filterVariant(itr).size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerinitfindreptmax = clienttimerref.reference.sdClientTimerInitialFindRepetitionsMax_PB?.
            filterVariant(itr).head
            if(clienttimerinitfindreptmax?.integerValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
          if(clienttimerref.reference.sdClientTimerInitialFindRepetitionsMax_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerinitfindreptmax : clienttimerref.reference.sdClientTimerInitialFindRepetitionsMax_PB)
            {
            if(clienttimerinitfindreptmax?.integerValue === null && 
            	!clienttimer_path.add(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0346
   * (ERR171076) Value of ClientTimerRequestResponseMaxDelay should be configured
   * in ClientTimer.
   */
  @ValidationRule( code=171076, name="ClientTimerRequestResponseMaxDelay is configured in ClientTimer.",
   description="Check if ClientTimerRequestResponseMaxDelay is configured in Container ClientTimer",
   message="The parameter 'ClientTimerRequestResponseMaxDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] ClientTimerRequestResponseMaxDelay_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
      for(itr : pbvclist)
      {
      for(_sdInstance : sd?.sdConfig?.sdInstances)
      {
      for(clientservice : _sdInstance?.sdClientServices)
      {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr)?.head as 
          SdClientServiceTimerRef
          if(clienttimerref.reference.sdClientTimerRequestResponseMaxDelay_PB.filterVariant(itr).size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerreqresmaxdelay = clienttimerref.reference.sdClientTimerRequestResponseMaxDelay_PB?.
            filterVariant(itr).head
            if(clienttimerreqresmaxdelay?.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
          if(clienttimerref.reference.sdClientTimerRequestResponseMaxDelay_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerreqresmaxdelay : clienttimerref.reference.sdClientTimerRequestResponseMaxDelay_PB)
            {
            if(clienttimerreqresmaxdelay?.floatValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0352
   * (ERR171077) Value of ServerTimerInitialOfferRepetitionsMax should be
   * configured in ServerTimer.
   */
  @ValidationRule( code=171077, name="ServerTimerInitialOfferRepetitionsMax is configured in ServerTimer.",
    description="Check if ServerTimerInitialOfferRepetitionsMax is configured in Container ServerTimer",
    message="The parameter 'ServerTimerInitialOfferRepetitionsMax' and it's value in {0} "+
          "should be configured",
    mode=ModeEnum.LIVE,
    severity=ConstraintSeverity.ERROR
   )
   def static Object[] ServerTimerInitialOfferRepetitionsMax_configured(Sd sd)
   {
     var int pbvclistsize = 0
     var servertimer_path = new ArrayList<String>()
     var flag = 0
     var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
       pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
       for(_sdInstance : sd?.sdConfig?.sdInstances)
       {
        for(serverservice : _sdInstance?.sdServerServices)
       {
           var servertimerref = (serverservice?.sdServerServiceTimerRef_PB?.filterVariant(itr).head as 
           	SdServerServiceTimerRef
           )
           if((servertimerref.reference.sdServerTimerInitialOfferRepetitionsMax_PB.filterVariant(itr).size == 0) && 
           	!(servertimer_path.contains(servertimerref.reference.shortName))
           )
           {
             flag = 1
             servertimer_path.add(servertimerref.reference.shortName)
           }

           else
           {
                var servertimerofferrepetmax = servertimerref.reference.sdServerTimerInitialOfferRepetitionsMax_PB?.
                filterVariant(itr).head
                if(servertimerofferrepetmax?.integerValue === null && !servertimer_path.
                	contains(servertimerref?.reference.shortName)
                )
                {
                flag = 1
                servertimer_path.add(servertimerref.reference.shortName)
                }
           }
         }

        if(!servertimer_path.nullOrEmpty)
        {
         str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
         servertimer_path = new ArrayList
        }
       }
       }

       if(str != '')
       {
         str = str.substring(0,str.length()-1)
         str = str.replace(";","\n")
         return #[str]
       }
    }

    else
    {
       for(_sdInstance : sd?.sdConfig?.sdInstances)
       {
       for(serverservice : _sdInstance?.sdServerServices)
       {
         for(servertimerref : serverservice?.sdServerServiceTimerRef_PB)
         {
           if(servertimerref.reference.sdServerTimerInitialOfferRepetitionsMax_PB.size == 0 && 
           	!servertimer_path.contains(servertimerref.reference.shortName)
           )
           {
             flag = 1
             servertimer_path.add(servertimerref.reference.shortName)
           }

           else
           {
               for(servertimerofferrepetmax : servertimerref.reference.sdServerTimerInitialOfferRepetitionsMax_PB)
               {
                if(servertimerofferrepetmax?.integerValue === null && !servertimer_path.contains(servertimerref.
                	reference.shortName
                ))
                {
                  flag = 1
                  servertimer_path.add(servertimerref.reference.shortName)
                }
               }
           }
         }
       }
        if(!servertimer_path.nullOrEmpty)
        {
         str = str+'Instance: '+_sdInstance.shortName+', ServerTimer: '+servertimer_path.join(',')+'; '
         servertimer_path = new ArrayList
        }
       }


       if(flag == 1)
       {
         str = str.substring(0,str.length()-1)
         str = str.replace(";","\n")
         return #[str]
       }

    }
   }


  /*
   * Design ID : SD_SDD_0460
   * (ERR171077) Value of SubscribeEventgroupRetryDelay should be configured in
   * ClientTimer.
   */
  @ValidationRule( code=171077, name="SubscribeEventgroupRetryDelay is configured in ClientTimer.",
   description="Check if SubscribeEventgroupRetryDelay is configured in Container ClientTimer",
   message="The parameter 'SubscribeEventgroupRetryDelay' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] SubscribeEventgroupRetryDelay_configured(Sd sd)
  {
  
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
     	
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
    	
      var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
      for(itr : pbvclist)
      {
      for(_sdInstance : sd?.sdConfig?.sdInstances)
      {
      	
      for(clientservice : _sdInstance?.sdClientServices)
      {
      	
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr)?.head as 
          SdClientServiceTimerRef
          
          if(clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB?.head?.floatValue < 0.001 )
          {
          	flag = 0
              clienttimer_path.add(clienttimerref.reference.shortName)
          }
          if(clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB.filterVariant(itr).size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerreqresmaxdelay = clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB?.
            filterVariant(itr).head
            if((clienttimerreqresmaxdelay?.floatValue  < 0.001) && (clienttimerreqresmaxdelay?.floatValue > 50) && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
        	if((clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB.head?.floatValue < 0.001))
        	{
        		flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
        	}
        	
        	if((clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB.head?.floatValue > 50))
        	{
        		flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
        	}
          if(clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerreqresmaxdelay : clienttimerref.reference.sdSubscribeEventgroupRetryDelay_PB)
            {
            if((clienttimerreqresmaxdelay?.floatValue < 0.001)&&(clienttimerreqresmaxdelay?.floatValue > 50) && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
  }

  /*
   * Design ID : SD_SDD_0461
   * (ERR171075) Value of SdSubscribeEventgroupRetryMax should be configured in
   * ClientTimer.
   */
  @ValidationRule( code=171075, name="SdSubscribeEventgroupRetryMax is configured in ClientTimer.",
   description="Check if SubscribeEventgroupRetryMax is configured in Container ClientTimer",
   message="The parameter 'SubscribeEventgroupRetryMax' and it's value in {0} "+
         "should be configured",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] SubscribeEventgroupRetryMax_configured(Sd sd)
  {
    var int pbvclistsize = 0
    var clienttimer_path = new ArrayList<String>()
    var flag = 0
    var str =''
    if (sd.sdGeneral.sdSubscribeEventgroupRetryEnable === true){
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
         for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
          var clienttimerref = clientservice?.sdClientServiceTimerRef_PB?.filterVariant(itr).head as 
          SdClientServiceTimerRef
          if(clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB?.filterVariant(itr).size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            var clienttimerinitfindreptmax = clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB?.
            filterVariant(itr).head
            if(clienttimerinitfindreptmax?.integerValue === null && 
            	!clienttimer_path.contains(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
          }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Variant: '+itr.matchingCriterion.shortName+', Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }
      }

       if(str != '')
       {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    else
    {
     for(_sdInstance : sd?.sdConfig?.sdInstances)
     {
      for(clientservice : _sdInstance?.sdClientServices)
      {
        for(clienttimerref : clientservice?.sdClientServiceTimerRef_PB)
        {
        	if(clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB?.head?.integerValue < 0)
        	{
        		
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          
        		
        	}
        	if(clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB?.head?.integerValue > 255)
        	{
        		
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          
        		
        	}
          if(clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB.size == 0 && 
          	!clienttimer_path.contains(clienttimerref.reference.shortName)
          )
          {
            flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
          }

          else
          {
            for(clienttimerinitfindreptmax : clienttimerref.reference.sdSubscribeEventgroupRetryMax_PB)
            {
            if(clienttimerinitfindreptmax?.integerValue === null && 
            	!clienttimer_path.add(clienttimerref.reference.shortName)
            )
            {
              flag = 1
              clienttimer_path.add(clienttimerref.reference.shortName)
            }
            }
          }
        }
      }
      if(!clienttimer_path.nullOrEmpty)
      {
      str = str+'Instance: '+_sdInstance.shortName+', ClientTimer: '+clienttimer_path.join(',')+'; '
      clienttimer_path = new ArrayList
      }
      }


      if(flag == 1)
      {
        str = str.substring(0,str.length()-1)
        str = str.replace(";","\n")
        return #[str]
      }
    }
    
    }
  }
  
  
  
  /*
   * Design ID : SD_SDD_0334
   * (ERR171058) Reference of parameter SdRxPduRef should match with the parameter
   * SoAdRxPduRef/InstanceTxPdu in SoAd.
   */
  @ValidationRule( code=171058, name="Reference of SoAdRxPduRef is configured in SoAd.",
   description="Check if the reference of parameter SoAdRxPduRef in container SdInstanceMulticastRxPdu, "+
          "SdInstanceUnicastRxPdu & SdInstanceTxPdu is configured in SoAd",
   message="{0}",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] SoAdRxPduRef_SoAdSocketRouteDest(Sd sd)
  {
    var int pbvclistsize = 0
    var SocketRouteDest_PduRef = new ArrayList<String>()
    var SocketPduRoute_TxPduRef = new ArrayList<String>()
    var err58 = new ArrayList<String>()
    val soad = sd.AUTOSAR.findFirstElement(SoAd)
     if(sd.implementationConfigVariant.toString == "VARIANT-POST-BUILD")
     {
      pbvclistsize = (sd?.postBuildVariantConditions.filterNull.size)
     }

    if(pbvclistsize > 0)
    {
       var pbvclist = sd?.postBuildVariantConditions?.sortBy[value.mixedText]
       for(itr : pbvclist)
       {
         for(socketroute : soad?.soAdConfig?.soAdSocketRoutes)
        {
        	 for(ref:socketroute?.soAdSocketRouteDests){
        	 	
        	 	var pduref = ref?.soAdRxPduRef_PB?.filterVariant(itr).head as SoAdRxPduRef
        	 	SocketRouteDest_PduRef.add(pduref?.reference?.shortName.toString)
        	 
        	 }
            
           
            
        }


        for(socketpduroute : soad?.soAdConfig?.soAdPduRoutes)
        {
           var txpduref = socketpduroute?.soAdTxPduRef_PB?.filterVariant(itr).head as SoAdTxPduRef
           SocketPduRoute_TxPduRef.add(txpduref?.reference?.shortName.toString)
        }

        for(sdinstance : sd?.sdConfig?.sdInstances)
        {
        var multicastrxpdu_rxpduref = sdinstance?.sdInstanceMulticastRxPdu?.sdRxPduRef_PB?.filterVariant(itr)?.
        head as SdRxPduRef
       if(!SocketRouteDest_PduRef.contains(multicastrxpdu_rxpduref?.reference?.shortName.toString))
       {
        err58.add("Reference of parameter SdRxPduRef in container InstanceMulticastRxPdu of instance : "+
          sdinstance.shortName+" in variant : "+itr.matchingCriterion.shortName+" should match with the parameter SoAdRxPduRef in SoAdSocketRouteDest of SoAd\n")
       }

       var unicastrxpdu_rxpduref = sdinstance?.sdInstanceUnicastRxPdu?.sdRxPduRef_PB?.filterVariant(itr).head as 
       Sd.SdConfig.SdInstance.SdInstanceUnicastRxPdu.SdRxPduRef
       if(!SocketRouteDest_PduRef.contains(unicastrxpdu_rxpduref?.reference?.shortName.toString))
       {
          err58.add("Reference of parameter SdRxPduRef in container InstanceUnicastRxPdu of instance : "+
            sdinstance.shortName+" in variant : "+itr.matchingCriterion.shortName+" should match with the parameter SoAdRxPduRef in SoAdSocketRouteDest of SoAd\n")
        }

       var txpdu_rxpduref = sdinstance?.sdInstanceTxPdu?.sdTxPduRef_PB?.filterVariant(itr).head as SdTxPduRef
       if(!SocketPduRoute_TxPduRef.contains(txpdu_rxpduref?.reference?.shortName.toString))
       {
          err58.add("Reference of parameter SdTxPduRef in container InstanceTxPdu of instance : "+
            sdinstance.shortName+" in variant : "+itr.matchingCriterion.shortName+" should match with the parameter SoAdTxPduRef in SoAdPduRoute of SoAd\n")
        }
       }
            SocketRouteDest_PduRef = new ArrayList
            SocketPduRoute_TxPduRef = new ArrayList
       }

       if(!(err58.nullOrEmpty))
       {
         return #[err58.join('\n\n')]
       }
    }
    else
    {
    for(socketroute : soad?.soAdConfig?.soAdSocketRoutes)
    {
      for(pduref : socketroute?.soAdSocketRouteDests)
      {
      	for(ref:pduref?.soAdRxPduRef_PB){SocketRouteDest_PduRef.add(ref?.reference?.shortName.toString)}
        
      }
    }


    for(socketpduroute : soad?.soAdConfig?.soAdPduRoutes)
    {
      for(txpduref : socketpduroute?.soAdTxPduRef_PB)
      {
        SocketPduRoute_TxPduRef.add(txpduref?.reference?.shortName.toString)
      }
    }

   for(sdinstance : sd?.sdConfig?.sdInstances)
   {
    for(multicastrxpdu_rxpduref : sdinstance?.sdInstanceMulticastRxPdu?.sdRxPduRef_PB)
    {
       if(!SocketRouteDest_PduRef.contains(multicastrxpdu_rxpduref?.reference?.shortName.toString))
       {
        err58.add("Reference of parameter SdRxPduRef in container InstanceMulticastRxPdu of instance : "+
          sdinstance.shortName+" should match with the parameter SoAdRxPduRef in SoAdSocketRouteDest of SoAd\n")
       }
    }

    for(unicastrxpdu_rxpduref : sdinstance?.sdInstanceUnicastRxPdu?.sdRxPduRef_PB)
    {
       if(!SocketRouteDest_PduRef.contains(unicastrxpdu_rxpduref?.reference?.shortName.toString))
       {
          err58.add("Reference of parameter SdRxPduRef in container InstanceUnicastRxPdu of instance : "+
            sdinstance.shortName+" should match with the parameter SoAdRxPduRef in SoAdSocketRouteDest of SoAd\n")
        }
    }

    for(txpdu_rxpduref : sdinstance?.sdInstanceTxPdu?.sdTxPduRef_PB)
    {
       if(!SocketPduRoute_TxPduRef.contains(txpdu_rxpduref?.reference?.shortName.toString))
       {
          err58.add("Reference of parameter SdTxPduRef in container InstanceTxPdu of instance : "+
            sdinstance.shortName+" should match with the parameter SoAdTxPduRef in SoAdPduRoute of SoAd\n")
        }
    }
    }

       if(!(err58.nullOrEmpty))
       {
         return #[err58.join('\n\n')]
       }
  }
 }
 

  /*
   * Design ID : SD_SDD_0381
   * (ERR171061) Service ID shall not be set to 0xFFFF in SdClientService.
   */
  @ValidationRule( 
   code=171061, 
   name="Client Service ID shall not be set to 0xFFFF.",
   description="The Client Service ID shall not be set to 0xFFFF for any Instance ",
   message="The SdClientServiceId shall not be set to 0xFFFF for any SD_Instance",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
   )
   def static Object[] Client (SdInstance Client)
   {
     var Return = new ArrayList<String>
     var Flag1 = 0
     
     for (Count : 0..<Client.sdClientServices.size)
     {
       val List1 = Client.sdClientServices.get(Count).sdClientServiceId_PB.head.toString
       
       if(List1.equals("65535"))
       {
       	Flag1=1
       	Return.add(Client.sdClientServices.get(Count).shortName)
       }
     }
     if(Flag1 == 1)
     {
       return #[Return.join(",")]
     }
   }

  /*
   * Design ID : SD_SDD_0382
   * (ERR171062) Service Instance ID shall not be set to 0xFFFF in
   * SdClientService.
   */
  @ValidationRule( 
   code=171062, 
   name="Server Service ID shall not be set to 0xFFFF.",
   description="The Server Service ID shall not be set to 0xFFFF for any Instance",
   message="The SdServerServiceId shall not be set to 0xFFFF for any SD_Instance",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
   )
   def static Object[] Sd_ServerService(SdInstance _sdServerService)
  {
  	var ret_Path = new ArrayList<String>
  	var flag = 0
  	
  	for(Count  : 0..< _sdServerService.sdServerServices.size)
  	{
      val list = _sdServerService.sdServerServices.get(Count).sdServerServiceId_PB.head.toString
  	  if (list.equals("65535"))
  	  {
  	    flag=1
  	   	ret_Path.add(_sdServerService.sdServerServices.get(Count).shortName)
  	  }
  	}
  	if(flag == 1)
    {
      return #[ret_Path.join(",")]
    }
  }
  
  /*
   * Design ID : SD_SDD_0383
   * (ERR171063) Service Instance ID shall not be set to 0xFFFF in
   * SdClientService.
   */
  @ValidationRule( 
   code=171063, 
   name="Consumed Event Group ID shall not be set to 0xFFFF.",
   description="The Consumed Event Group ID shall not be set to 0xFFFF for any Instance",
   message="The SdConsumedEventGroupId shall not be set to 0xFFFF for any SD_Instance",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
   )
   def static Object[] Sd_Instance_clientService (SdClientService _sdinstance)
   {
   	var ret_Path = new ArrayList<String>
  	var flag = 0
  	
  	for(Count  : 0..< _sdinstance.sdConsumedEventGroups.size)
   
  	{
      val list = _sdinstance.sdConsumedEventGroups.get(Count).sdConsumedEventGroupId.toString
       if (list.equals("65535"))
  	  {
  	    flag=1
  	   	ret_Path.add(_sdinstance.sdConsumedEventGroups.get(Count).shortName)
  	  }
  	}
  	if(flag == 1)
    {
      return #[ret_Path.join(",")]
    }
      
   
}
  /*
   * Design ID : SD_SDD_0384
   * (ERR171064) Service Instance ID shall not be set to 0xFFFF in
   * SdClientService.
   */
  @ValidationRule( 
   code=171064, 
   name="SdClientServiceInstanceId shall not be set to 0xFFFF.",
   description="The SdClientServiceInstanceId shall not be set to 0xFFFF for any Instance",
   message="The SdClientServiceInstanceId shall not be set to 0xFFFF for any SD_Instance",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] Service_Instance(SdInstance _sdinstance)
  {
  	var ret_Path = new ArrayList<String>
  	var flag = 0
  	
  	for(Count  : 0..< _sdinstance.sdClientServices.size)
  	{
  	  val list = _sdinstance.sdClientServices.get(Count).sdClientServiceInstanceId_PB.head.toString
  	  if (list.equals("65535"))
  	  {
  	    flag=1
  	   	ret_Path.add(_sdinstance.sdClientServices.get(Count).shortName)
  	  }
  	}
  	if(flag == 1)
    {
      return #[ret_Path.join(",")]
    }
  }
  
  
  /*
   * Design ID : SD_SDD_0385
   * (ERR171065) SdServerServiceMajorVersion shall not be set to 0xFF.
   */
  @ValidationRule( 
   code=171065, 
   name="SdServerServiceMajorVersion shall not be set to 0xFF.",
   description="SdServerServiceMajorVersion can be only a value up to 0xFE, the value 0xFF (any) cannot occur in an OfferService entry.",
   message="The SdServerServiceMajorVersion shall not be set to 0xFF for any SD_Instance",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static Object[] Sd_Instance(SdInstance _sdinstance)
  {
  	var ret_Path = new ArrayList<String>
  	var flag = 0
  	
  	for(Count  : 0..< _sdinstance.sdServerServices.size)
  	{
      val list = _sdinstance.sdServerServices.get(Count).sdServerServiceMajorVersion_PB.head.toString
  	    if (list.equals("255"))
  	    {
  	      flag=1
  	      ret_Path.add(_sdinstance.sdServerServices.get(Count).shortName)
     	}
    }
    if(flag == 1)
    {
      return #[ret_Path.join(",")]
    }
  }
  

  /*
   * Design ID : SD_SDD_0386
   * (ERR171066) SdEventHandlerMulticastThreshold shall not exceed the range 0 to
   * 65535.
   */
  @ValidationRule( 
   code=171066, 
   name="SdEventHandlerMulticastThreshold shall not exceed the range 0 to 65535.",
   description="SdEventHandlerMulticastThreshold shall not exceed the range 0 to 65535.",
   message="The SdEventHandlerMulticastThreshold shall not exceed the range 0 to 65535",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
 def static Object[] Sd_Instance1(SdServerService _sdinstance)
  {
  	var return_Path = new ArrayList<String>
  	var flag = 0
  	for(Count  : 0..< _sdinstance.sdEventHandlers.size)
  	{
      val list = _sdinstance.sdEventHandlers.get(Count).sdEventHandlerMulticastThreshold_PB.head.toString
         if (list.equals("65536"))
  	    {
  	      flag=1
  	      return_Path.add(_sdinstance.sdEventHandlers.get(Count).shortName)
     	}
    }
    if(flag == 1)
    {
      return #[return_Path.join(",")]
    }
  }
  
  /*
   * Design ID : SD_SDD_0455
   * (ERR171080)value configured for 'ServiceGroupHandleId' parameter in container
   * 'ClientService'
   * should be sequential.
   */
  @ValidationRule( code=171080, name="Sd_Service_GroupHandle_Id sequential.",
   description="Check value of ServiceGroupHandleId starts from zero and is sequential and it should be within range 0 to 65535",
   message="The value configured for 'ServiceGroupHandleId' parameter in 'SdServiceGroup' container "+
         "should be sequential,within range 0 to 65535 and starting from <0> for each instance of <SdConfig>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean ServiceGroupHandleId_sequential(Sd  _sd)
  {
    var returnval = false
    var service_Grp_handleid = new ArrayList<Integer>()
    
    for(_sdInstance : _sd?.sdConfig?.sdServiceGroups_PB)
    {
      
        service_Grp_handleid.add(_sdInstance?.sdServiceGroupHandleId?.intValue)
      
    }

      if(service_Grp_handleid.nullOrEmpty)
      {
        returnval = true
      }

      else if((service_Grp_handleid.hasSequentialElements) && service_Grp_handleid.contains(0))
      {
           returnval = true
      }
      else if (service_Grp_handleid.contains(65536))
      	{
      		returnval = false
      	}
      
      else
      {
           returnval = false
      }



      return(returnval)
  }
    
  /*
   * Design ID : SD_SDD_0462
   * (ERR171090)value configured for 'SdInstanceLocalAdressCheckLength' parameter
   * in container 'Sd_Instance'
   * should be sequential.
   */
  @ValidationRule( code=171090, name="SdInstanceLocalAdressCheckLength.",
   description="Check value of SdInstanceLocalAdressCheckLength starts from zero and it should be within range 0 to 128",
   message="The value configured for 'ClientServiceHandleId' parameter in 'SdInstanceLocalAdressCheckLength' parameter "+
         "should be ,within range 0 to 128 and starting from <0> for each instance of <SdInstance>",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_InstanceLocalAdressCheckLength(Sd  _sd)
  {
    var returnval = false
    var InstanceLocalAdressCheckLength = new ArrayList<Integer>()

    for(_sdInstance : _sd?.sdConfig?.sdInstances)
    {
      
      
        InstanceLocalAdressCheckLength.add(_sdInstance?.sdInstanceLocalAdressCheckLength_PB?.head?.integerValue)
      
    }

      if(InstanceLocalAdressCheckLength.nullOrEmpty)
      {
        returnval = true
      }

      else if((InstanceLocalAdressCheckLength.head?.intValue < 0))
      
      {
           returnval = false
      }
      else if ((InstanceLocalAdressCheckLength.head?.intValue > 128))
      	{
      		returnval = false
      	}
      
      else
      {
           returnval = true
      }

      return(returnval)
  }

  /*
   * Design ID : SD_SDD_0595
   * (171091)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
 /* @ValidationRule( code=171091, name="SdIpAddress.",
   description="Check Size of SdClientServiceAllowedProvider SdIpAddress is greater than Zero",
   message="The value is not configured for 'SdClientServiceAllowedProvider' ",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_IpAddress(Sd  _sd)
  {
    var returnval = false


 
       if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      	if(_sd.sdConfig.sdInstances.head.sdClientServices.head.sdClientServiceAllowedProvider_PB.nullOrEmpty)
      	  {
              returnval = false
              
           }
           else
           { 
           	returnval = true
           }
      
       }
       else if(_sd.sdGeneral.sdEnableAclPolicyCheck == false)
       {
       	if(_sd.sdConfig.sdInstances.head.sdClientServices.head.sdClientServiceAllowedProvider_PB.nullOrEmpty)
       	{
       		returnval =true
       	}
       	else
       	{
       		returnval = false
       	}
       	
       }
  
      
   
      return(returnval)
  }
*/
  /*
   * Design ID : SD_SDD_0596
   * (171092)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
 /* @ValidationRule( code=171092, name="SdIpAddress.",
   description="Check Size of SdServerServiceAllowedConsumers SdIpAddress is greater than Zero",
   message="The value is not configured for 'SdServerServiceAllowedConsumers' ",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_IpAddress2(Sd  _sd)
  {
    var returnval = false


 
     if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      	if(_sd.sdConfig.sdInstances.head.sdServerServices.head.sdServerServiceAllowedConsumerss_PB.nullOrEmpty)
      	  {
              returnval = false
              
           }
           else
           { 
           	returnval = true
           }
      
  }
  else if(_sd.sdGeneral.sdEnableAclPolicyCheck == false) 
  {
  		if(_sd.sdConfig.sdInstances.head.sdServerServices.head.sdServerServiceAllowedConsumerss_PB.nullOrEmpty)
      	  {
              returnval = true
              
           }
           else
           { 
           	returnval = false
           }
  }
  
      
   
      return(returnval)
  }
*/
 /**
    *Design ID: SD_SDD_0600
    **/	 
/*@ValidationRule(
    code = 171093,
    name = "Check the Security Event reference in General container",
    description = "Check the SEV_SOME_IP_ACL_CHECK_FAILED_OFFER ,SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION,SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST
 referenced in General container",
    message = "{0}",
    mode = ModeEnum.LIVE,
    severity = ConstraintSeverity.ERROR
)
def static Object[] Sd_ReferencingCheck(Sd  _sd) 
{
    val SdEnableSecurityReporting = _sd.sdGeneral.sdEnableSecurityEventReporting
    val errorMessages = newArrayList
      var String str = ''
    var flag = 0
    if (SdEnableSecurityReporting === true) 
    {
        if (_sd.sdGeneral.sdSecurityEventRefs === null) 
        {
        	flag = 1
         str =   str +"sdSecurityEventRefs SEV_SOME_IP_ACL_CHECK_FAILED_OFFER , SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION ,SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST in General container are not configured"
        } 
        else 
        {
    	 	val Sd_checkfailedoffer = _sd.sdGeneral.sdSecurityEventRefs?.SEV_SOME_IP_ACL_CHECK_FAILED_OFFER
	     	val Sd_failedsubscription = _sd.sdGeneral.sdSecurityEventRefs?.SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION
	     	val Sd_methodrequest = _sd.sdGeneral.sdSecurityEventRefs?.SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST
	     	val Sd_duplicateoffer =( _sd.sdGeneral.sdSecurityEventRefs as SdSecurityEventRefs).SEV_SOME_IP_SD_DUPLICATE_OFFER
	     	 
            if (Sd_checkfailedoffer === null) 
            {
            	flag = 1
                  str =   str +"SEV_SOME_IP_ACL_CHECK_FAILED_OFFER container is not configured in sdSecurityEventRefs@"
            }
            if (Sd_failedsubscription === null) 
            {
            	flag = 1
                str =   str +"SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION container is not configured in sdSecurityEventRefs@"
                
            }
             if (Sd_methodrequest === null) 
            {
            	flag = 1
               str =   str +"SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST container is not configured in sdSecurityEventRefs@"
            }
           
              if (Sd_duplicateoffer === null) 
            {
              
            	flag = 1
                str =   str +"SEV_DUPLICATE_OFFER container is not configured in sdSecurityEventRefs@"
            }
        }
    }
	if(flag === 1)
	{
	str = str.substring(0,str.length()-1)
      str = str.replace("@",",\n")
      return #[str]
		
	} 
}
 /*
   * Design ID :
   * (171092)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
/*  @ValidationRule( code=171094, name="SdMaxNumOfIpAddressesInAcl.",
   description="Check value of SdMaxNumOfIpAddressesInAcl  is greater than one and less than 255",
   message="The value SdMaxNumOfIpAddressesInAcl is not configured for 'Sd_ClientService' which should not be less than 1 or greater than 255",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_SdMaxNumOfIpAddressesInAclClient(Sd  _sd)
  {
    var returnval = true


 
     if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdClientServices)
      	{
      		if(returnval == true)
      		{
      		if((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdClientService)?.sdMaxNumOfIpAddressesInAcl != null){
      			if(((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdClientService)?.sdMaxNumOfIpAddressesInAcl?.longValue < 1)
      				|| ((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdClientService)?.sdMaxNumOfIpAddressesInAcl?.intValue > 255))
      			{
      				
      				returnval = false
      				
      				
      			
      				
      			}
      			else
      			{
      				returnval = true
      			}
      			
      		
      			}
      		}
      	}
      }
     
  }

  
      
   
      return(returnval)
      
      }
      
    */  
   /*
   * Design ID :
   * (171095)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
/*  @ValidationRule( code=171095, name="SdMaxNumOfIpAddressesInAcl.",
   description="Check value of SdMaxNumOfIpAddressesInAcl  is greater than one and less than 255",
   message="The value SdMaxNumOfIpAddressesInAcl is not configured for 'Sd_ServerService' which should not be less than 1 or greater than 255",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_SdMaxNumOfIpAddressesInAclServer(Sd  _sd)
  {
    var returnval = true


 
     if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdServerServices)
      	{
      		if(returnval == true)
      		{
      		if((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdServerService)?.sdMaxNumOfIpAddressesInAcl != null){
      			
      			if(((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdServerService)?.sdMaxNumOfIpAddressesInAcl?.longValue < 1)
      				|| ((Sd_client as com.kpit.c4k.bsw.sd.autosar.kpit.Sd.SdConfig.SdInstance.SdServerService)?.sdMaxNumOfIpAddressesInAcl?.intValue > 255))
      			{
      				
      				returnval = false
      				
      				
      			
      				
      			}
      			else
      			{
      				returnval = true
      			}
      			
      		
      			}
      		}
      	}
      }
     
  }

  
      
   
      return(returnval)
      
      }
      
*/
      /*
   * Design ID :
   * (171096)value configured for 'SdAclCheckBlockDescriptorRef' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
  @ValidationRule( code=171096, name="BlockDescriptor",
   description="Check value of NVM Block length  should be equal or greater than the combine length of Configured ConsumerClient list and Provider server List",
   message="The value NVM Block length is to be configured with the Below Mention Formula
            (TolalRamBlock Length = Sizeof(Sd_ProviderConsumerListType)*SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER + 3BytePadding + 1Byte Boolean ),Sizeof(Sd_ProviderConsumerListType) is 32 Bytes Calculated for x86 system",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_SdBlocklength_Validator(Sd  _sd)
  {
  	  var  NVM_RAM_BLOCK_LENGTH_ =0
  	  var  CLIENT_CONFIGURED_VALUE =0
  	  var SERVER_CONFIGURED_VALUE =0
  	 
    var returnval = true
  NVM_RAM_BLOCK_LENGTH_ = (( _sd.sdConfig.sdAclCheckBlockDescriptorRef?.nvMNvBlockLength -4)/32)

    for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdClientServices)
      	{
      		if((Sd_client)?.sdMaxNumOfIpAddressesInAcl?.intValue != 0)
      		{
      		
      		  if((Sd_client)?.sdMaxNumOfIpAddressesInAcl?.intValue  >= (Sd_client )?.sdClientServiceAllowedProviders_PB?.size.intValue)
      		  
      		 { 
      		 
      		 	
      		CLIENT_CONFIGURED_VALUE += (Sd_client )?.sdMaxNumOfIpAddressesInAcl.intValue

      		
      		}
      		else 
      		{
      			if((Sd_client)?.sdClientServiceAllowedProviders_PB !== null)
      			{
      			
      				CLIENT_CONFIGURED_VALUE += (Sd_client )?.sdClientServiceAllowedProviders_PB?.size.intValue
      				
      				}
      		}
      		
      		}
      		else
      		{
      			if((Sd_client)?.sdClientServiceAllowedProviders_PB != null)
      
      			{
      				CLIENT_CONFIGURED_VALUE += (Sd_client)?.sdClientServiceAllowedProviders_PB?.size.intValue
      				
      				}
      		}
      		
      	}

      	}
      	
      	  for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdServerServices)
      	{
      		if((Sd_client )?.sdMaxNumOfIpAddressesInAcl?.intValue != 0)
      		{
      		
      		  if((Sd_client )?.sdMaxNumOfIpAddressesInAcl?.intValue  >= (Sd_client )?.sdServerServiceAllowedConsumerss_PB?.size.intValue)
      		  
      		 { 
      	
      		 	
      		SERVER_CONFIGURED_VALUE += (Sd_client )?.sdMaxNumOfIpAddressesInAcl.intValue

      		
      		}
      		else 
      		{
      			if((Sd_client )?.sdServerServiceAllowedConsumerss_PB !== null)
      			{
      			
      				SERVER_CONFIGURED_VALUE += (Sd_client )?.sdServerServiceAllowedConsumerss_PB?.size.intValue
      				
      				}
      		}
      		
      		}
      		else
      		{
      			if((Sd_client )?.sdServerServiceAllowedConsumerss_PB != null)
      		
      			{
      				SERVER_CONFIGURED_VALUE += (Sd_client )?.sdServerServiceAllowedConsumerss_PB?.size.intValue
      				
      				}
      		}
      		
      	}

      	}
      	
      
       	
     if(_sd.sdConfig.sdAclCheckBlockDescriptorRef !== null) 
      {
      	   
      	
      	if ((SERVER_CONFIGURED_VALUE+CLIENT_CONFIGURED_VALUE) > NVM_RAM_BLOCK_LENGTH_ )
      	{
      		
      		
      	
      
      	returnval = false	

      	
      		
      	}
      
     
     
      }

  
      
   
      return(returnval)
      
      }
  
 /*  
   * Design ID :
   * (171097)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
  @ValidationRule( code=171097, name="SdMaxNumOfIpAddressesInAcl.",
   description="Check value of SdMaxNumOfIpAddressesInAcl  is greater than one and less than 255",
   message="The value SdMaxNumOfIpAddressesInAcl less than the size of total configured Provide List Please configure value greater than or Equal",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_SdMaxNumOfIpAddressesInAclClient_1(Sd  _sd)
  {
    var returnval = true


 
     if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdClientServices)
      	{
      		if(returnval == true)
      		{
      		if((Sd_client)?.sdMaxNumOfIpAddressesInAcl != null){
      			if((Sd_client )?.sdMaxNumOfIpAddressesInAcl?.longValue  >= (Sd_client )?.sdClientServiceAllowedProviders_PB?.size.intValue)
      			{
      				
      				returnval = true
      				
      				
      			
      				
      			}
      			else
      			{
      				returnval = false
      			}
      			
      		
      			}
      		}
      	}
      }
     
  }

  
      
   
      return(returnval)
      
      }
   
      
    
	 /*
	  
   * Design ID :
   * (171098)value configured for 'SdEnableAclPolicyCheck' parameter in container
   * 'Sd_General'
   * should be sequential.
   */
  @ValidationRule( code=171098, name="SdMaxNumOfIpAddressesInAcl.",
   description="Check value of SdMaxNumOfIpAddressesInAcl  is greater than one and less than 255",
   message="The value SdMaxNumOfIpAddressesInAcl less than the size of total configured Consumer List Pls configure value greater than or Equal",
   mode=ModeEnum.LIVE,
   severity=ConstraintSeverity.ERROR
  )
  def static boolean sd_SdMaxNumOfIpAddressesInAclServer_1(Sd  _sd)
  {
    var returnval = true


 
     if(_sd.sdGeneral.sdEnableAclPolicyCheck == true) 
      {
      for(Sd_inst:_sd?.sdConfig?.sdInstances)
      {
      	for(Sd_client:Sd_inst?.sdServerServices)
      	{
      		if(returnval == true)
      		{
      		if((Sd_client)?.sdMaxNumOfIpAddressesInAcl != null){
      			
      			if((Sd_client )?.sdMaxNumOfIpAddressesInAcl?.longValue >= (Sd_client )?.sdServerServiceAllowedConsumerss_PB?.size.intValue)
      			{
      				
      				returnval = true
      				
      				
      			
      				
      			}
      			else
      			{
      				returnval = false
      			}
      			
      		
      			}
      		}
      	}
      }
     
  }

  
      
   
      return(returnval)
      
      }
     

}
