/* Copyright (c) 2020 Themaister
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once
// Reused from Granite.

#include <stdint.h>
#include <stdio.h>

#if defined(_MSC_VER)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define LOGE(...)                                                  \
	do                                                             \
	{                                                              \
		fprintf(stderr, "[ERROR]: " __VA_ARGS__);                  \
		fflush(stderr);                                            \
		char buffer[4096];                                         \
		snprintf(buffer, sizeof(buffer), "[ERROR]: " __VA_ARGS__); \
		OutputDebugStringA(buffer);                                \
	} while (false)

#define LOGW(...)                                                 \
	do                                                            \
	{                                                             \
		fprintf(stderr, "[WARN]: " __VA_ARGS__);                  \
		fflush(stderr);                                           \
		char buffer[4096];                                        \
		snprintf(buffer, sizeof(buffer), "[WARN]: " __VA_ARGS__); \
		OutputDebugStringA(buffer);                               \
	} while (false)

#define LOGI(...)                                                 \
	do                                                            \
	{                                                             \
		fprintf(stderr, "[INFO]: " __VA_ARGS__);                  \
		fflush(stderr);                                           \
		char buffer[4096];                                        \
		snprintf(buffer, sizeof(buffer), "[INFO]: " __VA_ARGS__); \
		OutputDebugStringA(buffer);                               \
	} while (false)
#elif defined(ANDROID)
#include <android/log.h>
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "DXIL2SPIRV", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, "DXIL2SPIRV", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "DXIL2SPIRV", __VA_ARGS__)
#else
#define LOGE(...)                                 \
	do                                            \
	{                                             \
		fprintf(stderr, "[ERROR]: " __VA_ARGS__); \
		fflush(stderr);                           \
	} while (false)

#define LOGW(...)                                \
	do                                           \
	{                                            \
		fprintf(stderr, "[WARN]: " __VA_ARGS__); \
		fflush(stderr);                          \
	} while (false)

#define LOGI(...)                                \
	do                                           \
	{                                            \
		fprintf(stderr, "[INFO]: " __VA_ARGS__); \
		fflush(stderr);                          \
	} while (false)
#endif
