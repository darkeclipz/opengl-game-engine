#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

in vec3 FragPos;
in vec3 Normal;
out vec4 FragColor;
  
uniform float iTime; // current time.
uniform Material material;

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
    float VdotR = max(dot(V, R), 0.0f);

    vec3 ambient = lightColor * material.ambient;
    vec3 diffuse = NdotL * lightColor * material.diffuse;
    vec3 specular = pow(VdotR, material.shininess) * lightColor * material.specular;
    
    vec3 col = ambient + diffuse + specular;
    FragColor = vec4(col, 1.0f);
}  