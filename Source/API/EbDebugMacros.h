/*
* Copyright(c) 2020 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/


/*
* This file contains only debug macros that are used during the development
* and are supposed to be cleaned up every tag cycle
* all macros must have the following format:
* - enabling a feature should be prefixed by ENABLE_
* - disableing a feature should be prefixed by DISABLE_
* - tuning a feature should be prefixed by TUNE_
* - adding a new feature should be prefixed by FEATURE_
* - bug fixes should be prefixed by FIX_
* - all macros must have a coherent comment explaining what the MACRO is doing
* - #if 0 / #if 1 are not to be used
*/

#ifndef EbDebugMacros_h
#define EbDebugMacros_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// undefining this macro would allow the AVX512 optimization to be enabled by default
#ifndef NON_AVX512_SUPPORT
#define NON_AVX512_SUPPORT
#endif

// START  svt-03 /////////////////////////////////////////////////////////
#define FEATURE_MDS2 1 // TXT @ MDS2 if CLASS_0_3, and TXS/RDOQ @ MDS2 if CLASS_1_2
// END  svt-03 /////////////////////////////////////////////////////////

//FOR DEBUGGING - Do not remove
#define NO_ENCDEC         0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EbDebugMacros_h
