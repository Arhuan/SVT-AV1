/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbInterPrediction_h
#define EbInterPrediction_h

#include "EbDefinitions.h"
#include "EbPictureControlSet.h"
#include "EbCodingUnit.h"
#include "EbPredictionUnit.h"
#include "EbModeDecision.h"
#include "EbMcp.h"
#include "EbMvMerge.h"

#ifdef __cplusplus
extern "C" {
#endif

    extern DECLARE_ALIGNED(256, const InterpKernel, sub_pel_filters_8[SUBPEL_SHIFTS]);
    extern DECLARE_ALIGNED(256, const InterpKernel, sub_pel_filters_8smooth[SUBPEL_SHIFTS]);
    extern DECLARE_ALIGNED(256, const InterpKernel, sub_pel_filters_8sharp[SUBPEL_SHIFTS]);
    extern DECLARE_ALIGNED(256, const InterpKernel, sub_pel_filters_4[SUBPEL_SHIFTS]);
    extern DECLARE_ALIGNED(256, const InterpKernel, sub_pel_filters_4smooth[SUBPEL_SHIFTS]);
    extern DECLARE_ALIGNED(256, const InterpKernel, bilinear_filters[SUBPEL_SHIFTS]);

    struct ModeDecisionContext;

    typedef struct InterPredictionContext {
        MotionCompensationPredictionContext  *mcp_context;
    } InterPredictionContext;
#if !UNPACK_REF_POST_EP
    extern EbErrorType inter_prediction_context_ctor(
        InterPredictionContext   **inter_prediction_context,
        EbColorFormat                color_format,
        uint16_t                     max_cu_width,
        uint16_t                     max_cu_height);
#endif
    EbErrorType av1_inter_prediction(
        PictureControlSet                    *picture_control_set_ptr,
        uint32_t                                interp_filters,
        CodingUnit                           *cu_ptr,
        uint8_t                                 ref_frame_type,
        MvUnit                               *mv_unit,
        uint8_t                                  use_intrabc,
#if OBMC_SUP 
        MotionMode                             motion_mode,
#endif
#if OBMC_WSRC
        uint8_t  use_precomputed_obmc,
        struct ModeDecisionContext * md_context,
#endif
#if COMP_MODE
        uint8_t                                compound_idx,
#endif
#if COMP_DIFF
        INTERINTER_COMPOUND_DATA               *interinter_comp,
#endif
#if II_ED
    TileInfo                                * tile,
    NeighborArrayUnit                       *luma_recon_neighbor_array,
    NeighborArrayUnit                       *cb_recon_neighbor_array ,
    NeighborArrayUnit                       *cr_recon_neighbor_array ,
    uint8_t                                 is_interintra_used ,
    INTERINTRA_MODE                         interintra_mode,
    uint8_t                                 use_wedge_interintra,
    int32_t                                 interintra_wedge_index,

#endif
        uint16_t                                pu_origin_x,
        uint16_t                                pu_origin_y,
        uint8_t                                 bwidth,
        uint8_t                                 bheight,
        EbPictureBufferDesc                  *ref_pic_list0,
        EbPictureBufferDesc                  *ref_pic_list1,
        EbPictureBufferDesc                  *prediction_ptr,
        uint16_t                                dst_origin_x,
        uint16_t                                dst_origin_y,
        EbBool                                  perform_chroma);

#if COMP_DIFF
    void search_compound_diff_wedge(
        PictureControlSet                    *picture_control_set_ptr,
        struct ModeDecisionContext                  *context_ptr,
        ModeDecisionCandidate                *candidate_ptr);
#endif
#if COMP_AVG_DIST
    void search_compound_avg_dist(
        PictureControlSet                    *picture_control_set_ptr,
        struct ModeDecisionContext                    *context_ptr,
        ModeDecisionCandidate                *candidate_ptr);
#endif

    EbErrorType inter_pu_prediction_av1(
        struct ModeDecisionContext           *md_context_ptr,
        PictureControlSet                    *picture_control_set_ptr,
        ModeDecisionCandidateBuffer          *candidate_buffer_ptr);

    EbErrorType av1_inter_prediction_hbd(
        PictureControlSet                    *picture_control_set_ptr,
        uint8_t                                 ref_frame_type,
        CodingUnit                           *cu_ptr,
        MvUnit                               *mv_unit,
        uint8_t                                  use_intrabc,
        uint16_t                                pu_origin_x,
        uint16_t                                pu_origin_y,
        uint8_t                                 bwidth,
        uint8_t                                 bheight,
        EbPictureBufferDesc                  *ref_pic_list0,
        EbPictureBufferDesc                  *ref_pic_list1,
        EbPictureBufferDesc                  *prediction_ptr,
        uint16_t                                dst_origin_x,
        uint16_t                                dst_origin_y,
        uint8_t                                 bit_depth);

    EbErrorType choose_mvp_idx_v2(
        ModeDecisionCandidate               *candidate_ptr,
        uint32_t                               cu_origin_x,
        uint32_t                               cu_origin_y,
        uint32_t                               pu_index,
        uint32_t                               tb_size,
        int16_t                               *ref0_amvp_cand_array_x,
        int16_t                               *ref0_amvp_cand_array_y,
        uint32_t                               ref0_num_available_amvp_cand,
        int16_t                               *ref1_amvp_cand_array_x,
        int16_t                               *ref1_amvp_cand_array_y,
        uint32_t                               ref1_num_available_amvp_cand,
        PictureControlSet                   *picture_control_set_ptr);

    EbErrorType warped_motion_prediction(
        MvUnit                               *mv_unit,
        uint16_t                                pu_origin_x,
        uint16_t                                pu_origin_y,
        CodingUnit                           *cu_ptr,
        const BlockGeom                        *blk_geom,
        EbPictureBufferDesc                  *ref_pic_list0,
        EbPictureBufferDesc                  *prediction_ptr,
        uint16_t                                dst_origin_x,
        uint16_t                                dst_origin_y,
        EbWarpedMotionParams                   *wm_params,
        uint8_t                                 bit_depth,
        EbBool                                  perform_chroma);

#ifdef __cplusplus
}
#endif
#endif //EbInterPrediction_h
