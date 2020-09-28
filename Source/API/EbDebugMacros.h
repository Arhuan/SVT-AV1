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

//FOR DEBUGGING - Do not remove
#define NO_ENCDEC         0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch
#define PR1485       0 //Fix mismatch C/AVX2 kernel svt_av1_apply_temporal_filter_planewise()

#if 1 // ALL_OFF
#if 1 // ONLY_LOSSLESS
/************************************/
#if 0
#define TUNE_PME 1
#define TUNE_SUBPEL 0
#define SHUT_MV_COST 0
#define TUNE_REF 0
#define TXT_TUNE 1
#endif
/************************************/
#define COST_BASED_PRED_ONLY 1
#define ADD_LEVELS 1
#define PARENT_COST 0
/************************************/
#define RDOQ_CTRLS 1
#if RDOQ_CTRLS
#define SHUT_FP_QUANT_CHROMA 1 //--->
#define SKIP_TRELLIS_BASED_ON_SATD 1 //--->
#define RDOQ_PER_LAYER 0
#endif
/************************************/
#define PD0_SHUT_SKIP_DC_SIGN_UPDATE 1 //---->
/************************************/
#define PD0_REDUCE_ME_INTER_CAND 0
/************************************/
#define PRED_ONLY 0
#define FASTER_PD0 0
#define ENHANCED_FASTER_PD0 0
/************************************/
#define PD0_CUT_4x4 0
#define PD0_CUT_DEPTH 1
#define PD0_CUT_BIS 0
#define PD0_MD_EXIT 0
#define REF_VS_NRF_0 0
#define REF_VS_NRF_1 0
#define PD0_CUT_BYPASS 1
/*****************NEW*******************/
#define FIX_IFS_0 0
#define FIX_IFS_1 0
/*****************TF*******************/
#define TF_CHROMA_BLIND 1
#define TF_32x32_ONLY 0 ///***
#define TF_32x32_16x16_ADAPT 1 ///***
#define TF_NOISE 0
#define TF_REFACTOR 1 ///***
#define TF_3X3 0  ///***
#if TF_3X3
#define ENHANCED_TF_3X3 1  ///***
#endif
#define SHUT_TF 0
/************************************/
#define ME_TUNING 1
#define HME_LEVEL_1 1
#define HME_LEVEL_2 1

/************************************/
#define SHUT_TXT_STATS 1 // Set0: REF = DCT - DCT + H - DCT + V - DCT(what you have added)
#define TX_TYPE_GROUPING 1


#endif
#define ALL_LOSSLES_OPT 1
#if ALL_LOSSLES_OPT
/***********LOSSLESS I **************/

#define REMOVE_USELESS_0 1 // 1
#define REMOVE_USELESS_1 1
#define LOSSLESS_OPT 1 //2
#define OPTIMIZE_BUILD_QUANTIZER 1
#define OPT_IFS 1

#define PD0_OPT 1
#if PD0_OPT
#define PD0_A_OPT 1 // 3
#define PD0_B_OPT 1
#define PD0_C_OPT 1 // 4
#define PD0_D_OPT 1
#endif
/***********LOSSLESS II **************/
#define INIT_BLOCK_OPT        1 // 5
#define BYPASS_SIGNAL_SET     1
#define ME_IDX_LUPT           1
#define INIT_FAST_LOOP_OPT    1
#define REMOVE_UNUSED_NEIG_ARRAY   1
#endif

/***********TOOLS****************/
#define ME_16x11 0
#define HME_48x32 0


/************************************/
#define SHUT_WARP 0
#define ME_MAX_32_32 0
/************************************/
#define SHUT_SPATIAL_SSE 0
/************************************/
#define OPT_4           0
#define REMOVE_TXT_STATS 0
#define EXIT_TX_TYPE_IF_HAS_COEFF 0
#define COST_BASED_TXT 0
#define DCT_VS_DST  0 // to test for only INTRA CLASS
#define TXT_OFF 0
#define SKIP_TXT_RATE_ESTIMATION 0
#define TEST_BLOCK_BASED 0
/************************************/
#define SHUT_RDOQ_CHROMA 0
#define SHUT_FP_QUANT 0
#define SHUT_FP_QUANT_TX_SIZE 0
#define SHUT_FP_QUANT_TX_TYPE 0
#define SHUT_FP_QUANT_INTER 0
#define SHUT_FP_QUANT_INTRA 0
#define FAST_RDOQ_INTER 0
#define FAST_RDOQ_EOB 0
#define FAST_RDOQ_CHROMA 0 //--->
#define FAST_RDOQ_TH 0
#define FAST_RDOQ_N2 0
/************************************/

#define PER_REFERENCE_RDOQ 0

#define RDOQ_ONLY_NOT_N2 0
#define TUNE_SATD 0

#define FAST_RDOQ_SATD 0  //--->
#define RDOQ_DO_NOT_PROCESS_ZZ_COEF 0 // ---->
#define SHUT_RDOQ 0 //--->
#if FAST_RDOQ_SATD
#define FAST_RDOQ_MODE 0//--->
#endif
#define COEFF_OPT 0
#if COEFF_OPT
#define RES_VAR_BASED_DCT_DCT 0 //--->
#define RES_VAR_BASED_FORCE_SKIP 0

#endif

#define MAX_NZ_NUM    0
#define RATE_BLIND 0
#define SHUT_RDOQ_SKIP 0

#define RDOQ_REFACTOR_0 0
#define RDOQ_REFACTOR_1 0
#define RDOQ_TEST0 0 // RDOQ do not perform rd_low for only abs_qc==1
#define RDOQ_TEST1 0 // cnt fail
#define RDOQ_TEST2 0 // ???
#define FAST_RDOQ_ONLY_COEFF 0
#define FAST_RDOQ_ONLY_EOB 0
#if FAST_RDOQ_ONLY_COEFF
#define FAST_RDOQ 1
#endif
#define USE_MD_SKIP_DECISION_0 0 // clean-up (semi-lossless)
#define USE_MD_SKIP_DECISION_1 0 // clean-up (use md skip)
#define ON_THE_FLY_MDS1_BYPASS 0
#endif

#if 1 // just double check
#define ADD_GM_TO_M8 1 // Add GM to M7; change CFL and TF settings to offset speed loss
#define FEATURE_SKIP_GM_UNIPRED 1 // Add ability to skip GM unipred injection, and use bipred only
#define FASTER_GM 0
#define ERROR_GM 0
#define GM_LIST_0 0
#define GM_AFFINE 1
#define CDEF_OPT                1 // Added new fast search for CDEF
#define DC_ONLY_AT_NON_REF 1 // use only intra dc at no reference frame
#define NEW_CDF 1 // Updating CDF levels and controls
#endif
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EbDebugMacros_h
