#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>
#include <glad/glad.h>

#include "shader.h"
#include "texture.h"

class ResourceManager
{
public:
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Texture2D> textures;

    static Shader loadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    static Shader getShader(std::string name);

    static Texture2D loadTexture(const char *file, bool alpha, std::string name);
    static Texture2D getTexture(std::string name);

    static void clear();

private:
    // private constructor, we do not want nay actual resource manage objects. 
    //its members and functions should be publicly available (static)
    ResourceManager(){}
    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    static Texture2D loadTextureFromFile(const char *file, bool alpha);

};  


#endif