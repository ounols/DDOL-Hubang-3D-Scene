out vec4 FragColor;

//[texture.albedo]//
uniform sampler2D u_sampler_albedo;

in mediump vec2 v_textureCoordOut;

void main() {
    highp vec4 albedo = texture(u_sampler_albedo, v_textureCoordOut).rgba;
    if (albedo.a < 0.01) {
        discard;
    }
    FragColor = albedo;
    gl_FragDepth = 0.0;
}