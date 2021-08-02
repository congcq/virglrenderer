/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_QUERY_POOL_H
#define VN_PROTOCOL_RENDERER_QUERY_POOL_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* struct VkQueryPoolCreateInfo chain */

static inline void *
vn_decode_VkQueryPoolCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkQueryPoolCreateInfo_self_temp(struct vn_cs_decoder *dec, VkQueryPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkQueryType(dec, &val->queryType);
    vn_decode_uint32_t(dec, &val->queryCount);
    vn_decode_VkFlags(dec, &val->pipelineStatistics);
}

static inline void
vn_decode_VkQueryPoolCreateInfo_temp(struct vn_cs_decoder *dec, VkQueryPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkQueryPoolCreateInfo_pnext_temp(dec);
    vn_decode_VkQueryPoolCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkQueryPoolCreateInfo_handle_self(VkQueryPoolCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queryType */
    /* skip val->queryCount */
    /* skip val->pipelineStatistics */
}

static inline void
vn_replace_VkQueryPoolCreateInfo_handle(VkQueryPoolCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            vn_replace_VkQueryPoolCreateInfo_handle_self((VkQueryPoolCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkQueryPoolCreateInfo_temp(dec, (VkQueryPoolCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pQueryPool = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueryPool));
        if (!args->pQueryPool) return;
        vn_decode_VkQueryPool(dec, args->pQueryPool);
    } else {
        args->pQueryPool = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreateQueryPool_args_handle(struct vn_command_vkCreateQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkQueryPoolCreateInfo_handle((VkQueryPoolCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pQueryPool */
}

static inline void vn_encode_vkCreateQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateQueryPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pQueryPool))
        vn_encode_VkQueryPool(enc, args->pQueryPool);
}

static inline void vn_decode_vkDestroyQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyQueryPool_args_handle(struct vn_command_vkDestroyQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyQueryPool_EXT});

    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetQueryPoolResults_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetQueryPoolResults *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
    vn_decode_size_t(dec, &args->dataSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->dataSize);
        args->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pData) return;
    } else {
        vn_decode_array_size(dec, 0);
        args->pData = NULL;
    }
    vn_decode_VkDeviceSize(dec, &args->stride);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkGetQueryPoolResults_args_handle(struct vn_command_vkGetQueryPoolResults *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
    /* skip args->dataSize */
    /* skip args->pData */
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_encode_vkGetQueryPoolResults_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetQueryPoolResults *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetQueryPoolResults_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
    /* skip args->dataSize */
    if (args->pData) {
        vn_encode_array_size(enc, args->dataSize);
        vn_encode_blob_array(enc, args->pData, args->dataSize);
    } else {
        vn_encode_array_size(enc, 0);
    }
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_decode_vkResetQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
}

static inline void vn_replace_vkResetQueryPool_args_handle(struct vn_command_vkResetQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_encode_vkResetQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetQueryPool_EXT});

    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_dispatch_vkCreateQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateQueryPool args;

    if (!ctx->dispatch_vkCreateQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateQueryPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateQueryPool(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateQueryPool returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyQueryPool args;

    if (!ctx->dispatch_vkDestroyQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyQueryPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyQueryPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetQueryPoolResults(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetQueryPoolResults args;

    if (!ctx->dispatch_vkGetQueryPoolResults) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetQueryPoolResults_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetQueryPoolResults(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkGetQueryPoolResults returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetQueryPoolResults_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetQueryPool args;

    if (!ctx->dispatch_vkResetQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetQueryPool_args_temp(ctx->decoder, &args);
    if (!args.device) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetQueryPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_QUERY_POOL_H */
