#ifndef TEXTURE_H
#define TEXTURE_H


class Texture2D
{
public:
    unsigned int id;
    unsigned int width, height;
    unsigned int internalFormat;
    unsigned int imageFormat;

    unsigned int wrapS;
    unsigned int wrapT;
    unsigned int filterMin;
    unsigned int filterMax;

    Texture2D();

    void generate(unsigned int width, unsigned int height, unsigned char *data);
    void bind() const;

};

#endif