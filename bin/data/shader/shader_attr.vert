#version 410

uniform mat4 modelToWorld;
uniform mat4 worldToCamera;
uniform mat4 cameraToView;
//uniform mat4 matrix;
in vec4 position;
in vec3 color;
out vec4 colorV;

void main() {
	gl_Position = cameraToView * worldToCamera * modelToWorld * position;
	//gl_Position = matrix * position;
	//gl_Position = position;
	colorV = vec4(color, 1.0);
}