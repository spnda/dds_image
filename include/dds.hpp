#pragma once

#if __cplusplus > 201703L && defined(DDS_USE_STD_FILESYSTEM)
#include <filesystem>
namespace fs = std::filesystem;
#endif

#include <fstream>
#include <iostream>

#include "dds_formats.hpp"

#if __cplusplus > 201703L
#define NO_DISCARD [[nodiscard]]
#else
#define NO_DISCARD
#endif

namespace dds {
    NO_DISCARD inline uint32_t getBlockSize(const DXGI_FORMAT format) {
        switch (format) {
            case DXGI_FORMAT_BC1_UNORM:
            case DXGI_FORMAT_BC1_UNORM_SRGB:
            case DXGI_FORMAT_BC4_UNORM:
            case DXGI_FORMAT_BC4_SNORM:
                return 8;
            case DXGI_FORMAT_BC2_UNORM:
            case DXGI_FORMAT_BC2_UNORM_SRGB:
            case DXGI_FORMAT_BC3_UNORM:
            case DXGI_FORMAT_BC3_UNORM_SRGB:
            case DXGI_FORMAT_BC5_UNORM:
            case DXGI_FORMAT_BC5_SNORM:
                return 16;
            default:
                return 0;
        }
    }

    NO_DISCARD inline uint32_t getBitsPerPixel(const DXGI_FORMAT format) {
        switch (format) {
            case DXGI_FORMAT_R32G32B32A32_TYPELESS:
            case DXGI_FORMAT_R32G32B32A32_FLOAT:
            case DXGI_FORMAT_R32G32B32A32_UINT:
            case DXGI_FORMAT_R32G32B32A32_SINT:
                return 128;

            case DXGI_FORMAT_R32G32B32_TYPELESS:
            case DXGI_FORMAT_R32G32B32_FLOAT:
            case DXGI_FORMAT_R32G32B32_UINT:
            case DXGI_FORMAT_R32G32B32_SINT:
                return 96;

            case DXGI_FORMAT_R16G16B16A16_TYPELESS:
            case DXGI_FORMAT_R16G16B16A16_FLOAT:
            case DXGI_FORMAT_R16G16B16A16_UNORM:
            case DXGI_FORMAT_R16G16B16A16_UINT:
            case DXGI_FORMAT_R16G16B16A16_SNORM:
            case DXGI_FORMAT_R16G16B16A16_SINT:
            case DXGI_FORMAT_R32G32_TYPELESS:
            case DXGI_FORMAT_R32G32_FLOAT:
            case DXGI_FORMAT_R32G32_UINT:
            case DXGI_FORMAT_R32G32_SINT:
            case DXGI_FORMAT_R32G8X24_TYPELESS:
            case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
            case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
            case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
                return 64;

            case DXGI_FORMAT_R10G10B10A2_TYPELESS:
            case DXGI_FORMAT_R10G10B10A2_UNORM:
            case DXGI_FORMAT_R10G10B10A2_UINT:
            case DXGI_FORMAT_R11G11B10_FLOAT:
            case DXGI_FORMAT_R8G8B8A8_TYPELESS:
            case DXGI_FORMAT_R8G8B8A8_UNORM:
            case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
            case DXGI_FORMAT_R8G8B8A8_UINT:
            case DXGI_FORMAT_R8G8B8A8_SNORM:
            case DXGI_FORMAT_R8G8B8A8_SINT:
            case DXGI_FORMAT_R16G16_TYPELESS:
            case DXGI_FORMAT_R16G16_FLOAT:
            case DXGI_FORMAT_R16G16_UNORM:
            case DXGI_FORMAT_R16G16_UINT:
            case DXGI_FORMAT_R16G16_SNORM:
            case DXGI_FORMAT_R16G16_SINT:
            case DXGI_FORMAT_R32_TYPELESS:
            case DXGI_FORMAT_D32_FLOAT:
            case DXGI_FORMAT_R32_FLOAT:
            case DXGI_FORMAT_R32_UINT:
            case DXGI_FORMAT_R32_SINT:
            case DXGI_FORMAT_R24G8_TYPELESS:
            case DXGI_FORMAT_D24_UNORM_S8_UINT:
            case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
            case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
            case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
            case DXGI_FORMAT_R8G8_B8G8_UNORM:
            case DXGI_FORMAT_G8R8_G8B8_UNORM:
            case DXGI_FORMAT_B8G8R8A8_UNORM:
            case DXGI_FORMAT_B8G8R8X8_UNORM:
            case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
            case DXGI_FORMAT_B8G8R8A8_TYPELESS:
            case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
            case DXGI_FORMAT_B8G8R8X8_TYPELESS:
            case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
                return 32;

            case DXGI_FORMAT_R8G8_TYPELESS:
            case DXGI_FORMAT_R8G8_UNORM:
            case DXGI_FORMAT_R8G8_UINT:
            case DXGI_FORMAT_R8G8_SNORM:
            case DXGI_FORMAT_R8G8_SINT:
            case DXGI_FORMAT_R16_TYPELESS:
            case DXGI_FORMAT_R16_FLOAT:
            case DXGI_FORMAT_D16_UNORM:
            case DXGI_FORMAT_R16_UNORM:
            case DXGI_FORMAT_R16_UINT:
            case DXGI_FORMAT_R16_SNORM:
            case DXGI_FORMAT_R16_SINT:
            case DXGI_FORMAT_B5G6R5_UNORM:
            case DXGI_FORMAT_B5G5R5A1_UNORM:
            case DXGI_FORMAT_B4G4R4A4_UNORM:
                return 16;

            case DXGI_FORMAT_R8_TYPELESS:
            case DXGI_FORMAT_R8_UNORM:
            case DXGI_FORMAT_R8_UINT:
            case DXGI_FORMAT_R8_SNORM:
            case DXGI_FORMAT_R8_SINT:
            case DXGI_FORMAT_A8_UNORM:
                return 8;

            case DXGI_FORMAT_R1_UNORM:
                return 1;

            case DXGI_FORMAT_BC1_TYPELESS:
            case DXGI_FORMAT_BC1_UNORM:
            case DXGI_FORMAT_BC1_UNORM_SRGB:
            case DXGI_FORMAT_BC4_TYPELESS:
            case DXGI_FORMAT_BC4_UNORM:
            case DXGI_FORMAT_BC4_SNORM:
                return 4;

            case DXGI_FORMAT_BC2_TYPELESS:
            case DXGI_FORMAT_BC2_UNORM:
            case DXGI_FORMAT_BC2_UNORM_SRGB:
            case DXGI_FORMAT_BC3_TYPELESS:
            case DXGI_FORMAT_BC3_UNORM:
            case DXGI_FORMAT_BC3_UNORM_SRGB:
            case DXGI_FORMAT_BC5_TYPELESS:
            case DXGI_FORMAT_BC5_UNORM:
            case DXGI_FORMAT_BC5_SNORM:
            case DXGI_FORMAT_BC6H_TYPELESS:
            case DXGI_FORMAT_BC6H_UF16:
            case DXGI_FORMAT_BC6H_SF16:
            case DXGI_FORMAT_BC7_TYPELESS:
            case DXGI_FORMAT_BC7_UNORM:
            case DXGI_FORMAT_BC7_UNORM_SRGB:
                return 8;
            default:
                return 0;
        }
    }

#ifdef VK_VERSION_1_0
    NO_DISCARD inline VkFormat getVulkanFormat(DXGI_FORMAT format, const bool alphaFlag) {
        switch (format) {
            case DXGI_FORMAT_BC1_UNORM: {
                if (alphaFlag) return VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
                else return VK_FORMAT_BC1_RGB_UNORM_BLOCK;
            }
            case DXGI_FORMAT_BC1_UNORM_SRGB: {
                if (alphaFlag) return VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
                else return VK_FORMAT_BC1_RGB_SRGB_BLOCK;
            }

            case DXGI_FORMAT_BC2_UNORM:       return VK_FORMAT_BC2_UNORM_BLOCK;
            case DXGI_FORMAT_BC2_UNORM_SRGB:  return VK_FORMAT_BC2_SRGB_BLOCK;
            case DXGI_FORMAT_BC3_UNORM:       return VK_FORMAT_BC3_UNORM_BLOCK;
            case DXGI_FORMAT_BC3_UNORM_SRGB:  return VK_FORMAT_BC3_SRGB_BLOCK;
            case DXGI_FORMAT_BC4_UNORM:       return VK_FORMAT_BC4_UNORM_BLOCK;
            case DXGI_FORMAT_BC4_SNORM:       return VK_FORMAT_BC4_SNORM_BLOCK;
            case DXGI_FORMAT_BC5_UNORM:       return VK_FORMAT_BC5_UNORM_BLOCK;
            case DXGI_FORMAT_BC5_SNORM:       return VK_FORMAT_BC5_SNORM_BLOCK;

            case DXGI_FORMAT_R8G8B8A8_UNORM:      return VK_FORMAT_R8G8B8A8_UNORM;
            case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return VK_FORMAT_R8G8B8A8_SRGB;
            case DXGI_FORMAT_R8G8B8A8_UINT:       return VK_FORMAT_R8G8B8A8_UINT;
            case DXGI_FORMAT_R8G8B8A8_SNORM:      return VK_FORMAT_R8G8B8A8_SNORM;
            case DXGI_FORMAT_R8G8B8A8_SINT:       return VK_FORMAT_R8G8B8A8_SINT;
            case DXGI_FORMAT_B8G8R8A8_UNORM:      return VK_FORMAT_B8G8R8A8_UNORM;
            case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: return VK_FORMAT_B8G8R8A8_SRGB;

            case DXGI_FORMAT_R16G16B16A16_FLOAT:  return VK_FORMAT_R16G16B16A16_SFLOAT;
            case DXGI_FORMAT_R16G16B16A16_SINT:   return VK_FORMAT_R16G16B16A16_SINT;
            case DXGI_FORMAT_R16G16B16A16_UINT:   return VK_FORMAT_R16G16B16A16_UINT;
            case DXGI_FORMAT_R16G16B16A16_UNORM:  return VK_FORMAT_R16G16B16A16_UNORM;
            case DXGI_FORMAT_R16G16B16A16_SNORM:  return VK_FORMAT_R16G16B16A16_SNORM;

            case DXGI_FORMAT_R8G8_B8G8_UNORM:
            case DXGI_FORMAT_G8R8_G8B8_UNORM:
            case DXGI_FORMAT_YUY2:
            default:
                return VK_FORMAT_UNDEFINED;
        }
    }

    NO_DISCARD inline VkImageCreateInfo getVulkanImageCreateInfo(dds::Image* image) {
        VkImageCreateInfo imageInfo = {};
        imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        switch (image->dimension) {
            case Texture1D: imageInfo.imageType = VK_IMAGE_TYPE_1D; break;
            case Texture2D: imageInfo.imageType = VK_IMAGE_TYPE_2D; break;
            case Texture3D: imageInfo.imageType = VK_IMAGE_TYPE_3D; break;
            default: break;
        }
        imageInfo.format = getVulkanFormat(image->format, image->supportsAlpha);
        imageInfo.extent.width = image->width;
        imageInfo.extent.height = image->height;
        imageInfo.extent.depth = image->depth;
        imageInfo.mipLevels = image->numMips;
        imageInfo.arrayLayers = image->arraySize;
        return imageInfo;
    }

    NO_DISCARD inline VkImageViewCreateInfo getVulkanImageViewCreateInfo(dds::Image* image) {
        VkImageViewCreateInfo imageViewInfo = {};
        imageViewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        imageViewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        imageViewInfo.format = getVulkanFormat(image->format, image->supportsAlpha);
        imageViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        imageViewInfo.subresourceRange.baseMipLevel = 0;
        imageViewInfo.subresourceRange.levelCount = image->numMips;
        imageViewInfo.subresourceRange.baseArrayLayer = 0;
        imageViewInfo.subresourceRange.layerCount = image->arraySize;
        return imageViewInfo;
    }
#endif // #ifdef VK_VERSION_1_0

#if __cplusplus > 201703L && defined(DDS_USE_STD_FILESYSTEM)
    NO_DISCARD inline dds::ReadResult readFile(const fs::path& filepath, dds::Image* image) {
#else
    NO_DISCARD inline dds::ReadResult readFile(const std::string& filepath, dds::Image* image) {
#endif
        std::ifstream filestream(filepath, std::ios::binary | std::ios::in);
        if (!filestream.is_open())
            return dds::ReadResult::Failure;

        // Read the file into a vector.
        filestream.seekg(0, std::ios::end);
        size_t fileSize = filestream.tellg();
        image->data.resize(fileSize);
        filestream.seekg(0);
        filestream.read(image->data.data(), static_cast<int64_t>(fileSize));

        // Read the magic number
        auto* ptr = image->data.data();
        auto* ddsMagic = reinterpret_cast<uint32_t*>(ptr);
        ptr += 4;

        // Read the header
        if (fileSize < sizeof(dds::FileHeader))
            return dds::ReadResult::Failure;
        const auto* header = reinterpret_cast<const dds::FileHeader*>(ptr);
        ptr += sizeof(dds::FileHeader);

        // Validate header
        if (*ddsMagic != dds::DdsMagicNumber::DDS)
            return dds::ReadResult::Failure;

//      UNDO_FOUR_CHARACTER_CODE(header->pixelFormat.fourCC, fourCCStr);
//      std::cout << fourCCStr << std::endl;
        if (header->pixelFormat.flags & PixelFormatFlags::FourCC) {
            const dds::Dx10Header* additionalHeader;
            switch (header->pixelFormat.fourCC) {
                case dds::DdsMagicNumber::DX10: {
                    additionalHeader = reinterpret_cast<const dds::Dx10Header*>(ptr);
                    ptr += sizeof(dds::Dx10Header);

                    image->arraySize = additionalHeader->arraySize;
                    image->format = additionalHeader->dxgiFormat;
                    image->dimension = additionalHeader->resourceDimension;
                    break;
                }
                case DXT1:              image->format = DXGI_FORMAT_BC1_UNORM; break;
                case DXT2: case DXT3:   image->format = DXGI_FORMAT_BC2_UNORM; break;
                case DXT4: case DXT5:   image->format = DXGI_FORMAT_BC3_UNORM; break;
                case ATI1: case BC4U:   image->format = DXGI_FORMAT_BC4_UNORM; break;
                case BC4S:              image->format = DXGI_FORMAT_BC4_SNORM; break;
                case ATI2: case BC5U:   image->format = DXGI_FORMAT_BC5_UNORM; break;
                case BC5S:              image->format = DXGI_FORMAT_BC5_SNORM; break;
                default:
                    return ReadResult::UnsupportedFormat;
            }
        } else {
            if (header->pixelFormat.flags & PixelFormatFlags::RGB) {

            }
        }

        if (header->flags & HeaderFlags::Volume || header->caps2 & Caps2Flags::Cubemap) {
            image->dimension = Texture3D;
        } else {
            image->dimension = Texture2D;
        }

        const auto blockSizeBytes = getBlockSize(image->format);
        const auto pixelSizeBits = getBitsPerPixel(image->format);
        if (!blockSizeBytes && !pixelSizeBits)
            return dds::ReadResult::UnsupportedFormat;

        // Read the image fileSize
        uint32_t totalOffset = 0;
        {
            auto width = header->width;
            auto height = header->height;
            for (uint32_t mip = 0; mip < header->mipmapCount; ++mip) {
                uint32_t surfaceSize;
                if (blockSizeBytes) {
                    auto temp = ((width + 3) / 4);
                    surfaceSize = ((1 < temp) ? temp : 1) * blockSizeBytes;
                } else {
                    const auto pitch = ((width * pixelSizeBits) + 7) / 8; // Divide by 8 for byte alignment.
                    surfaceSize = pitch * height;
                }
                totalOffset += surfaceSize;

                // Not going to include <algorithm> just for std::max.
                uint32_t halfWidth = width / 2;
                width = (1u < halfWidth) ? halfWidth : 1u;
                uint32_t halfHeight = height / 2;
                height = (1u < halfHeight) ? halfHeight : 1u;
            }
        }
        const auto ddsSize = ptr - fileSize + size_t(totalOffset);
        // if (ddsSize > fileSize || ddsSize < fileSize)
        //     return dds::ReadResult::InvalidSize;

        image->numMips = header->mipmapCount;
        image->width = header->width;
        image->height = header->height;
        image->supportsAlpha = header->hasAlphaFlag();

        // Close the file and return success
        filestream.close();
        return dds::ReadResult::Success;
    }
}
