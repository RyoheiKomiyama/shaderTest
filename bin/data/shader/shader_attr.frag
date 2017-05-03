#version 410

in vec4 colorV;
out vec4 outputColor;

void main() {
	vec4 c = colorV;
	c.a = 1.0;
	outputColor = c;
}