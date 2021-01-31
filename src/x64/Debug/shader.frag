#version 330 core
out vec4 FragColor;
  
uniform float iTime; // current time.

in vec3 Color;
in vec2 TexCoord;

uniform sampler2D iChannel0;

void main()
{
    vec3 col = 0.5 + 0.5 * cos(vec3(0, 2, 4) + iTime + TexCoord.xyx);
    vec3 tex = texture(iChannel0, TexCoord).rgb;

    FragColor = vec4(tex, 1.0f);
}  