/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_IntTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovert                                     **
**                                                                            **
**  PURPOSE   : This File contains internal types referred by Sd              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
**  Design ID : SD_SDD_0449                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date         Changed By          Description                               **
********************************************************************************
** 07-Jul-2025  Gourav Purohit      Initial Release.                          **
**                                                                            **
*******************************************************************************/

#ifndef SD_INT_TYPES_H
#define SD_INT_TYPES_H

/*******************************************************************************
**                   MISRA-C:2012 violations Section                          **
*******************************************************************************/

/* #violates #ref Sd_IntTypes_h_REF_1 Violates MISRA 2012 Required Rule 19.2*/
/* A union type specifier has been defined.*/
/* PRQA S 0750 EOF */

/* #violates #ref Sd_IntTypes_h_REF_1 Violates MISRA 2012 Dir-4.9 (Advisory)*/
/* A function could probably be used instead of this function-like macro. */
/*PRQA S 3453 EOF */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Design ID : SD_SDD_0449 */
/*Design ID : SD_SDD_0488,SD_SDD_0512,SD_SDD_0479,SD_SDD_0515,SD_SDD_0514,SD_SDD_0517,SD_SDD_0516,
SD_SDD_0519,SD_SDD_0518,SD_SDD_0490,SD_SDD_0492,SD_SDD_0491,SD_SDD_0494,SD_SDD_0493,SD_SDD_0496,
SD_SDD_0495,SD_SDD_0531,SD_SDD_0498,SD_SDD_0530,SD_SDD_0497,SD_SDD_0533,SD_SDD_0532,SD_SDD_0499,
SD_SDD_0524,SD_SDD_0523,SD_SDD_0526,SD_SDD_0525,SD_SDD_0528,SD_SDD_0527,SD_SDD_0529,SD_SDD_6001,
SD_SDD_6002,SD_SDD_6003,SD_SDD_0382,SD_SDD_0381,SD_SDD_0384,SD_SDD_6008,SD_SDD_6009,SD_SDD_0540,
SD_SDD_6004,SD_SDD_0542,SD_SDD_6005,SD_SDD_0541,SD_SDD_6006,SD_SDD_0544,SD_SDD_6007,SD_SDD_0543,
SD_SDD_175,SD_SDD_0535,SD_SDD_0534,SD_SDD_0537,SD_SDD_0536 */
/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/* This parameter is the maximum supported length of the OtherServ value
 * (after the = sign) */
/*Design ID : SD_SDD_0035*/
#define SD_OTHERSERV_SIZE (32U)
#define SD_MEMSET MEMSET

#define SD_ZERO (0x00U)
#define SD_ONE (0x01U)
#define SD_TWO (0x02U)
#define SD_THREE (0x03U)
#define SD_FOUR (0x04U)
#define SD_FIVE (0x05U)
#define SD_SIX (0x06U)
#define SD_SEVEN (0x07U)
#define SD_EIGHT (0x08U)
#define SD_NINE (0x09U)
#define SD_TEN (0x0AU)
#define SD_ELEVEN (0x0BU)
#define SD_TWELVE (0x0CU)
#define SD_THIRTEEN (0x0DU)
#define SD_FOURTEEN (0x0EU)
#define SD_FIFTEEN (0x0FU)
#define SD_SIXTEEN (0x10U)
#define SD_TWENTY (0x14U)
#define SD_TWENTY_ONE (21U)
#define SD_TWENTY_TWO (22U)
#define SD_TWENTY_FOUR (24U)
#define SD_THIRTY_TWO (32U)
#define SD_EIGHTTEEN (0x12U)

#define SD_SIXTY_FOUR (64U)

#define SD_RETRY_MAX (0xFFU)

#define SD_NINETY_SIX (96U)

#define SD_ONE_TWENTY_EIGHT (128U)

#define SD_INVALID (0xFFU)

/* #violates #ref Sd_Internal_h_REF_1 Violates MISRA 2012 Required Rule
  4.9*/

#if (STD_ON == SD_PRE_COMPILE_SINGLE)

#define SD_GP_FIRST_GAA_INSTANCES_STATIC &Sd_GaaInstanceStatic[0]

#define SD_GP_FIRST_GAA_CLIENT_SERVICE_STATIC &Sd_GaaClientServiceStatic[0]

#define SD_GP_FIRST_GAA_SERVER_SERVICE_STATIC &Sd_GaaServerServiceStatic[0]

#define SD_GP_FIRST_GAA_CONSUMED_EV_GRP_STATIC &Sd_GaaConsumedEvGrpStatic[0]

#define SD_GP_FIRST_GAA_EV_HANDLER_STATIC &Sd_GaaEvHandlerStatic[0]

#define SD_GP_FIRST_GAA_RX_PDU_MAP_ARRAY &Sd_GaaRxPduMapArray[0]

#define SD_GP_FIRST_GAA_SO_CON_GROUP_STATIC &Sd_GaaSoConGroupStatic[0]

#else

#define SD_GP_FIRST_GAA_INSTANCES_STATIC &Sd_GpConfigPtr->pInstanceStatic[0];
#define SD_GP_FIRST_GAA_CLIENT_SERVICE_STATIC &Sd_GaaClientServiceStatic[0]
#define SD_GP_FIRST_GAA_SERVER_SERVICE_STATIC &Sd_GaaServerServiceStatic[0]
#define SD_GP_FIRST_GAA_CONSUMED_EV_GRP_STATIC &Sd_GaaConsumedEvGrpStatic[0]
#define SD_GP_FIRST_GAA_EV_HANDLER_STATIC &Sd_GaaEvHandlerStatic[0]
#define SD_GP_FIRST_GAA_RX_PDU_MAP_ARRAY &Sd_GaaRxPduMapArray[0]
#define SD_GP_FIRST_GAA_SO_CON_GROUP_STATIC &Sd_GaaSoConGroupStatic[0];
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GblInitCalled;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_8
#include "Sd_MemMap.h"
extern uint8 Sd_GucSdInstanceIndex;
#define SD_STOP_SEC_VAR_CLEARED_8
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sd_MemMap.h"
extern PduInfoType Sd_GddPduInfoPtr;
#define SD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sd_MemMap.h"
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GaaAclPolicyFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#else
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GaaAclPolicyFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
**                      Structure definitions                                 **
*******************************************************************************/

/* Design_ID : SD_SDD_0096*/
typedef struct STag_Sd_EvHandlerType
{

  Sd_EventHandlerCurrentStateType enEvHandlerCurrState;
  uint8 ucNoOfSubGrpsTcp;
  uint8 ucNoOfSubGrpsUdp;
} Sd_EvHandlerType;

/* Design_ID : SD_SDD_0094*/
typedef struct STag_Sd_EvHandlerSubGrpFlagType
{

  uint8 blTcpActiveEv : 1;

  uint8 blUdpActiveEv : 1;

  unsigned int ucEvHandlerReserved : 5; /* Reserved */
} Sd_EvHandlerSubGrpFlagType;

/* Design_ID : SD_SDD_0095*/
typedef struct STag_Sd_SubEventGroupType
{
  uint32 ulEvSubGrpTtlCount;

  TcpIp_SockAddrType LstSubGrpRemoteAddr;
  SoAd_SoConIdType ddSoConUdpIndex;
  SoAd_SoConIdType ddSoConTcpIndex;

  uint8 ucSubGrpCounter;

  Sd_EvHandlerSubGrpFlagType stEvHandlerFlag;

} Sd_EvHandlerSubGrpType;

/* Design_ID : SD_SDD_0097*/ /*[SWS_SD_00150]*/
typedef struct STag_Sd_InstancePartnerFlagType
{

  boolean blInstancePartnerActive;

  boolean blUnicastRebootFlagRecd;

  boolean blMulticastRebootFlagRecd;

  boolean blUnicastRebootFlagTx;
  uint8 ucReserved : 4;
} Sd_InstancePartnerFlagType;

/* Design_ID : SD_SDD_0099*/
typedef struct STag_Sd_Instance
{
  boolean blMulticastRebootFlagTx;

  uint8 usSendNoOfEntrys;

  uint8 usSendNoOfOptions;

  uint16 usSendPduSize;

  uint16 usMulticastSessionIdTx;

  TcpIp_SockAddrType stSubnetAddr;

  TcpIp_IpAddrStateType enIpAddrState;

#if (STD_ON == SD_IPV6_ENABLED)
  TcpIp_SockAddrInet6Type stSubnetNetmask;
#else
  TcpIp_SockAddrInetType stSubnetNetmask;
#endif

} Sd_InstanceType;

/* Design_ID : SD_SDD_0098*/ /*[SWS_SD_00032]*/
typedef struct Stag_Sd_InstancePartner
{
  /* This is the flag for the instance partner */
  Sd_InstancePartnerFlagType stInstancePartnerFlag;

  /* This is the remote IP address of the communication partner */
  TcpIp_SockAddrType stRemoteAddr;

  /* The Session Id that is received via unicast
   * (stored for reboot checking)*/
  uint16 usUnicastSessionIdRecd;

  /* The Session Id that is received via Multicast
   * (stored for reboot checking) */
  uint16 usMulticastSessionIdRecd;

  /* The Session Id that is Transmit via Unicast */
  uint16 usUnicastSessionIdTx;

} Sd_InstancePartnerType;

/* Design_ID : SD_SDD_0049,SD_SDD_0112*/
typedef enum ETag_Sd_TypeOfEntryType
{
  SD_FIND_SERVICE_ENTRY,
  SD_OFFER_SERVICE_ENTRY,
  SD_STOP_OFFER_SERVICE_ENTRY,
  SD_SUBSCRIBE_ENTRY,
  SD_SUBSCRIBE_ACK_ENTRY,
  SD_STOP_SUBSCRIBE_ENTRY,
  SD_SUBSCRIBE_NACK_ENTRY
} Sd_TypeOfEntryType;

/* Design_ID : SD_SDD_0090*/
/* [SWS_SD_00160], [SWS_SD_00161] */
typedef struct STag_Sd_Entry1DataType
{
  uint8 ucEntryType;
  uint8 ucIndex1;
  uint8 ucIndex2;
  uint8 ucNoOfOptions1;
  uint8 ucNoOfOptions2;
  uint8 ucMajorVersion;
  uint16 usServiceId;
  uint16 usInstanceId;
  uint32 ulTtlsec;
  uint32 ulMinorVersion;
} Sd_Entry1DataType;

/* Design_ID : SD_SDD_0091*/ /*SWS_SD_00184*/
typedef struct STag_Sd_Entry2DataType
{
  uint8 ucEntryType;
  uint8 ucIndex1;
  uint8 ucIndex2;
  uint8 ucNoOfOptions1;
  uint8 ucNoOfOptions2;
  uint8 ucMajorVersion;
  uint8 usReserved;
  uint8 ucCounter;
  uint16 usServiceId;
  uint16 usInstanceId;
  uint16 usEventGroupId;
  uint32 ulTtlsec;
  uint32 ulMinorVersion;
} Sd_Entry2DataType;

/* Design_ID : SD_SDD_0092*/ /*[SWS_SD_00183] */

typedef union UTag_SdEntryDataType
{
  Sd_Entry1DataType stEntry1;
  Sd_Entry2DataType stEntry2;
} Sd_EntryDataType;

/* Design_ID : SD_SDD_0093*/
typedef struct STag_EntryType
{
  Sd_TypeOfEntryType enTypeOfEntry;
  Sd_EntryDataType unEntryData;
} Sd_EntryType;

/* Design_ID : SD_SDD_0050,SD_SDD_0113 */
/*[SWS_SD_00217] */
typedef enum ETag_Sd_TypeOfOptionsType
{
  SD_CONFIGURATION_OPTION,
  SD_IPV4_ENDPOINT_OPTION,
  SD_IPV4_MULTICAST_OPTION,
  SD_IPV4_SD_ENDPOINT_OPTION,
  SD_IPV6_ENDPOINT_OPTION,
  SD_IPV6_MULTICAST_OPTION,
  SD_IPV6_SD_ENDPOINT_OPTION
} Sd_TypeOfOptionsType;

typedef enum ETag_Sd_TypeOfSecurityEventsType
{
  SD_NO_IDSM_EVENT,
  SD_SOME_IP_ACL_CHECK_FAILED_OFFER,
  SD_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION,
  SD_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST,
  SD_DUPLICATE_OFFER

} Sd_TypeOfSecurityEventsType;

/* Design_ID : SD_SDD_0103*/
typedef struct STag_Sd_OptionsRefType
{
  const uint8 *pConfigOption;

  Sd_TypeOfOptionsType enTypeOfOption;

  SoAd_SoConIdType ddLocalAddrSoConId;

  uint8 ucProtocol;

} Sd_OptionsRefType;

/* Design_ID : SD_SDD_0101*/ /*[SWS_SD_00212] [SWS_SD_00214] [SWS_SD_00215]
[SWS_SD_00396]  */
typedef struct STag_Sd_OptionsIpv4Type
{
  uint32 ulIpAddr;
  uint16 usPortNo;
  uint8 ucProtocol;
} Sd_OptionsIpv4Type;

#if (STD_ON == SD_IPV6_ENABLED)
/* Design_ID : SD_SDD_0102*/ /*[SWS_SD_00219] [SWS_SD_00221] [SWS_SD_00222] */
typedef struct STag_Sd_OptionsIpv6Type
{
  uint32 *pIpAddr;
  uint16 usPortNo;
  uint8 ucProtocol;
} Sd_OptionsIpv6Type;
#endif

/* Design_ID : SD_SDD_0104*/ /*SD_SRS_369 [SWS_SD_00658]*/
/* violates #ref SD_INTTYPES_H_REF_1 Violates MISRA 2012 Required Rule 19.2 */
typedef union UTag_Sd_OptionsUnionType
{
  Sd_OptionsIpv4Type stOptionsIpv4;
#if (STD_ON == SD_IPV6_ENABLED)
  Sd_OptionsIpv6Type stOptionsIpv6;
#endif
  uint8 aaOtherServ[SD_OTHERSERV_SIZE];
} Sd_OptionsUnionType;

/* Design_ID : SD_SDD_0100*/
typedef struct STag_SdOptionsDataType
{
  Sd_TypeOfOptionsType enTypeOfOption;
  Sd_OptionsUnionType unOptionsData;
} Sd_OptionsDataType;

/* Design_ID : SD_SDD_0105*/
typedef struct STag_Sd_QueueType
{
  /* This is TRUE if data is to be sent via unicast else FALSE*/
  boolean blSendUnicast;
  /* This is the reference to the SdInstance for this entry - used to
   *   determine the match for combining of multicast transmitted entries  */
  uint8 ucSdInstanceIndex;
  /* This is a generic Index. The array it points to  depends on the type of
   *   entry.  It is used to access the ServerService, EvHandler and other
   *   structures to generate the options */
  Sd_ServicesType ddGenericIndex;
  /* This is the SoConId that is used to transmit the UDP option. This is used
   * for the transmission of the Subscribe and StopSubscribe entries only */
  SoAd_SoConIdType ddSoConIdUdp;
  /* This is the SoConId that is used to transmit the TCP option. This is used
   * for the transmission of the Subscribe and StopSubscribe entries only */
  SoAd_SoConIdType ddSoConIdTcp;
  /* This is the IP address that the packet is to be sent to. */
  TcpIp_SockAddrType stSendAddr;
  /* This is the delay count for the sending of the entry. It is '0' for
   * immediate sending. */
  uint32 ulDelayCount;
  /* This is the Entry Data Union */
  Sd_EntryType stEntryData;
} Sd_QueueType;

/* Design_ID : SD_SDD_0110*/
typedef enum ETag_Sd_ServerServicePhaseType
{
  SD_SERVER_DOWN,
  SD_SERVER_INITIAL_WAIT,
  SD_SERVER_REPETITION,
  SD_SERVER_MAIN
} Sd_ServerServicePhaseType;

/* Design_ID : SD_SDD_0106*/
typedef struct STag_Sd_ServerServiceType
{

  uint32 ulServerDelayCount;

  uint32 ulServerTtlCount;

  Sd_ServerServicePhaseType enServerPhase;

  Sd_ServerServiceSetStateType enServerServiceSetState;

  uint8 ucNoOfOffersSent;

} Sd_ServerServiceType;

/* Design_ID : SD_SDD_0109*/
typedef enum ETag_Sd_ClientServicePhaseType
{
  SD_CLIENT_DOWN,
  SD_CLIENT_INITIAL_WAIT,
  SD_CLIENT_REPETITION,
  SD_CLIENT_MAIN
} Sd_ClientServicePhaseType;

/* Design_ID : SD_SDD_0085*/
typedef struct STag_Sd_ClientFlagType
{
  uint8 blOfferAvailable : 1;

  uint8 blOfferMaxTtl : 1;

  uint8 blOfferTtlExpired : 1;

  uint8 blTcpActive : 1;

  uint8 blUdpActive : 1;

} Sd_ClientFlagType;

/* Design_ID : SD_SDD_0086*/
typedef struct STag_Sd_ClientServiceType
{
  Sd_ClientFlagType stClientFlag;

  uint32 ulOfferTtlCount;

  uint32 ulClientDelayCount;

  uint32 ulClientRetrySubDelayCount;

  Sd_ClientServicePhaseType enClientPhase;

  Sd_ClientServiceCurrentStateType enClientCurrState;

  Sd_ClientServiceSetStateType enClientSetState;

  TcpIp_SockAddrType stOfferEndpointAddrTcp;
  TcpIp_SockAddrType stOfferEndpointAddrUdp;
  TcpIp_SockAddrType stOfferRemoteAddr;

  SoAd_SoConIdType ddOfferSoConIndexUdp;

  SoAd_SoConIdType ddOfferSoConIndexTcp;

  uint8 ucNoOfOffersSent;

} Sd_ClientServiceType;

/* Design_ID : SD_SDD_0088*/
typedef struct STag_Sd_ConsumedEvGrpFlagType
{

  uint8 blRoutingEnabled : 1;

  uint8 blMulticastRoutingEnabled : 1;

  uint8 blConEvGrpTtlExpired : 1;

  uint8 blUnicastOfferRecd : 1;

  uint8 blSubscribeSent : 1;

  uint8 blSubscribeAckRecd : 1;

  uint8 blSubscribeNAckRecd : 1;

  uint8 ucReserved : 2;
} Sd_ConsumedEvGrpFlagType;

/* Design_ID : SD_SDD_0089*/
typedef struct STag_Sd_ConsumedEvGrpType
{
  Sd_ConsumedEvGrpFlagType stConsumedEvGrpFlag;

  Sd_ConsumedEventGroupCurrentStateType enConEvGrpCurrState;

  Sd_ConsumedEventGroupSetStateType enConEvGrpSetState;

  uint32 ulConEvGrpTtlCount;

  uint32 ulConEvGrpRetryCount;

  SoAd_SoConIdType ddSoConIdTcp;

  SoAd_SoConIdType ddSoConIdUdp;

  SoAd_SoConIdType ddSoConGrpIndexMulticast;

  SoAd_SoConIdType ddSoConIdMulticast;

} Sd_ConsumedEvGrpType;

/* Design_ID : SD_SDD_0087*/ /*[SWS_SD_00696a]*/
typedef struct Sd_SoConFlagType
{

  uint8 blWildcardSocketServer : 1;

  uint8 blWildcardSocketClient : 1;

  uint8 blSocketOpened : 1;

  uint8 ucReserved : 5;
} Sd_CoConFlagType;

/* Design_ID : SD_SDD_0108*/
typedef struct STag_Sd_SoConType
{
  /* This is the no of connected Server services for that socket connection */
  uint16 usNoOfSubServers;
  /* This is the no of connected Client services for that socket connection */
  uint16 usNoOfSubClients;
  /* Socket Connection flag */
  Sd_CoConFlagType stSoConFlag;

  /* Socket connection mode */
  SoAd_SoConModeType ddSoaASoConMode;
} Sd_SoConType;

/* Design_ID : SD_SDD_0107*/
typedef struct STag_Sd_SoConGroupType
{

  uint16 usNoOfSubConEvGrp;

  boolean blWildcardConEvGrp;

} Sd_SoConGroupType;

typedef struct STag_Sd_ClientCounterType
{

  uint16 usClientRequestCounter;

} Sd_ClientCounterType;
typedef struct STag_Sd_ServerCounterType
{

  uint16 usServerAvailabilityCounter;

} Sd_ServerAvailabilityCounterType;

/* Design_ID : SD_SDD_0111*/
typedef enum ETag_Sd_TcpUdpEnumType
{
  SD_TCP,
  SD_UDP
} Sd_TcpUdpEnumType;
typedef struct STag_Sd_SoconIndexRertunType
{

  SoAd_SoConIdType usIndexTCP;
  SoAd_SoConIdType usIndexUDP;

} Sd_SoconIndexRertunType;

typedef struct STag_Sd_AclUpdateReturnType
{

  boolean Wildcard;
  uint8 usindex;

} Sd_AclUpdateReturnType;
/* Design ID :SD_SDD_0383,SD_SDD_0386,SD_SDD_0462,SD_SDD_0385,SD_SDD_0346,SD_SDD_0345,SD_SDD_0457 */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
