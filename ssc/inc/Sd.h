/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd.h                                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This File contains types referred by Sd                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
**  Design ID : SD_SDD_0444                                                   **
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

#ifndef SD_H
#define SD_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Design ID : SD_SDD_0075,SD_SDD_0079,SD_SDD_0444*/
#include "Sd_Cfg.h"
#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#include "Sd_PBcfg.h"
#endif

/* Design ID: SD_SDD_0001 */
/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/*[SWS_SD_00119b] [SWS_SD_00496b] [SWS_SD_00409b] [SWS_SD_00560b]
[SWS_SD_00412b] [SWS_SD_00129b] [SWS_SD_00130b]*/
/*Design ID : SD_SDD_0029*/
#define SD_INIT_SID (0x01U)
/*Design ID : SD_SDD_0029*/
#define SD_GET_VERSION_INFO_SID (0x02U)
/*Design ID : SD_SDD_0029*/
#define SD_MAIN_FUNCTION_SID (0x06U)
/*Design ID : SD_SDD_0029*/
#define SD_SERVER_SERVICE_SET_STATE_SID (0x07U)
/*Design ID : SD_SDD_0029*/
#define SD_CLIENT_SERVICE_SET_STATE_SID (0x08U)
/*Design ID : SD_SDD_0029*/
#define SD_CONSUMED_EVENT_GROUP_SET_STATE_SID (0x09U)
/*Design ID : SD_SDD_0029*/
#define SD_LOCAL_IP_ADDR_ASSIGNMENT_CHANGE_SID (0x05U)
/*Design ID : SD_SDD_0029*/
#define SD_RX_INDICATION_SID (0x42U)

/*Design ID : SD_SDD_0057*/
/*[SWS_SD_00107b][SWS_SD_00107c][SWS_SD_00107d][SWS_SD_00107e][SWS_SD_00107f] */
#define SD_E_UNINIT (0x01U)
#define SD_E_PARAM_POINTER (0x02U)
#define SD_E_INV_MODE (0x03U)
#define SD_E_INV_ID (0x04U)
#define SD_E_INIT_FAILED (0x05U)

/*Design ID : SD_SDD_0025*/
#define SD_INSTANCE_ID (0x00U)

#define SD_SERVICE_GROUP_START_SID (0x44U)

#define SD_SERVICE_GROUP_STOP_SID (0x45U)

#define SD_E_COUNT_OF_RETRY_SUBSCRIPTION_EXCEEDED (0x06)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Structure definitions                                 **
*******************************************************************************/
/*Design ID : SD_SDD_0446 */

/*Design ID : SD_SDD_0446 */
#if (STD_OFF == SD_PRE_COMPILE_SINGLE)

typedef struct STag_Sd_ConfigType
{
  uint32 ulStartOfDbToc;
#if (SD_NO_OF_CLIENT_TIMERS != SD_VAL_ZERO)
  const Sd_ClientTimerStaticType *pSd_GSaaClientTimerStatic;

  uint8 ucSdClientTimerCount;
#endif
#if (SD_NO_OF_INSTANCES != SD_VAL_ZERO)
  const Sd_InstanceStaticType *pInstanceStatic;

  uint8 ucSdInstanceIndexValue;
#endif
#if (SD_NO_OF_CONSUMED_EV_GRP != SD_VAL_ZERO)
  const Sd_ConsumedEvGrpStaticType *pSd_GaaConsumedEvGrpStatic;
  const Sd_ServicesType *pSd_GaaConEvGrpHandleMapArray;
#endif
#if (SD_NO_OF_SERVER_SERVICES != SD_VAL_ZERO)
  const Sd_ServerServiceStaticType *pSd_GaaServerServiceStatic;
  const Sd_ServicesType *pSd_GaaServerHandleMapArray;
#endif
#if (SD_NO_OF_SERVER_TIMERS != SD_VAL_ZERO)
  /* Reference to the Server Timer */
  const Sd_ServerTimerStaticType * pServerTimer;

  uint8 ucSdServerTimerIndexValue;
#endif
#if (SD_NO_OF_CLIENT_SERVICES != SD_VAL_ZERO)
  const Sd_ClientServiceStaticType *pSd_GaaClientServiceStatic;

  const Sd_ServicesType *pSd_GaaClientHandleMapArray;
#endif
#if (SD_NO_OF_EV_HANDLERS != SD_VAL_ZERO)
  const Sd_EvHandlerStaticType *pSd_GaaEvHandlerStatic;
#endif
#if (SD_NO_OF_PROVIDED_SERVER_CONSUMER != SD_VAL_ZERO)
  const Sd_ProviderConsumerListType *pSdAllowedConsumerStatic;
  uint8 ucSdAllowedConsumerStaticCount;
#endif
#if (SD_NO_OF_ALLOWED_CLIENT_PROVIDER != SD_VAL_ZERO)
  const Sd_ProviderConsumerListType *pSdAllowedProviderStatic;
  uint8 ucSdAllowedProviderStaticCount;

#endif
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#if (SD_CLIENT_REF_SERVICEGRP_CONFIGURED != SD_VAL_ZERO)
  const uint16 *pServgrpCliArray;
#endif
#if (SD_SERVER_REF_SERVICEGRP_CONFIGURED != SD_VAL_ZERO)
  const uint16 *pServgrpSerArray;
#endif
#if (SD_SERVICE_GROUP != SD_VAL_ZERO)
  const Sd_ServiceGroupType *pServgrpStatic;
#if (SD_CLIENT_REF_SERVICEGRP_CONFIGURED != SD_VAL_ZERO)
  const Sd_ServicegroupClientArrayType *pServgrpCliStatic;
#endif
#if (SD_SERVER_REF_SERVICEGRP_CONFIGURED != SD_VAL_ZERO)
  const Sd_ServicegroupServerArrayType *pServgrpSerStatic;
#endif
#endif
#endif
#if (SD_NO_OF_INSTANCES != SD_VAL_ZERO)
  const Sd_ServicesType *pRxPduMapArray;
#endif
} Sd_ConfigType;

#endif

/*Design ID : SD_SDD_0069,*/
/*SWS_SD_00005 SD_SRS_204*/

typedef enum ETag_Sd_AclUpdateType
{
  SD_ACL_ADD_PROVIDER,
  SD_ACL_ADD_CONSUMER,
  SD_ACL_REMOVE_PROVIDER,
  SD_ACL_REMOVE_CONSUMER
} Sd_AclUpdateType;

typedef enum ETag_Sd_ServerServiceSetStateType
{
  SD_SERVER_SERVICE_DOWN,
  SD_SERVER_SERVICE_AVAILABLE

} Sd_ServerServiceSetStateType;

/*Design ID : SD_SDD_0065,SD_SDD_0085*/
/*SWS_SD_00005 SD_SRS_205*/

typedef enum ETag_Sd_ClientServiceSetStateType
{
  SD_CLIENT_SERVICE_RELEASED,
  SD_CLIENT_SERVICE_REQUESTED
} Sd_ClientServiceSetStateType;

/*Design ID : SD_SDD_0067*/ /*SD_SRS_206 SWS_SD_00005*/
typedef enum ETag_Sd_ConsumedEventGroupSetStateType
{
  SD_CONSUMED_EVENTGROUP_RELEASED,
  SD_CONSUMED_EVENTGROUP_REQUESTED
} Sd_ConsumedEventGroupSetStateType;

/*Design ID : SD_SDD_0064*/
typedef enum ETag_Sd_ClientServiceCurrentStateType
{
  SD_CLIENT_SERVICE_DOWN,
  SD_CLIENT_SERVICE_AVAILABLE
} Sd_ClientServiceCurrentStateType;

/*Design ID : SD_SDD_0066*/
typedef enum ETag_Sd_ConsumedEventGroupCurrentStateType
{
  SD_CONSUMED_EVENTGROUP_DOWN,
  SD_CONSUMED_EVENTGROUP_AVAILABLE
} Sd_ConsumedEventGroupCurrentStateType;

/*Design ID : SD_SDD_0068*/
typedef enum ETag_Sd_EventHandlerCurrentStateType
{
  SD_EVENT_HANDLER_RELEASED,
  SD_EVENT_HANDLER_REQUESTED
} Sd_EventHandlerCurrentStateType;

/*Design ID : SD_SDD_0456*/
typedef uint16 Sd_ServiceGroupIdType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_ServerServiceSetState(
    uint16 SdServerServiceHandleId,
    Sd_ServerServiceSetStateType ServerServiceState);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_ClientServiceSetState(
    uint16 ClientServiceHandleId,
    Sd_ClientServiceSetStateType ClientServiceState);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_ConsumedEventGroupSetState(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupSetStateType ConsumedEventGroupState);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0077*/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetVersionInfo(
    Std_VersionInfoType * versioninfo);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Init(
    const Sd_ConfigType * ConfigPtr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0072,SD_SDD_0073,SD_SDD_0445*/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_RxIndication(PduIdType RxPduId,
                const PduInfoType * PduInfoPtr);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0081*/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAddrAssignmentChg(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SoConModeChg(SoAd_SoConIdType SoConId,
                SoAd_SoConModeType Mode);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServiceGroupStart(Sd_ServiceGroupIdType ServiceGroupId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServiceGroupStop(Sd_ServiceGroupIdType ServiceGroupId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (SD_SERVER_CONFIGURED == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RequestRoutingGroupEnable(uint32 PduHeaderID,
                             SoAd_SoConIdType SoConId);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclCheckEnable(boolean EnableAcl);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#define SD_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ConfigType Sd_GaaConfig[SD_NUM_OF_CFG_SETS];
#define SD_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
extern const Sd_ConfigType * Sd_GpConfigPtr;
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclUpdate(
    uint16 SdServiceId,
    uint16 ServiceInstanceId,
    const TcpIp_SockAddrType * RemoteAddrPtr,
    Sd_AclUpdateType RequestType);
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/* SD_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
