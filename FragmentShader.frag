
#version 450 core

layout(location = 0) out vec4 color;
uniform vec2 u_res;

void main() {

    vec2 st = (gl_FragCoord.xy) / vec2(1500.0,900.0);
    vec3 col1 = vec3(1.0, 0.55, 0);
    vec3 col2 = vec3(0.5, 0.0, 0.315);
    float mixValue = distance(st, vec2(0,1));
    vec3 col = mix(col1, col2, mixValue);
    color = vec4(col, mixValue); 
    
}