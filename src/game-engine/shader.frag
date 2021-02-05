#version 330 core

in vec3 FragPos;
in vec3 Normal;
out vec4 FragColor;
  
uniform float iTime; // current time.

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;  
uniform vec3 viewPos;

uniform sampler2D iChannel0;

void main()
{
    vec3 N = normalize(Normal);
    vec3 L = normalize(lightPos - FragPos);  
    vec3 V = normalize(viewPos - FragPos);
    vec3 R = reflect(-L, N);
    float NdotL = max(dot(N, L), 0.0f);

    // Ambient    
    float ambientStength = 0.1f;
    vec3 ambient = ambientStength * lightColor;

    // Diffuse
    vec3 diffuse = lightColor * NdotL;

    // Specular
    float specularStrength = 0.5;
    float k = pow(max(dot(V, R), 0.0), 32);
    vec3 specular = specularStrength * k * lightColor;  
    
    vec3 col = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(col, 1.0f);
}  