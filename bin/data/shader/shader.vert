#version 410

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 color;
in vec4 position;
//in vec3 color;
out vec4 colorV;

void main() {
	gl_Position = projectionMatrix * modelViewMatrix * position;
	colorV = vec4(color, 1.0);
}