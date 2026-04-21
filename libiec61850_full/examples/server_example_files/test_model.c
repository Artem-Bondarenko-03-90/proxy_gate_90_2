/*
 * test_model.c
 *
 * automatically generated from simpleIO_direct_control.cid
 */
#include "test_model.h"

static void initializeValues();

extern DataSet testModelds_GenericIO_LLN0_Events;
extern DataSet testModelds_GenericIO_LLN0_Events2;
extern DataSet testModelds_GenericIO_LLN0_Measurements;


extern DataSetEntry testModelds_GenericIO_LLN0_Events_fcda0;
extern DataSetEntry testModelds_GenericIO_LLN0_Events_fcda1;
extern DataSetEntry testModelds_GenericIO_LLN0_Events_fcda2;
extern DataSetEntry testModelds_GenericIO_LLN0_Events_fcda3;

DataSetEntry testModelds_GenericIO_LLN0_Events_fcda0 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO1$stVal", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events_fcda1
};

DataSetEntry testModelds_GenericIO_LLN0_Events_fcda1 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO2$stVal", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events_fcda2
};

DataSetEntry testModelds_GenericIO_LLN0_Events_fcda2 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO3$stVal", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events_fcda3
};

DataSetEntry testModelds_GenericIO_LLN0_Events_fcda3 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO4$stVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet testModelds_GenericIO_LLN0_Events = {
  "GenericIO",
  "LLN0$Events",
  4,
  &testModelds_GenericIO_LLN0_Events_fcda0,
  &testModelds_GenericIO_LLN0_Events2
};

extern DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda0;
extern DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda1;
extern DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda2;
extern DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda3;

DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda0 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO1", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events2_fcda1
};

DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda1 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO2", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events2_fcda2
};

DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda2 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO3", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Events2_fcda3
};

DataSetEntry testModelds_GenericIO_LLN0_Events2_fcda3 = {
  "GenericIO",
  false,
  "GGIO1$ST$SPCSO4", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet testModelds_GenericIO_LLN0_Events2 = {
  "GenericIO",
  "LLN0$Events2",
  4,
  &testModelds_GenericIO_LLN0_Events2_fcda0,
  &testModelds_GenericIO_LLN0_Measurements
};

extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda0;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda1;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda2;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda3;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda4;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda5;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda6;
extern DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda7;

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda0 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn1$mag$f", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda1
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda1 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn1$q", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda2
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda2 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn2$mag$f", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda3
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda3 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn2$q", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda4
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda4 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn3$mag$f", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda5
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda5 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn3$q", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda6
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda6 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn4$mag$f", 
  -1,
  NULL,
  NULL,
  &testModelds_GenericIO_LLN0_Measurements_fcda7
};

DataSetEntry testModelds_GenericIO_LLN0_Measurements_fcda7 = {
  "GenericIO",
  false,
  "GGIO1$MX$AnIn4$q", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet testModelds_GenericIO_LLN0_Measurements = {
  "GenericIO",
  "LLN0$Measurements",
  8,
  &testModelds_GenericIO_LLN0_Measurements_fcda0,
  NULL
};

LogicalDevice testModel_GenericIO = {
    LogicalDeviceModelType,
    "GenericIO",
    (ModelNode*) &testModel,
    NULL,
    (ModelNode*) &testModel_GenericIO_LLN0,
    NULL
};

LogicalNode testModel_GenericIO_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &testModel_GenericIO,
    (ModelNode*) &testModel_GenericIO_LPHD1,
    (ModelNode*) &testModel_GenericIO_LLN0_Mod,
};

DataObject testModel_GenericIO_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &testModel_GenericIO_LLN0,
    (ModelNode*) &testModel_GenericIO_LLN0_Beh,
    (ModelNode*) &testModel_GenericIO_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_LLN0_Mod,
    (ModelNode*) &testModel_GenericIO_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_LLN0_Mod,
    (ModelNode*) &testModel_GenericIO_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_LLN0_Mod,
    (ModelNode*) &testModel_GenericIO_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &testModel_GenericIO_LLN0,
    (ModelNode*) &testModel_GenericIO_LLN0_Health,
    (ModelNode*) &testModel_GenericIO_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_LLN0_Beh,
    (ModelNode*) &testModel_GenericIO_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_LLN0_Beh,
    (ModelNode*) &testModel_GenericIO_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &testModel_GenericIO_LLN0,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &testModel_GenericIO_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_LLN0_Health,
    (ModelNode*) &testModel_GenericIO_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_LLN0_Health,
    (ModelNode*) &testModel_GenericIO_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &testModel_GenericIO_LLN0,
    NULL,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute testModel_GenericIO_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &testModel_GenericIO_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode testModel_GenericIO_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &testModel_GenericIO,
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyNam,
};

DataObject testModel_GenericIO_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &testModel_GenericIO_LPHD1,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute testModel_GenericIO_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &testModel_GenericIO_LPHD1,
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &testModel_GenericIO_LPHD1,
    NULL,
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode testModel_GenericIO_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &testModel_GenericIO,
    NULL,
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod,
};

DataObject testModel_GenericIO_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod_q,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Health,
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &testModel_GenericIO_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Health,
    (ModelNode*) &testModel_GenericIO_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Health,
    (ModelNode*) &testModel_GenericIO_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &testModel_GenericIO_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1_mag,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1_q,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_AnIn2 = {
    DataObjectModelType,
    "AnIn2",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2_mag,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_AnIn2_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2_q,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn2_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_AnIn3 = {
    DataObjectModelType,
    "AnIn3",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3_mag,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_AnIn3_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3_q,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn3_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_AnIn4 = {
    DataObjectModelType,
    "AnIn4",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4_mag,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_AnIn4_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4_q,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn4_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_AnIn4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_AnIn4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_SPCSO2 = {
    DataObjectModelType,
    "SPCSO2",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_ctlModel,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_SPCSO3 = {
    DataObjectModelType,
    "SPCSO3",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_ctlModel,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_SPCSO4 = {
    DataObjectModelType,
    "SPCSO4",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_ctlModel,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_SPCSO4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_SPCSO4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Ind2 = {
    DataObjectModelType,
    "Ind2",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Ind2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Ind3 = {
    DataObjectModelType,
    "Ind3",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Ind3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject testModel_GenericIO_GGIO1_Ind4 = {
    DataObjectModelType,
    "Ind4",
    (ModelNode*) &testModel_GenericIO_GGIO1,
    NULL,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4_stVal,
    0,
    -1
};

DataAttribute testModel_GenericIO_GGIO1_Ind4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute testModel_GenericIO_GGIO1_Ind4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &testModel_GenericIO_GGIO1_Ind4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

extern ReportControlBlock testModel_GenericIO_LLN0_report0;
extern ReportControlBlock testModel_GenericIO_LLN0_report1;
extern ReportControlBlock testModel_GenericIO_LLN0_report2;
extern ReportControlBlock testModel_GenericIO_LLN0_report3;
extern ReportControlBlock testModel_GenericIO_LLN0_report4;
extern ReportControlBlock testModel_GenericIO_LLN0_report5;
extern ReportControlBlock testModel_GenericIO_LLN0_report6;

ReportControlBlock testModel_GenericIO_LLN0_report0 = {&testModel_GenericIO_LLN0, "EventsRCB01", "Events1", false, "Events", 4294967295, 24, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report1};
ReportControlBlock testModel_GenericIO_LLN0_report1 = {&testModel_GenericIO_LLN0, "EventsIndexed01", "Events2", false, "Events", 1, 24, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report2};
ReportControlBlock testModel_GenericIO_LLN0_report2 = {&testModel_GenericIO_LLN0, "EventsIndexed02", "Events2", false, "Events", 1, 24, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report3};
ReportControlBlock testModel_GenericIO_LLN0_report3 = {&testModel_GenericIO_LLN0, "EventsIndexed03", "Events2", false, "Events", 1, 24, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report4};
ReportControlBlock testModel_GenericIO_LLN0_report4 = {&testModel_GenericIO_LLN0, "Measurements01", "Measurements", true, "Measurements", 1, 16, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report5};
ReportControlBlock testModel_GenericIO_LLN0_report5 = {&testModel_GenericIO_LLN0, "Measurements02", "Measurements", true, "Measurements", 1, 16, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &testModel_GenericIO_LLN0_report6};
ReportControlBlock testModel_GenericIO_LLN0_report6 = {&testModel_GenericIO_LLN0, "Measurements03", "Measurements", true, "Measurements", 1, 16, 239, 50, 1000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};




extern LogControlBlock testModel_GenericIO_LLN0_lcb0;
extern LogControlBlock testModel_GenericIO_LLN0_lcb1;
LogControlBlock testModel_GenericIO_LLN0_lcb0 = {&testModel_GenericIO_LLN0, "EventLog", "Events", "GenericIO/LLN0$EventLog", 3, 0, true, true, &testModel_GenericIO_LLN0_lcb1};
LogControlBlock testModel_GenericIO_LLN0_lcb1 = {&testModel_GenericIO_LLN0, "GeneralLog", NULL, NULL, 3, 0, true, true, NULL};

extern Log testModel_GenericIO_LLN0_log0;
extern Log testModel_GenericIO_LLN0_log1;
Log testModel_GenericIO_LLN0_log0 = {&testModel_GenericIO_LLN0, "GeneralLog", &testModel_GenericIO_LLN0_log1};
Log testModel_GenericIO_LLN0_log1 = {&testModel_GenericIO_LLN0, "EventLog", NULL};


IedModel testModel = {
    "simpleIO",
    &testModel_GenericIO,
    &testModelds_GenericIO_LLN0_Events,
    &testModel_GenericIO_LLN0_report0,
    NULL,
    NULL,
    NULL,
    &testModel_GenericIO_LLN0_lcb0,
    &testModel_GenericIO_LLN0_log0,
    initializeValues
};

static void
initializeValues()
{

testModel_GenericIO_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

testModel_GenericIO_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("MZ Automation");

testModel_GenericIO_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("0.7.3");

testModel_GenericIO_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("libiec61850 server example");

testModel_GenericIO_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

testModel_GenericIO_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

testModel_GenericIO_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

testModel_GenericIO_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

testModel_GenericIO_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);
}
