/* Copyright 2015 Samsung Electronics Co., LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "../engine/renderer/renderer.h"

#include "util/gvr_jni.h"

namespace gvr {
extern "C" {
void Java_org_gearvrf_NativeMonoscopicRenderer_renderCamera(JNIEnv * env,
        jobject obj, jlong jscene, jlong jcamera, jint viewportX,
        jint viewportY, jint viewportWidth, jint viewportHeight,
        jlong jshader_manager, jlong jpost_effect_shader_manager,
        jlong jpost_effect_render_texture_a,
        jlong jpost_effect_render_texture_b);

}

void Java_org_gearvrf_NativeMonoscopicRenderer_renderCamera(JNIEnv * env,
        jobject obj, jlong jscene, jlong jcamera, jint viewportX,
        jint viewportY, jint viewportWidth, jint viewportHeight,
        jlong jshader_manager, jlong jpost_effect_shader_manager,
        jlong jpost_effect_render_texture_a,
        jlong jpost_effect_render_texture_b) {
    std::shared_ptr<Scene> scene =
            *reinterpret_cast<std::shared_ptr<Scene>*>(jscene);
    std::shared_ptr<Camera> camera =
            *reinterpret_cast<std::shared_ptr<Camera>*>(jcamera);
    std::shared_ptr<ShaderManager> shader_manager =
            *reinterpret_cast<std::shared_ptr<ShaderManager>*>(jshader_manager);
    std::shared_ptr<PostEffectShaderManager> post_effect_shader_manager =
            *reinterpret_cast<std::shared_ptr<PostEffectShaderManager>*>(jpost_effect_shader_manager);
    std::shared_ptr<RenderTexture> post_effect_render_texture_a =
            *reinterpret_cast<std::shared_ptr<RenderTexture>*>(jpost_effect_render_texture_a);
    std::shared_ptr<RenderTexture> post_effect_render_texture_b =
            *reinterpret_cast<std::shared_ptr<RenderTexture>*>(jpost_effect_render_texture_b);

    Renderer::renderCamera(scene, camera, viewportX, viewportY, viewportWidth,
            viewportHeight, shader_manager, post_effect_shader_manager,
            post_effect_render_texture_a, post_effect_render_texture_b);

}

}
