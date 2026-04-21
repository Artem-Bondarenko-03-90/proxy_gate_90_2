/*
 * iedModel.c
 *
 * automatically generated from F:\RTSoft\Code\proxy_gate_90_2\MultiLD.cid
 */
#include "iedModel.h"

static void initializeValues();

extern DataSet iedModelds_Measurements_LLN0_Values;
extern DataSet iedModelds_Protection_LLN0_Events;
extern DataSet iedModelds_Control_LLN0_Status;


extern DataSetEntry iedModelds_Measurements_LLN0_Values_fcda0;

DataSetEntry iedModelds_Measurements_LLN0_Values_fcda0 = {
  "Measurements",
  false,
  "GGIO1$MX$AnIn1$mag$f", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_Measurements_LLN0_Values = {
  "Measurements",
  "LLN0$Values",
  1,
  &iedModelds_Measurements_LLN0_Values_fcda0,
  &iedModelds_Protection_LLN0_Events
};

extern DataSetEntry iedModelds_Protection_LLN0_Events_fcda0;

DataSetEntry iedModelds_Protection_LLN0_Events_fcda0 = {
  "Protection",
  false,
  "GGIO1$ST$SPCSO1$stVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_Protection_LLN0_Events = {
  "Protection",
  "LLN0$Events",
  1,
  &iedModelds_Protection_LLN0_Events_fcda0,
  &iedModelds_Control_LLN0_Status
};

extern DataSetEntry iedModelds_Control_LLN0_Status_fcda0;

DataSetEntry iedModelds_Control_LLN0_Status_fcda0 = {
  "Control",
  false,
  "GGIO1$ST$Ind1$stVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet iedModelds_Control_LLN0_Status = {
  "Control",
  "LLN0$Status",
  1,
  &iedModelds_Control_LLN0_Status_fcda0,
  NULL
};

LogicalDevice iedModel_Measurements = {
    LogicalDeviceModelType,
    "Measurements",
    (ModelNode*) &iedModel,
    (ModelNode*) &iedModel_Protection,
    (ModelNode*) &iedModel_Measurements_LLN0,
    NULL
};

LogicalNode iedModel_Measurements_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_Measurements,
    (ModelNode*) &iedModel_Measurements_LPHD1,
    (ModelNode*) &iedModel_Measurements_LLN0_Mod,
};

DataObject iedModel_Measurements_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Measurements_LLN0,
    (ModelNode*) &iedModel_Measurements_LLN0_Beh,
    (ModelNode*) &iedModel_Measurements_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_LLN0_Mod,
    (ModelNode*) &iedModel_Measurements_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_LLN0_Mod,
    (ModelNode*) &iedModel_Measurements_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_LLN0_Mod,
    (ModelNode*) &iedModel_Measurements_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Measurements_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Measurements_LLN0,
    (ModelNode*) &iedModel_Measurements_LLN0_Health,
    (ModelNode*) &iedModel_Measurements_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_LLN0_Beh,
    (ModelNode*) &iedModel_Measurements_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_LLN0_Beh,
    (ModelNode*) &iedModel_Measurements_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Measurements_LLN0,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    (ModelNode*) &iedModel_Measurements_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_LLN0_Health,
    (ModelNode*) &iedModel_Measurements_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_LLN0_Health,
    (ModelNode*) &iedModel_Measurements_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Measurements_LLN0,
    NULL,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Measurements_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_Measurements_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_Measurements_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_Measurements,
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyNam,
};

DataObject iedModel_Measurements_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_Measurements_LPHD1,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_Measurements_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_Measurements_LPHD1,
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_Measurements_LPHD1,
    NULL,
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy,
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy,
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_Measurements_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_Measurements,
    NULL,
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod,
};

DataObject iedModel_Measurements_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh,
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod_q,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod,
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod,
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Measurements_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_Health,
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh,
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh,
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Measurements_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_GGIO1_Health,
    (ModelNode*) &iedModel_Measurements_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_Health,
    (ModelNode*) &iedModel_Measurements_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Measurements_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Measurements_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &iedModel_Measurements_GGIO1,
    NULL,
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute iedModel_Measurements_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1,
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1,
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Measurements_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Measurements_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};


LogicalDevice iedModel_Protection = {
    LogicalDeviceModelType,
    "Protection",
    (ModelNode*) &iedModel,
    (ModelNode*) &iedModel_Control,
    (ModelNode*) &iedModel_Protection_LLN0,
    NULL
};

LogicalNode iedModel_Protection_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_Protection,
    (ModelNode*) &iedModel_Protection_LPHD1,
    (ModelNode*) &iedModel_Protection_LLN0_Mod,
};

DataObject iedModel_Protection_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Protection_LLN0,
    (ModelNode*) &iedModel_Protection_LLN0_Beh,
    (ModelNode*) &iedModel_Protection_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_LLN0_Mod,
    (ModelNode*) &iedModel_Protection_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_LLN0_Mod,
    (ModelNode*) &iedModel_Protection_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_LLN0_Mod,
    (ModelNode*) &iedModel_Protection_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Protection_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Protection_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Protection_LLN0,
    (ModelNode*) &iedModel_Protection_LLN0_Health,
    (ModelNode*) &iedModel_Protection_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_LLN0_Beh,
    (ModelNode*) &iedModel_Protection_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_LLN0_Beh,
    (ModelNode*) &iedModel_Protection_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Protection_LLN0,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    (ModelNode*) &iedModel_Protection_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_LLN0_Health,
    (ModelNode*) &iedModel_Protection_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_LLN0_Health,
    (ModelNode*) &iedModel_Protection_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Protection_LLN0,
    NULL,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Protection_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_Protection_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_Protection_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_Protection,
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyNam,
};

DataObject iedModel_Protection_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_Protection_LPHD1,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_Protection_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Protection_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Protection_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_Protection_LPHD1,
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_Protection_LPHD1,
    NULL,
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy,
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy,
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_Protection_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_Protection,
    NULL,
    (ModelNode*) &iedModel_Protection_GGIO1_Mod,
};

DataObject iedModel_Protection_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_Beh,
    (ModelNode*) &iedModel_Protection_GGIO1_Mod_q,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_Mod,
    (ModelNode*) &iedModel_Protection_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_Mod,
    (ModelNode*) &iedModel_Protection_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Protection_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_Health,
    (ModelNode*) &iedModel_Protection_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_GGIO1_Beh,
    (ModelNode*) &iedModel_Protection_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_Beh,
    (ModelNode*) &iedModel_Protection_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Protection_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_GGIO1_Health,
    (ModelNode*) &iedModel_Protection_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_Health,
    (ModelNode*) &iedModel_Protection_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Protection_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_Protection_GGIO1,
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Protection_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &iedModel_Protection_GGIO1,
    NULL,
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute iedModel_Protection_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1,
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1,
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Protection_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Protection_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};


LogicalDevice iedModel_Control = {
    LogicalDeviceModelType,
    "Control",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_Control_LLN0,
    NULL
};

LogicalNode iedModel_Control_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_Control,
    (ModelNode*) &iedModel_Control_LPHD1,
    (ModelNode*) &iedModel_Control_LLN0_Mod,
};

DataObject iedModel_Control_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Control_LLN0,
    (ModelNode*) &iedModel_Control_LLN0_Beh,
    (ModelNode*) &iedModel_Control_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_LLN0_Mod,
    (ModelNode*) &iedModel_Control_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_LLN0_Mod,
    (ModelNode*) &iedModel_Control_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_LLN0_Mod,
    (ModelNode*) &iedModel_Control_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Control_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Control_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Control_LLN0,
    (ModelNode*) &iedModel_Control_LLN0_Health,
    (ModelNode*) &iedModel_Control_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_LLN0_Beh,
    (ModelNode*) &iedModel_Control_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_LLN0_Beh,
    (ModelNode*) &iedModel_Control_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Control_LLN0,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    (ModelNode*) &iedModel_Control_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_LLN0_Health,
    (ModelNode*) &iedModel_Control_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_LLN0_Health,
    (ModelNode*) &iedModel_Control_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Control_LLN0,
    NULL,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Control_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    (ModelNode*) &iedModel_Control_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_Control_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_Control_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_Control,
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_LPHD1_PhyNam,
};

DataObject iedModel_Control_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_Control_LPHD1,
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Control_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute iedModel_Control_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Control_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Control_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_Control_LPHD1,
    (ModelNode*) &iedModel_Control_LPHD1_Proxy,
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_Control_LPHD1,
    NULL,
    (ModelNode*) &iedModel_Control_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_LPHD1_Proxy,
    (ModelNode*) &iedModel_Control_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_LPHD1_Proxy,
    (ModelNode*) &iedModel_Control_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_Control_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_Control,
    NULL,
    (ModelNode*) &iedModel_Control_GGIO1_Mod,
};

DataObject iedModel_Control_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_Beh,
    (ModelNode*) &iedModel_Control_GGIO1_Mod_q,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_Mod,
    (ModelNode*) &iedModel_Control_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_Mod,
    (ModelNode*) &iedModel_Control_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Control_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_Health,
    (ModelNode*) &iedModel_Control_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_GGIO1_Beh,
    (ModelNode*) &iedModel_Control_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_Beh,
    (ModelNode*) &iedModel_Control_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Control_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_GGIO1_Health,
    (ModelNode*) &iedModel_Control_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_Health,
    (ModelNode*) &iedModel_Control_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt,
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_Control_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1,
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_Control_GGIO1,
    (ModelNode*) &iedModel_Control_GGIO1_Ind1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_Control_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &iedModel_Control_GGIO1,
    NULL,
    (ModelNode*) &iedModel_Control_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute iedModel_Control_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_Control_GGIO1_Ind1,
    (ModelNode*) &iedModel_Control_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_Control_GGIO1_Ind1,
    (ModelNode*) &iedModel_Control_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_Control_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_Control_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};









IedModel iedModel = {
    "MultiLD",
    &iedModel_Measurements,
    &iedModelds_Measurements_LLN0_Values,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{
}
