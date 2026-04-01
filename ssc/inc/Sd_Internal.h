/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Internal.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovert                                     **
**                                                                            **
**  PURPOSE   : This File contains internal functions and macros required by  **
**              Service Discovery                                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
** Design ID : SD_SDD_0448                                                    **
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date         Changed By          Description                               **
********************************************************************************
** 07-Jul-2025  Gourav Purohit      Initial Release.                          **
**                                                                            **
*******************************************************************************/
#ifndef SD_INTERNAL_H
#define SD_INTERNAL_H

/*******************************************************************************
**                   MISRA-C:2012 violations Section                          **
*******************************************************************************/

/* violates #ref SD_Internal_H_REF_2 Violates MISRA 2012 Required Rule D1.1 */
/*The keyword 'inline' has been used.*/
/* PRQA S 1055 EOF */

/*#violates #ref SD_Internal_H_REF_2 Violates MISRA 2012 Dir 1.1*/
/* Number of macro definitions exceeds 1024*/
/* PRQA S 0857 EOF */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Design ID : SD_SDD_0448 */
/*Design ID : SD_SDD_0582,SD_SDD_0461,SD_SDD_0581,SD_SDD_0586,SD_SDD_0585,SD_SDD_0500,
 SD_SDD_0467,SD_SDD_0466,SD_SDD_0579,SD_SDD_0578,,SD_SDD_0470,SD_SDD_0472,
 SD_SDD_0471,SD_SDD_0595,SD_SDD_0474,SD_SDD_0473,SD_SDD_0597,SD_SDD_0476,SD_SDD_0596,SD_SDD_0475,
 SD_SDD_0511,SD_SDD_0510,SD_SDD_0477,SD_SDD_0502,SD_SDD_0501,SD_SDD_0468,SD_SDD_0504,SD_SDD_0503,SD_SDD_0506,
 SD_SDD_0505,SD_SDD_0508,SD_SDD_0507,SD_SDD_0509,SD_SDD_0361,SD_SDD_0444,SD_SDD_0446,SD_SDD_0481,SD_SDD_0480,SD_SDD_0483,
 SD_SDD_0482,SD_SDD_0485,SD_SDD_0484,SD_SDD_0520,SD_SDD_0487,SD_SDD_0486,SD_SDD_0522,SD_SDD_0247,SD_SDD_0489,SD_SDD_0521 */
/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/*Design ID : SD_SDD_0028*/
#define SD_MAX_PDU_SIZE (1460U)

/*Design ID : SD_SDD_0028*/
#define SD_MAX_ENTRIES (32U)

/*Design ID : SD_SDD_0028*/
#define SD_MAX_EVENT_SUB_GROUPS (16U)

/*Design ID : SD_SDD_0028*/
#define SD_MAX_INSTANCE_PARTNER (16U)

/*Design ID : SD_SDD_0048*/ /*SWS_SD_00312*/ /*[SWS_SD_00313]*/
/*SWS_SD_00316*/                             /*SWS_SD_00314*/
#define SD_ENTRY_TYPE_FIND (0x00U)
#define SD_ENTRY_TYPE_OFFER (0x01U)
#define SD_ENTRY_TYPE_STOP_OFFER (0x01U)
#define SD_ENTRY_TYPE_SUBSCRIBE (0x06U)
#define SD_ENTRY_TYPE_STOP_SUBSCRIBE (0x06U)
#define SD_ENTRY_TYPE_SUBSCRIBE_ACK (0x07U)
#define SD_ENTRY_TYPE_SUBSCRIBE_NACK (0x07U)

/*Design ID : SD_SDD_0043*/ /*[SWS_SD_00207] [SWS_SD_00397]*/
#define SD_OPTION_TYPE_CONFIG (0x01U)
#define SD_OPTION_TYPE_IPV4_ENDPOINT (0x04U)
#define SD_OPTION_TYPE_IPV6_ENDPOINT (0x06U)
/*[SWS_SD_00391] [SWS_SD_00398] */
#define SD_OPTION_TYPE_IPV4_MULTICAST (0x14U)
#define SD_OPTION_TYPE_IPV6_MULTICAST (0x16U)
#define SD_OPTION_TYPE_IPV4_SD_ENDPOINT (0x24U)
#define SD_OPTION_TYPE_IPV6_SD_ENDPOINT (0x26U)

/*Design ID : SD_SDD_0042*/ /*[SWS_SD_00209] [SWS_SD_00216] [SWS_SD_00390] */
#define SD_IPV4_OPTION_LENGTH (0x09U)
#define SD_IPV6_OPTION_LENGTH (0x15U)

/*[SWS_SD_00176]]*/
/*Design ID : SD_SDD_0037*/
#define SD_SERVICE_ID_ALL_MATCH (0xFFFFU)
/*Design ID : SD_SDD_0037*/
#define SD_INSTANCE_ID_ALL_MATCH (0xFFFFU)
/*Design ID : SD_SDD_0037*/
#define SD_MAJOR_VERSION_ALL_MATCH (0xFFU)
/*Design ID : SD_SDD_0037*/
#define SD_MINOR_VERSION_ALL_MATCH (0xFFFFFFFFU)
/*Design ID : SD_SDD_0037*/
#define SD_EVENT_GROUP_ID_ALL_MATCH (0xFFFFU)

/*Design ID : SD_SDD_0035*/
#define SD_SERVICE_ID_OTHERSERV (0xFFFEU)
/*Design ID : SD_SDD_0028*/
#define SD_TTL_SEC_MAX (0xFFFFFFUL)
/*Design ID : SD_SDD_0028*/
#define SD_TTL_COUNT_MAX (0xFFFFFFFFU)
/*Design ID : SD_SDD_0028*/
#define SD_SESSION_ID_MAX (0xFFFFU)
/*Design ID : SD_SDD_0028*/
#define SD_IP_ADDR_MAX (0xFFFFFFFFU)

#define SD_HIGH_NIBBLE_MASK (0xF0U)
#define SD_LOW_NIBBLE_MASK (0x0FU)

#define SD_BYTE_MASK (0xFFU)

#define SD_COUNTER_MASK (0x0FU)

/*Design ID : SD_SDD_0044*/
#define SD_QUEUE_EMPTY (0x00U)
#define SD_QUEUE_FULL (0x01U)

/*[SWS_SD_00143]*/
/*Design ID : SD_SDD_0034*/
#define SD_CLIENT_ID (0x0000U)
/*[SWS_SD_00141]*/
/*Design ID : SD_SDD_0034*/
#define SD_PROTOCOL_VERSION (0x01U)
/*Design ID : SD_SDD_0034*/
#define SD_INTERFACE_VERSION (0x01U)
/*Design ID : SD_SDD_0034*/
#define SD_MESSAGE_TYPE (0x02U)
/*SWS_SD_00147*/
/*Design ID : SD_SDD_0034*/
#define SD_RETURN_CODE (0x00U)

#define SD_UNICAST_FLAG_MASK (0x40U)

#define SD_REBOOT_FLAG_MASK (0x80U)

#define SD_UNICAST_REBOOT_FLAG (0xC0U)

/*Design ID : SD_SDD_0039*/
#define SD_OPTIONS_NOT_FOUND (0x00U)
#define SD_TCP_OPTIONS_MASK (0x01U)
#define SD_UDP_OPTIONS_MASK (0x02U)
#define SD_OPTIONS_MALFORMED_MASK (0x04U)

/*Design ID : SD_SDD_0046*/ /*[SWS_SD_00395] [SWS_SD_00414] */
#define SD_PROTOCOL_TCP (0x06U)
#define SD_PROTOCOL_UDP (0x11U)

#define SD_FALSE SD_ZERO
#define SD_TRUE SD_ONE

/*Design ID : SD_SDD_0041*/
#define SD_NULL_PTR (NULL_PTR)


/*Design ID : SD_SDD_0026*/
#define SD_DEM_INVALID (0xFFFFU)

/*Design ID : SD_SDD_0027*/
#define SD_UNUSED(Var) ((void)(Var))

/*Design ID : SD_SDD_0031*/
#define SD_WILDCARD_PORT (0x00U)
/*Design ID : SD_SDD_0031*/
#define SD_WILDCARD_ADDR (0x00U)

#define SD_SERVICE_ID_TYPE_TWO_ENTRY_CHECK (0xFFFEU)

/*Design ID : SD_SDD_0036*/
#define SD_LCG_CONSTANT_1 (125)
/*Design ID : SD_SDD_0036*/
#define SD_LCG_CONSTANT_2 (12345)
/*Design ID : SD_SDD_0036*/
#define SD_LCG_CONSTANT_3 (0x07FF)
/*Design ID : SD_SDD_0036*/
#define SD_LCG_CONSTANT_4 (0x03FF)
/*Design ID : SD_SDD_0036*/
#define SD_RANDOM_NUM_INIT (150)

/*Design ID : SD_SDD_0032*/
#define SD_MATCHED_AND_EXISTING (0x00U)
/*Design ID : SD_SDD_0032*/
#define SD_NOT_MATCHED_AND_FREE (0x01U)
/*Design ID : SD_SDD_0032*/
#define SD_NOT_MATCHED_AND_NOT_FREE (0x02U)

#define SD_THIRTY_TWO_SET_BIT (0XFFFFFFFFU)
#define SD_SEC_TO_MS (0x03E8U)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Design ID : SD_SDD_0009, SD_SDD_0008, SD_SDD_0059 */
/*[SD_SRS_157a] [SD_SRS_158a] SWS_SD_00106 SWS_SD_00708 SWS_SD_00707*/
#define SD_REPORT_DEM_MALFORMED(LpInstanceStatic)                                   \
    do                                                                              \
    {                                                                               \
        if (SD_DEM_INVALID != (LpInstanceStatic)->usDemErrorMalformedId)            \
        {                                                                           \
            (void)Dem_SetEventStatus((LpInstanceStatic)->usDemErrorMalformedId,     \
                                     (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED); \
        }                                                                           \
    } while (0)
/*SWS_SD_00707*/
#define SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic)                                  \
    do                                                                              \
    {                                                                               \
        if (SD_DEM_INVALID != (LpInstanceStatic)->usDemErrorOutOfResId)             \
        {                                                                           \
            (void)Dem_SetEventStatus((LpInstanceStatic)->usDemErrorOutOfResId,      \
                                     (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED); \
        }                                                                           \
    } while (0)
/*SWS_SD_00707 4.3.0*/
#define SD_E_SUBSCR_NACK_RECV(LpInstanceStatic)                                         \
    do                                                                                  \
    {                                                                                   \
        if (SD_DEM_INVALID != (LpInstanceStatic)->usDemErrorSubEventgroupNackId)        \
        {                                                                               \
            (void)Dem_SetEventStatus((LpInstanceStatic)->usDemErrorSubEventgroupNackId, \
                                     (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);     \
        }                                                                               \
    } while (0)

#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
extern const Sd_ServicesType Sd_GaaRxPduMapArray[SD_NO_OF_INSTANCES * SD_TWO];
#else
extern const Sd_ServicesType Sd_GaaRxPduMapArray[SD_NO_OF_INSTANCES * SD_TWO];
#endif
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_OptionsDataType Sd_GaaRxOptionsData[SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GaaBswMEvNotifiFlag[SD_NO_OF_EV_HANDLERS];
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GblTxSuccessFLag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GblSubscribeInQueue;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
 extern boolean Sd_GblBswClientRepitionStateFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern  boolean Sd_GblBswServerRepitionStateFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

/*#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#define SD_START_SEC_VAR_CLEARED_PTR
#include "Sd_MemMap.h"
extern const Sd_ConfigType_PB * Sd_GpConfigPtr;
extern const Sd_InstanceStaticType*
SD_GP_FIRST_GAA_INSTANCES_STATIC;
extern const Sd_ClientServiceStaticType* SD_GP_FIRST_GAA_CLIENT_SERVICE_STATIC;
extern const Sd_ServerServiceStaticType* SD_GP_FIRST_GAA_SERVER_SERVICE_STATIC;
extern const Sd_ConsumedEvGrpStaticType* SD_GP_FIRST_GAA_CONSUMED_EV_GRP_STATIC;
extern const Sd_EvHandlerStaticType * SD_GP_FIRST_GAA_EV_HANDLER_STATIC;
extern const Sd_ServicesType * SD_GP_FIRST_GAA_RX_PDU_MAP_ARRAY;
extern const Sd_SoConGroupStaticType * SD_GP_FIRST_GAA_SO_CON_GROUP_STATIC;
#define SD_STOP_SEC_VAR_CLEARED_PTR
#include "Sd_MemMap.h"
#endif
*/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ClientTimerStaticType Sd_GSaaClientTimerStatic[SD_NO_OF_CLIENT_TIMERS];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServerServiceStaticType Sd_GaaServerServiceStatic[SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_EvHandlerStaticType Sd_GaaEvHandlerStatic[SD_NO_OF_EV_HANDLERS];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ClientServiceStaticType Sd_GaaClientServiceStatic[SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#else
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ClientServiceStaticType Sd_GaaClientServiceStatic[SD_NO_OF_CLIENT_SERVICES_PB];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ConsumedEvGrpStaticType Sd_GaaConsumedEvGrpStatic[SD_NO_OF_CONSUMED_EV_GRP];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_SoConGroupStaticType Sd_GaaSoConGroupStatic[SD_NO_OF_SO_CON_GRPS];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_InstanceStaticType Sd_GaaInstanceStatic[SD_NO_OF_INSTANCES];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const SoAd_SoConIdType Sd_GaaSoConId[SD_NO_OF_SOCKET_CONNECTIONS];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
#if (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const SoAd_SoConIdType Sd_GaaMulticastSoConGrpIndex
    [SD_NO_OF_MULTICAST_SO_CON_GRP];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#else
#if (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const SoAd_SoConIdType Sd_GaaMulticastSoConGrpIndex[];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#endif

#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServiceGroupType Sd_GaaServicegroupStatic[SD_SERVICE_GROUP];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_CLIENT_CONFIGURED))
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicegroupClientArrayType Sd_GaaServicegroupClientStatic[SD_SERVICE_GROUP];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_CLIENT_CONFIGURED))
#define SD_START_SEC_CONST_16
#include "Sd_MemMap.h"
extern const uint16 Sd_GaaServicegroupClientArray[SD_SERVICE_GROUP][SD_CLIENT_REF_SERVICEGRP_CONFIGURED];
#define SD_STOP_SEC_CONST_16
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_CLIENT_CONFIGURED))
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ClientCounterType Sd_GaaClientRequestCounter[SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_SERVER_CONFIGURED))
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ServerAvailabilityCounterType Sd_GaaServerAvailabilityCounter[SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_SERVER_CONFIGURED))
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicegroupServerArrayType Sd_GaaServicegroupServerStatic[SD_SERVICE_GROUP];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_SERVER_CONFIGURED))
#define SD_START_SEC_CONST_16
#include "Sd_MemMap.h"
extern const uint16 Sd_GaaServicegroupServerArray[SD_SERVICE_GROUP][SD_SERVER_REF_SERVICEGRP_CONFIGURED];
#define SD_STOP_SEC_CONST_16
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GaaServiceGrpIdFlag[SD_SERVICE_GROUP];
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif
#if (SD_ROM_BLOCK == STD_ON)
#if ((STD_ON == SD_CLIENT_CONFIGURED))
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ProviderConsumerListType Sd_GaaClientServiceAllowedProviderStatic[SD_NO_OF_ALLOWED_CLIENT_PROVIDER];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#endif

#if (SD_ROM_BLOCK == STD_ON)
#if ((STD_ON == SD_SERVER_CONFIGURED))
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ProviderConsumerListType Sd_GaaServerServiceAllowedConsumerStatic[SD_NO_OF_PROVIDED_SERVER_CONSUMER];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#endif
/*
 *****************************************************************************
 *          Global constants Defined in cfg.c/pbcfg.c
 *****************************************************************************
 */
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/* Design Id: SD_SDD_0100 */
extern Sd_InstanceType Sd_GaaInstance[SD_NO_OF_INSTANCES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_InstancePartnerType Sd_GaaInstancePartner[SD_NO_OF_INSTANCES * SD_MAX_INSTANCE_PARTNER];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ServerServiceType Sd_GaaServerService[SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_EvHandlerType Sd_GaaEvHandler[SD_NO_OF_EV_HANDLERS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_EvHandlerSubGrpType Sd_GaaEvHandlerSubGrp[SD_NO_OF_EV_HANDLERS * SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0085, SD_SDD_0086,SD_SDD_0088*/
extern Sd_ClientServiceType Sd_GaaClientService[SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

/*#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h" */
/*Design ID : SD_SDD_0085, SD_SDD_0086,SD_SDD_0088*/
/*extern Sd_ClientServiceAllowedProviderType Sd_GaaClientServiceAllowedProvider[SD_NO_OF_ALLOWED_CLIENT_PROVIDER];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h" */

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ConsumedEvGrpType Sd_GaaConsumedEvGrp[SD_NO_OF_CONSUMED_EV_GRP];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_SoConType Sd_GaaSoCon[SD_NO_OF_SOCKET_CONNECTIONS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0107*/
extern Sd_SoConGroupType Sd_GaaSoConGroup[SD_NO_OF_SO_CON_GRPS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*
 ****************************************************************************
 * Dynamic variables
 ****************************************************************************
 */

#define SD_START_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"
extern uint8 Sd_GaaTxSduData[SD_MAX_PDU_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_EntryType Sd_GaaSendEntrys[SD_MAX_ENTRIES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_QueueType Sd_GaaQueue[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"
extern uint8 Sd_GaaQueueStatus[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_OptionsRefType Sd_GaaOptionsRef[SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_16
#include "Sd_MemMap.h"
extern uint16 Sd_GaaQueueSend[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_16
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
extern uint32 Sd_GaaIpAddr[SD_SIXTY_FOUR];
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern TcpIp_SockAddrType Sd_GddIpv4Wildcard;
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern TcpIp_SockAddrType Sd_GddIpv6Wildcard;
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
extern sint32 Sd_GslRandomState;
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
extern uint32 Sd_GulRandomValue;
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
extern boolean Sd_GblRandomCalled;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicesType Sd_GaaServerHandleMapArray[SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicesType Sd_GaaClientHandleMapArray[SD_NO_OF_CLIENT_SERVICES_PB];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#else
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicesType Sd_GaaClientHandleMapArray[SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ServicesType Sd_GaaConEvGrpHandleMapArray[SD_NO_OF_CONSUMED_EV_GRP];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_VAR_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_NvMRamBlockData_type Sd_Gaa_NvMRamBlockData[SD_ONE];
#define SD_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#if (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_NvMRomBlockData_type Sd_Gaa_NvMRomBlockData[SD_ONE];
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ProviderConsumerListType Sd_GaaClient_Server_List[SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#else
#if (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
extern Sd_ProviderConsumerListType Sd_GaaClient_Server_List[SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#endif
#endif

    



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerServiceDownEntered(
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateMachine(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    Sd_ServerServiceType * LpServerService,
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_EvHandlerMain(
    const Sd_ServerServiceType * LpServerService,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_EvHandlerRelease(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
Std_ReturnType Sd_AddClientToFanout(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    uint8 LucOptions_ACL,    
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpSendAddr);
#endif
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_RemoveClientFromFanout(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerServiceWaitEntered(
    Sd_ServerServiceType * LpServerService,
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateInitialWait(
    Sd_ServerServiceType * LpServerService,
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateRepetition(
    Sd_ServerServiceType * LpServerService,
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateMain(
    Sd_ServerServiceType * LpServerService,
    const Sd_ServerServiceStaticType * LpServerServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ResetToWildcardServer(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    Sd_TcpUdpEnumType enTcpUdp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_FindTcpIndex(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrTcp,
  uint8 LucOptionsCode);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_AddClientToFanoutTcp(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    uint8 LucOptionsCode,
    Std_ReturnType Sd_FoundTcpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AddClienttoFanoutUdpActions(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    SoAd_SoConIdType LddMatchSocketIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_FindUdpIndex(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrUdp,
  uint8 LucOptionsCode);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddClientToFanoutUdp(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    Std_ReturnType Sd_FoundUdpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddClientCheck(
    const Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    boolean LblTcp,
    const TcpIp_SockAddrType * LpIpAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientServiceWaitEntered(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientStateDown(
    const Sd_InstanceType * LpInstance,
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientStateInitialWait(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientStateRepetition(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientStateMain(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    boolean LblOfferTtlExpired);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ClientSetUpTcpConnection(
    const Sd_InstanceStaticType * LpInstanceStatic,
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ClientSetUpUdpConnection(
    const Sd_InstanceStaticType * LpInstanceStatic,
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrUdp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientSharedTimer(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const Sd_ClientTimerStaticType * LpClientTimer);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif

#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) &&     \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED) && \
     (STD_OFF == SD_SET_REM_ADDR_OF_CLIENT_RX_MULTICAST_SO_CON))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MulticastMatchSocket_Rem_Addr_Off(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_SoConGroupStaticType * LpSoConGrpStatic,
    SoAd_SoConIdType * LpSoConId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Sd_SoconIndexRertunType * 
Sd_Acl_UniqueAddress(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode,
    const Sd_InstanceType * LpInstance);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_AcL_IP_Client_policy_Check(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AcL_IP_Server_policy_Check(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckRemote(
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    uint16 Userviceid,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblAclCheckUDP,
    boolean LblAclCheckRemote,
    boolean LblClientorServer);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckServerIPV6(
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    uint16 Userviceid,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblAclCheckUDP,
    boolean LblAclCheckRemote,
    boolean LblClientorServer);

#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#endif
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclTcpClientRouting(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    SoAd_SoConIdType LddTcpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclUdpClientRouting(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    SoAd_SoConIdType LddUdpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AclTcpServerRouting(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    TcpIp_SockAddrType LstIpAddrTcp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AclUdpServerRouting(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    TcpIp_SockAddrType LstIpAddrUdp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Remote(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckRemote);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Tcp_Addr(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblClientorServer);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if ((SD_ROM_BLOCK == STD_ON) || (SD_RAM_BLOCK == STD_ON))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Udp_Addr(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckUDP,
    boolean LblClientorServer);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckRemote_Return(uint8 LucReturnCode,
                      boolean LblAclCheckTCP,
                      boolean LblAclCheckUDP,
                      boolean LblAclCheckRemote,
                      boolean LblClientorServer);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerRemoteCodeReturn(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucReturnCode2,
    uint8 LblServiceMatch);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddProviderToClientService(uint16 usServiceId,
                              uint16 usServiceInstanceId,
                              const Sd_ProviderConsumerType Request_Type,
                              const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddConsumerToServerService(uint16 usServiceId,
                              uint16 usServiceInstanceId,
                              const Sd_ProviderConsumerType Request_Type,
                              const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_IpAclWildCard(
    uint16 usServiceId,
    const Sd_ProviderConsumerType Request_type,
    uint8 LucIndex,
    Sd_AclUpdateReturnType * Return_Data);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RemoveProviderToClientService(uint16 usServiceId,
                                 uint16 usServiceInstanceId,
                                 Sd_ProviderConsumerType Request_Type,
                                 const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RemoveConsumerToServerService(uint16 usServiceId,
                                 uint16 usServiceInstanceId,
                                 Sd_ProviderConsumerType Request_Type,
                                 const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_IpAddAclWildCard(
    uint16 usServiceId,
    Sd_ProviderConsumerType Request_type,
    uint8 LucIndex,
    const TcpIp_SockAddrType * LpRemoteAddr,
    Sd_AclUpdateReturnType * Return_Data);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_IpAddressCnt(
    uint16 UsserviceId,
    const Sd_ProviderConsumerType Address_Type);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/******************************************************************************/

/******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxCheckHeader(
    const uint8 LpSduDataPtr[],
    const PduLengthType LusSduLength,
    uint16 * LpSessionId,
    boolean * LpRebootFlag);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetEntry(
    const uint8 LpPduDataPtr[],
    Sd_EntryType * LpEntry,
    uint8 LucNoOfOptions);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetAllOptions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const uint8 LpOptionsPtr[],
    uint32 LulLengthOfOptions,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetRemoteAddr(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_OptionsDataType * LpRxOptionsData,
    uint8 LucNoOfOptions,
    boolean LblUnicast,
    TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_FindRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
Std_ReturnType Sd_SubscribeRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    uint8 LucReturnCode);
#else
Std_ReturnType Sd_SubscribeRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr);

#endif
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_StopSubscribeRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_OfferRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeAckRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_StopOfferRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeNackRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const uint8 LpBaseEntriesSduPtr[],
    uint8 LucNoOfEntries,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_StopOfferRecdActions(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_FillTypeOfEntry(
    const uint8 LucEntryType,
    const uint32 LulTtlSec,
    Sd_EntryType * LpEntry);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_CheckIndexInRange(
    uint8 LucIndex1,
    uint8 LucNoOfOptions1,
    uint8 LucIndex2,
    uint8 LucNoOfOptions2,
    uint8 LucTotalNoOfOptions);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionConfig(
    uint16 LusOptionLength,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionIpV4(
    const Sd_InstanceStaticType * LpInstanceStatic,
    uint16 LusOptionLength,
    Sd_TypeOfOptionsType LenTypeOfOption,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_MatchOtherServSingle(
    const Sd_OptionsDataType * LpCurrOption,
    const uint8 LpOtherServStatic[],
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    boolean * LpOtherServMatch);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchOtherServ(
    const uint8 LpOtherServStatic[],
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    const Sd_EntryType * LpEntry,
    const Sd_OptionsDataType * LpOptionsData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchService(
    uint16 LusServiceIdRecd,
    uint16 LusServiceIdStatic,
    const uint8 * LpOtherServStatic,
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    const Sd_EntryType * LpEntry,
    const Sd_OptionsDataType * LpOptionsData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeRecdActions(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    uint8 LucCounter,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_OfferRecdCheckOptions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const uint8 LucOptionsCode);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdDown(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint32 LulTtlSec);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdInitialWait(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint32 LulTtlSec,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdRepetition(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    uint32 LulTtlSec,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdMain(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint32 LulTtlSec,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) && \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MulticastMatchSoConGroup(
    const Sd_InstanceStaticType * LpInstanceStatic,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    SoAd_SoConIdType * LpSoConGrpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) && \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MulticastMatchSocket(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceType * LpClientService,
    const Sd_SoConGroupStaticType * LpSoConGrpStatic,
    SoAd_SoConIdType * LpSoConId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SubscribeAckRecdActions(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceType * LpClientService,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SubscribeNackRecdActions(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const uint8 LpBaseEntriesSduPtr[],
    uint8 LucNoOfEntries,
    uint8 LucNoOfOptions,
    uint16 LusServiceId,
    uint16 LusInstanceId,
    uint8 LucMajorVersion,
    uint8 LucCounter,
    uint16 LusEventGroupId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (SD_IPV6_ENABLED == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionIpV6(
    const Sd_InstanceStaticType * LpInstanceStatic,
    uint16 LusOptionLength,
    Sd_TypeOfOptionsType LenTypeOfOption,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SubscibeEventGroupRetry(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif

/******************************************************************************/

/******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendOffer(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay,
    boolean blSendUnicast);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendStopOffer(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribeAck(
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribeNack(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendFind(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribe(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendStopSubscribe(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_Ipv4Lengthcheck(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_InstanceType * LpInstance,
    uint32 LulSubnetAddr,
    uint32 LulAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_Ipv6Lengthcheck(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_InstanceType * LpInstance,
    uint32 LulSubnetAddr,
    uint32 LulAddr,
    uint32 LaaAddrMask[],
    uint8 LucCount);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
boolean Sd_OfferNtExpire(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    boolean LblSoConOnline);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/******************************************************************************/

/******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_CombineQueue(void);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/******************************************************************************
 Helper functions
 *****************************************************************************
 */
/*******************************************************************************
** Function Name        : Sd_MemCpy                                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to copy memory bytes betn   **
**                      : two locations                                       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpSrcPtr - Pointer to source string                 **
**                      : LpDestPtr - Pointer to destination string           **
**                      : LusNumBytesToCopy - Number of bytes to copy         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0321                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_MemCpy(Sd_QueueType * LpDestPtr,
                                           const Sd_QueueType * LpSrcPtr)
{
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
      LpDestPtr value is not equal to SD_NULL_PTR.*/
    if (((Sd_QueueType *)SD_NULL_PTR != LpDestPtr) &&
        ((Sd_QueueType *)SD_NULL_PTR != LpSrcPtr))
    {
        LpDestPtr->blSendUnicast = LpSrcPtr->blSendUnicast;
        LpDestPtr->ddGenericIndex = LpSrcPtr->ddGenericIndex;
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
        LpDestPtr->ddSoConIdTcp = LpSrcPtr->ddSoConIdTcp;
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
        LpDestPtr->ddSoConIdUdp = LpSrcPtr->ddSoConIdUdp;
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
        LpDestPtr->stEntryData = LpSrcPtr->stEntryData;
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
        LpDestPtr->stSendAddr = LpSrcPtr->stSendAddr;
        LpDestPtr->ucSdInstanceIndex = LpSrcPtr->ucSdInstanceIndex;
        LpDestPtr->ulDelayCount = LpSrcPtr->ulDelayCount;
    }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : IpAddr                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function copy's the IP address from the source **
**                      : to the destination. It copy's IPv4 or IPv6 depending**
**                      : on the domain parameter of the source address       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpDest - Pointer to Destination Address             **
**                      : LpSource - Pointer to source address                **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0316                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_CopyIpAddr(
    TcpIp_SockAddrType * LpDest,
    const TcpIp_SockAddrType * LpSource)
{

    uint8 LusCount;
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
    if (TCPIP_AF_INET == LpSource->domain)
    {
        LpDest->domain = LpSource->domain;
        for (LusCount = 0; LusCount < SD_SIX; LusCount++)
        {
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
              made sure that they are initialized with proper Value " */
            LpDest->aaSockAddrInetData[LusCount] =
                LpSource->aaSockAddrInetData[LusCount];
        }
    }
/*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
    made sure that they are initialized with proper Value " */
#if (STD_ON == SD_IPV6_ENABLED)
    else if (TCPIP_AF_INET6 == LpSource->domain)
    {
        LpDest->domain = LpSource->domain;
        for (LusCount = 0; LusCount < SD_EIGHTTEEN; LusCount++)
        {
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
            LpDest->aaSockAddrInetData[LusCount] =
                LpSource->aaSockAddrInetData[LusCount];
        }
    }
#endif
    else
    {
    }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchIpWildcard(const TcpIp_SockAddrType * LpAddr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_HosttonetPtr                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts uint16 variable from         **
**                      : host to network order                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LulInput : Parameter to convert to host             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output bytes                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0325                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_HosttonetPtr(
    uint8 LpOutput[],
    const uint16 LusInput)
{
    /*[SWS_SD_00037]*/
    /*polyspace +3 RTE:IDP [Justified:Low] "LusInput point to only
    index 0 to 1. hence it will not exceed beyond its boundary. LusInput,
    has config for only 0 and 1 index. so its within bounds" */
    LpOutput[SD_ONE] = (uint8)(LusInput);
    LpOutput[SD_ZERO] = (uint8)((LusInput) >> SD_EIGHT);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Hosttonet3Ptr                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts uint24 variable from         **
**                      : host to network order                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LulInput : Parameter to convert to host             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output bytes                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0323                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_Hosttonet3Ptr(
    uint8 LpOutput[],
    const uint32 LulInput)
{

    LpOutput[SD_TWO] = (uint8)(LulInput);
    LpOutput[SD_ONE] = (uint8)((LulInput) >> SD_EIGHT);
    LpOutput[SD_ZERO] = (uint8)((LulInput) >> SD_SIXTEEN);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_HosttonetlPtr                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts uint32 variable from         **
**                      : host to network order                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LulInput : Parameter to convert to host             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output bytes                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0324                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_HosttonetlPtr(
    uint8 LpOutput[],
    const uint32 LulInput)
{

    LpOutput[SD_THREE] = (uint8)(LulInput);
    LpOutput[SD_TWO] = (uint8)((LulInput) >> SD_EIGHT);
    LpOutput[SD_ONE] = (uint8)((LulInput) >> SD_SIXTEEN);
    LpOutput[SD_ZERO] = (uint8)((LulInput) >> SD_TWENTY_FOUR);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_HtonlArr                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts uint8 variable from          **
**                      : host to network order                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInput : Pointer to convert to host                **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output bytes                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0342                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_HtonlArr(
    uint8 LpOutput[],
    const uint8 LpInput[])

{
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*polyspace +3 RTE:IDP [Justified:Low] "LpInput point to only
      index 0 to 3. hence it will not exceed beyond its boundary. LpInput,
      has config for only 0 to 3 index. so its within bounds" */
    LpOutput[SD_THREE] = LpInput[SD_ZERO];
    LpOutput[SD_TWO] = LpInput[SD_ONE];
    LpOutput[SD_ONE] = LpInput[SD_TWO];
    LpOutput[SD_ZERO] = LpInput[SD_THREE];
#else
    LpOutput[SD_THREE] = LpInput[SD_THREE];
    LpOutput[SD_TWO] = LpInput[SD_TWO];
    LpOutput[SD_ONE] = LpInput[SD_ONE];
    LpOutput[SD_ZERO] = LpInput[SD_ZERO];
#endif
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_NettohostPtr                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts network to host for 16 bits  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpOutput :                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : uint16 - the converted parameter                    **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0328                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline uint16 Sd_NettohostPtr(const uint8 LpInput[])
{
    /*[SWS_SD_00037]*/
    /*polyspace +4 RTE:IDP [Justified:Low] "LpInput point to only
    index 0 to 1 . hence it will not exceed beyond its boundary. LpInput,
    has config for only 0 and 1 index. so its within bounds" */
    return ((uint16)((uint16)LpInput[SD_ZERO] << SD_EIGHT) |
            (uint16)LpInput[SD_ONE]);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_HtonsArr                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts uint16 variable from         **
**                      : host to network order                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInput : Pointer to convert to host                **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output bytes                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0344                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_HtonsArr(
    uint8 LpOutput[],
    const uint8 LpInput[])
{
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*polyspace +3 RTE:IDP [Justified:Low] "LpInput point to only
    index 0 and 1. hence it will not exceed beyond its boundary. LpInput,
    has config for only 0 to 1 index. so its within bounds" */
    LpOutput[SD_ONE] = LpInput[SD_ZERO];
    LpOutput[SD_ZERO] = LpInput[SD_ONE];
#else
    LpOutput[SD_ONE] = LpInput[SD_ONE];
    LpOutput[SD_ZERO] = LpInput[SD_ZERO];
#endif
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Nettohost3Ptr                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts network to host for 24 bits  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpOutput :                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0326                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline uint32 Sd_Nettohost3Ptr(
    const uint8 LpInput[])
{
    /*[SWS_SD_00037]*/
    uint32 LulOutput;

    LulOutput = (uint32)((uint32)LpInput[SD_TWO] |
                         ((uint32)LpInput[SD_ONE] << SD_EIGHT) |
                         ((uint32)LpInput[SD_ZERO] << SD_SIXTEEN));

    return (LulOutput);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_NettohostlPtr                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts network to host for 32 bits  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpOutput :                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0327                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline uint32 Sd_NettohostlPtr(
    const uint8 LpInput[])
{
    /*[SWS_SD_00037]*/
    uint32 LulOutput;
    /*polyspace +6 RTE:IDP [Justified:Low] "LpInput point to only
    index 0 to 3. hence it will not exceed beyond its boundary. LpInput,
    has config for only 4 index. so its within bounds" */
    LulOutput = (uint32)((uint32)LpInput[SD_THREE] |
                         ((uint32)LpInput[SD_TWO] << SD_EIGHT) |
                         ((uint32)LpInput[SD_ONE] << SD_SIXTEEN) |
                         ((uint32)LpInput[SD_ZERO] << SD_TWENTY_FOUR));

    return (LulOutput);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Rand                                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is generates a random number between  **
**                      : the two numbers given as input                      **
**                      : Sd_GulRandomValue is recalculated every time in     **
**                        main function                                       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ulMinValue - Minumum value                          **
**                      : ulMaxValue - Maximum value                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : uint32 - The random number between the min and max  **
**                          values                                            **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GblRandomCalled            **
**                          Sd_GulRandomValue                                 **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0322                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline uint32 Sd_Rand(uint32 ulMinValue,
                                           uint32 ulMaxValue)
{
    uint32 LulReturn;
    /*[SWS_SD_00494b] [SWS_SD_00494c] [SWS_SD_00495a]*/
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
     ulMaxValue is equal to ulMinValue." */
    if (ulMinValue == ulMaxValue)
    {
        LulReturn = ulMinValue;
    }
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     ulMaxValue is greater.
   Module Test Case Reference SD_ETC_178, SWS ID SWS_SD_00494" */
    else if (ulMaxValue > ulMinValue)
    {
        LulReturn = ulMinValue + (Sd_GulRandomValue % (ulMaxValue - ulMinValue));

        Sd_GblRandomCalled = SD_TRUE;
    }

    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     ulMaxValue is greater.
  Module Test Case Reference SD_ETC_178, SWS ID SWS_SD_00494" */
    else
    {
        LulReturn = ulMinValue + (Sd_GulRandomValue % (ulMinValue - ulMaxValue));

        Sd_GblRandomCalled = SD_TRUE;
    }

    return (LulReturn);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetRandomVal                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Runs the linear congruential generator algorithm to **
**                        produce a random number                             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LslResult                                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GslRandomState             **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0317                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline uint32 Sd_GetRandomVal(void)
{
    uint32 LulTempResult;
    /*polyspace +3 RTE:OVFL [Justified:Low] "The purpose of Sd_GetRandomVal
    to generate  random value so it will overflow " */
    Sd_GslRandomState = (sint32)(Sd_GslRandomState * SD_LCG_CONSTANT_1);
    Sd_GslRandomState = Sd_GslRandomState + SD_LCG_CONSTANT_2;
    LulTempResult = (uint32)((uint32)Sd_GslRandomState >> (uint32)SD_SIXTEEN) &
                    (uint32)SD_LCG_CONSTANT_3;
    /*polyspace +3 RTE:OVFL [Justified:Low] "The purpose of Sd_GetRandomVal to
    generate  random value so it will overflow " */
    Sd_GslRandomState = (sint32)(Sd_GslRandomState * SD_LCG_CONSTANT_1);
    Sd_GslRandomState = Sd_GslRandomState + SD_LCG_CONSTANT_2;
    LulTempResult = LulTempResult << (uint32)SD_TEN;
    LulTempResult = LulTempResult | ((uint32)((uint32)Sd_GslRandomState >>
                                              (uint32)SD_SIXTEEN) &
                                     (uint32)SD_LCG_CONSTANT_4);
    /*polyspace +2 RTE:OVFL [Justified:Low] "The purpose of Sd_GetRandomVal to
    generate  random value so it will overflow " */
    Sd_GslRandomState = (sint32)(Sd_GslRandomState * SD_LCG_CONSTANT_1);
    Sd_GslRandomState = Sd_GslRandomState + SD_LCG_CONSTANT_2;
    LulTempResult = LulTempResult << (uint32)SD_TEN;
    LulTempResult = LulTempResult | ((uint32)((uint32)Sd_GslRandomState >>
                                              (uint32)SD_SIXTEEN) &
                                     (uint32)SD_LCG_CONSTANT_4);

    return LulTempResult;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Ipv4NetmaskToIpAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts the netmask from the CIDR    **
**                        notation to the IP address                          **
**                        Care is taken to convert properly for IPv4 and IPv6 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LucNetmask : Netmask in CIDR notation               **
**                      : LblDomainIpv4 : indicates the domain whether IPv4   **
**                      :    or IPv6                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpIpAddr - The Netmask in Ip Address format         **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0343                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_Ipv4NetmaskToIpAddr(
    uint8 LucSubnetMask,
    TcpIp_SockAddrInetType * LpIp4Addr)
{

    uint32 LulXorValue;

    LpIp4Addr->domain = TCPIP_AF_INET;
    if (LucSubnetMask == SD_ZERO)
    {
        LpIp4Addr->addr[SD_ZERO] = (uint32)SD_ZERO;
    }
    else if (LucSubnetMask < SD_THIRTY_TWO)
    {
        LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_THIRTY_TWO - LucSubnetMask))) - SD_ONE;
        LpIp4Addr->addr[SD_ZERO] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        /*For little endian subnet mask to check ip address in same subnet */
        LpIp4Addr->addr[SD_ZERO] = ~LpIp4Addr->addr[SD_ZERO];
#endif
    }
    else
    {
        LpIp4Addr->addr[SD_ZERO] = (uint32)SD_IP_ADDR_MAX;
    }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Ipv4LoadData                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function loads the Ipv4 Domain, port and       **
                          Address from Input pointer to output pointer.       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInput : Pointer to input data                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output data                   **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0340                                          **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static inline void Sd_Ipv4LoadData(
    const Sd_OptionsDataType * LpInData,
    TcpIp_SockAddrType * LpOutData)
{
    uint16 LusPort;
    uint32 LulAddr;

    LpOutData->domain = TCPIP_AF_INET;

    LusPort = (LpInData->unOptionsData).stOptionsIpv4.usPortNo;
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    LpOutData->aaSockAddrInetData[SD_ZERO] = (uint8)LusPort;
    LpOutData->aaSockAddrInetData[SD_ONE] = (uint8)((LusPort) >> SD_EIGHT);

    LulAddr = (LpInData->unOptionsData).stOptionsIpv4.ulIpAddr;

    LpOutData->aaSockAddrInetData[SD_TWO] = (uint8)(LulAddr);

    LpOutData->aaSockAddrInetData[SD_THREE] =
        (uint8)((LulAddr) >> SD_EIGHT);
    LpOutData->aaSockAddrInetData[SD_FOUR] =
        (uint8)((LulAddr) >> SD_SIXTEEN);
    LpOutData->aaSockAddrInetData[SD_FIVE] =
        (uint8)((LulAddr) >> SD_TWENTY_FOUR);
#else
    LpOutData->aaSockAddrInetData[SD_ONE] = (uint8)LusPort;
    LpOutData->aaSockAddrInetData[SD_ZERO] = (uint8)((LusPort) >> SD_EIGHT);

    LulAddr = (LpInData->unOptionsData).stOptionsIpv4.ulIpAddr;
    LpOutData->aaSockAddrInetData[SD_FIVE] = (uint8)(LulAddr);
    LpOutData->aaSockAddrInetData[SD_FOUR] =
        (uint8)((LulAddr) >> SD_EIGHT);
    LpOutData->aaSockAddrInetData[SD_THREE] =
        (uint8)((LulAddr) >> SD_SIXTEEN);
    LpOutData->aaSockAddrInetData[SD_TWO] =
        (uint8)((LulAddr) >> SD_TWENTY_FOUR);
#endif
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MatchString(const uint8 * LpSource,
               const uint8 * LpMatch, uint16 * LpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetIpAddrFromOptions(
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    TcpIp_SockAddrType * LpIpAddrTcp,
    TcpIp_SockAddrType * LpIpAddrUdp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetIpAddrFromMulticastOption(
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    TcpIp_SockAddrType * LpIpAddrUdp);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchIpAddr(const TcpIp_SockAddrType * LpAddr1,
               const TcpIp_SockAddrType * LpAddr2);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Ipv6NetmaskToIpAddr(
    uint8 LucSubnetMask,
    boolean LblDomainIpv4,
    TcpIp_SockAddrInet6Type * LpIp6Addr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_CheckSubnet(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpOptionTcpAddr,
    const TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Ipv6LoadData(
    const Sd_OptionsDataType * LpInData,
    TcpIp_SockAddrType * LpOutData);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetEvHandlerSubGrpIndex(
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucCounterIn,
    Sd_ServicesType * LpEvhandlerSubGrpIndex);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetSessionIdAndFlag(
    Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    boolean LblUnicast,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint16 * LpSessionId,
    boolean * LpRebootFlag);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_DetectReboot(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast,
    uint16 LusSessionIdRecd,
    boolean LblRebootFlagRecd);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_OFF == SD_EV_HANDLER_CONFIGURED) && (STD_OFF == SD_CLIENT_CONFIGURED)
void Sd_RebootActions(
    const Sd_InstanceStaticType * LpInstanceStatic);
#else
void Sd_RebootActions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr);
#endif
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_RxIndicationProcessEntry(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntry,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const uint8 LpSduDataPtr[],
    uint8 LucNoOfOptions,
    uint8 LucNoOfEntries,
    boolean LblUnicast);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAssignmentServer(
    const Sd_InstanceStaticType * LpInstanceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAssignmentClient(
    const Sd_InstanceStaticType * LpInstanceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/******************************************************************************/

/******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientServiceDownEntered(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientStateMachine(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
void Sd_ConsumedEvGrpMain(
    Sd_ClientServiceType * LpClientService,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic);
#else
void Sd_ConsumedEvGrpMain(
    const Sd_ClientServiceType * LpClientService,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic);
#endif
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_ClientSetUpTcpUdpConnection(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientFanIn(
    const Sd_ClientServiceType * LpClientService,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    uint8 LucReturnCode_ACL);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientInactive(
    Sd_ClientServiceType * LpClientService);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ConsumedEvGrpRelease(
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/******************************************************************************/

/******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_InitServer(void);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_InitClient(void);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
