#version 410

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
in vec4  position;
in vec2  texcoord;
out vec2 texCoordVarying;

void main()
{
	texCoordVarying = texcoord;
	gl_Position = projectionMatrix * modelViewMatrix * position;
}