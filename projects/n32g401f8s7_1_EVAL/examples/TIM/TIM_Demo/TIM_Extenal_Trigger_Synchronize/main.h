/**
*\*\file main.h
*\*\author Nations 
*\*\version v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
**/
#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g401f8s7_1.h"
#include "ADTIM_common.h"


typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} Status;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
