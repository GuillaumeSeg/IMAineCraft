#version 330

in vec3 vNormal;
in vec2 vTexCoords;

out vec3 fFragColor;

        struct Material {
            vec3 ambient;
            vec3 diffuse;
            vec3 specular;
            float shininess;
        };
        

uniform Material uMaterial;

void main() {
    fFragColor = vNormal;
}

