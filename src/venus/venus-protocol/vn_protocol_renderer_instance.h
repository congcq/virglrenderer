/* This file is generated by venus-protocol.  See vn_protocol_renderer.h. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_INSTANCE_H
#define VN_PROTOCOL_RENDERER_INSTANCE_H

#include "vn_protocol_renderer_structs.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/*
 * These structs/unions/commands are not included
 *
 *   vkGetInstanceProcAddr
 */

/* struct VkApplicationInfo chain */

static inline void *
vn_decode_VkApplicationInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkApplicationInfo_self_temp(struct vn_cs_decoder *dec, VkApplicationInfo *val)
{
    /* skip val->{sType,pNext} */
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        val->pApplicationName = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pApplicationName) * string_size);
        if (!val->pApplicationName) return;
        vn_decode_blob_array(dec, (char *)val->pApplicationName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pApplicationName = NULL;
    }
    vn_decode_uint32_t(dec, &val->applicationVersion);
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        val->pEngineName = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pEngineName) * string_size);
        if (!val->pEngineName) return;
        vn_decode_blob_array(dec, (char *)val->pEngineName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pEngineName = NULL;
    }
    vn_decode_uint32_t(dec, &val->engineVersion);
    vn_decode_uint32_t(dec, &val->apiVersion);
}

static inline void
vn_decode_VkApplicationInfo_temp(struct vn_cs_decoder *dec, VkApplicationInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_APPLICATION_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkApplicationInfo_pnext_temp(dec);
    vn_decode_VkApplicationInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkApplicationInfo_handle_self(VkApplicationInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->pApplicationName */
    /* skip val->applicationVersion */
    /* skip val->pEngineName */
    /* skip val->engineVersion */
    /* skip val->apiVersion */
}

static inline void
vn_replace_VkApplicationInfo_handle(VkApplicationInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            vn_replace_VkApplicationInfo_handle_self((VkApplicationInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkInstanceCreateInfo chain */

static inline void *
vn_decode_VkInstanceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkInstanceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkInstanceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    if (vn_decode_simple_pointer(dec)) {
        val->pApplicationInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pApplicationInfo));
        if (!val->pApplicationInfo) return;
        vn_decode_VkApplicationInfo_temp(dec, (VkApplicationInfo *)val->pApplicationInfo);
    } else {
        val->pApplicationInfo = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledLayerCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledLayerNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames) * val->enabledLayerCount);
        if (!val->ppEnabledLayerNames) return;
        vn_decode_array_size(dec, val->enabledLayerCount);
        for (uint32_t i = 0; i < val->enabledLayerCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledLayerNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames[i]) * string_size);
            if (!val->ppEnabledLayerNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledLayerNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledLayerNames = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledExtensionCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledExtensionNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames) * val->enabledExtensionCount);
        if (!val->ppEnabledExtensionNames) return;
        vn_decode_array_size(dec, val->enabledExtensionCount);
        for (uint32_t i = 0; i < val->enabledExtensionCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledExtensionNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames[i]) * string_size);
            if (!val->ppEnabledExtensionNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledExtensionNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledExtensionNames = NULL;
    }
}

static inline void
vn_decode_VkInstanceCreateInfo_temp(struct vn_cs_decoder *dec, VkInstanceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    if (stype != VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO)
        vn_cs_decoder_set_fatal(dec);

    val->sType = stype;
    val->pNext = vn_decode_VkInstanceCreateInfo_pnext_temp(dec);
    vn_decode_VkInstanceCreateInfo_self_temp(dec, val);
}

static inline void
vn_replace_VkInstanceCreateInfo_handle_self(VkInstanceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    if (val->pApplicationInfo)
        vn_replace_VkApplicationInfo_handle((VkApplicationInfo *)val->pApplicationInfo);
    /* skip val->enabledLayerCount */
    /* skip val->ppEnabledLayerNames */
    /* skip val->enabledExtensionCount */
    /* skip val->ppEnabledExtensionNames */
}

static inline void
vn_replace_VkInstanceCreateInfo_handle(VkInstanceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            vn_replace_VkInstanceCreateInfo_handle_self((VkInstanceCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

static inline void vn_decode_vkCreateInstance_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateInstance *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkInstanceCreateInfo_temp(dec, (VkInstanceCreateInfo *)args->pCreateInfo);
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
        args->pInstance = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInstance));
        if (!args->pInstance) return;
        vn_decode_VkInstance_temp(dec, args->pInstance);
    } else {
        args->pInstance = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkCreateInstance_args_handle(struct vn_command_vkCreateInstance *args)
{
    if (args->pCreateInfo)
        vn_replace_VkInstanceCreateInfo_handle((VkInstanceCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pInstance */
}

static inline void vn_encode_vkCreateInstance_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateInstance *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateInstance_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pInstance))
        vn_encode_VkInstance(enc, args->pInstance);
}

static inline void vn_decode_vkDestroyInstance_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyInstance *args)
{
    vn_decode_VkInstance_lookup(dec, &args->instance);
    if (vn_decode_simple_pointer(dec)) {
        vn_cs_decoder_set_fatal(dec);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyInstance_args_handle(struct vn_command_vkDestroyInstance *args)
{
    vn_replace_VkInstance_handle(&args->instance);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyInstance_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyInstance *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyInstance_EXT});

    /* skip args->instance */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkEnumerateInstanceVersion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceVersion *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pApiVersion = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pApiVersion));
        if (!args->pApiVersion) return;
    } else {
        args->pApiVersion = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
}

static inline void vn_replace_vkEnumerateInstanceVersion_args_handle(struct vn_command_vkEnumerateInstanceVersion *args)
{
    /* skip args->pApiVersion */
}

static inline void vn_encode_vkEnumerateInstanceVersion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceVersion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceVersion_EXT});

    vn_encode_VkResult(enc, &args->ret);
    if (vn_encode_simple_pointer(enc, args->pApiVersion))
        vn_encode_uint32_t(enc, args->pApiVersion);
}

static inline void vn_decode_vkEnumerateInstanceLayerProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * (args->pPropertyCount ? *args->pPropertyCount : 0));
        if (!args->pProperties) return;
        vn_decode_array_size(dec, (args->pPropertyCount ? *args->pPropertyCount : 0));
        for (uint32_t i = 0; i < (args->pPropertyCount ? *args->pPropertyCount : 0); i++)
            vn_decode_VkLayerProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateInstanceLayerProperties_args_handle(struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateInstanceLayerProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceLayerProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, (args->pPropertyCount ? *args->pPropertyCount : 0));
        for (uint32_t i = 0; i < (args->pPropertyCount ? *args->pPropertyCount : 0); i++)
            vn_encode_VkLayerProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkEnumerateInstanceExtensionProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        args->pLayerName = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pLayerName) * string_size);
        if (!args->pLayerName) return;
        vn_decode_blob_array(dec, (char *)args->pLayerName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pLayerName = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
        vn_cs_decoder_set_fatal(dec);
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * (args->pPropertyCount ? *args->pPropertyCount : 0));
        if (!args->pProperties) return;
        vn_decode_array_size(dec, (args->pPropertyCount ? *args->pPropertyCount : 0));
        for (uint32_t i = 0; i < (args->pPropertyCount ? *args->pPropertyCount : 0); i++)
            vn_decode_VkExtensionProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateInstanceExtensionProperties_args_handle(struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    /* skip args->pLayerName */
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateInstanceExtensionProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceExtensionProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->pLayerName */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, (args->pPropertyCount ? *args->pPropertyCount : 0));
        for (uint32_t i = 0; i < (args->pPropertyCount ? *args->pPropertyCount : 0); i++)
            vn_encode_VkExtensionProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_dispatch_vkCreateInstance(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateInstance args;

    if (!ctx->dispatch_vkCreateInstance) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateInstance_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateInstance(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkCreateInstance returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateInstance_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyInstance(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyInstance args;

    if (!ctx->dispatch_vkDestroyInstance) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyInstance_args_temp(ctx->decoder, &args);
    if (!args.instance) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyInstance(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyInstance_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceVersion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceVersion args;

    if (!ctx->dispatch_vkEnumerateInstanceVersion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceVersion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceVersion(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkEnumerateInstanceVersion returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceVersion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceLayerProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceLayerProperties args;

    if (!ctx->dispatch_vkEnumerateInstanceLayerProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceLayerProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceLayerProperties(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkEnumerateInstanceLayerProperties returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceLayerProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceExtensionProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceExtensionProperties args;

    if (!ctx->dispatch_vkEnumerateInstanceExtensionProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceExtensionProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceExtensionProperties(ctx, &args);

#ifdef DEBUG
    if (!vn_cs_decoder_get_fatal(ctx->decoder) && vn_dispatch_should_log_result(args.ret))
        vn_dispatch_debug_log(ctx, "vkEnumerateInstanceExtensionProperties returned %d", args.ret);
#endif

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceExtensionProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

#pragma GCC diagnostic pop

#endif /* VN_PROTOCOL_RENDERER_INSTANCE_H */
