#version 120

uniform sampler2DRect tex0;
varying vec2 texCoordVarying;

void main() {
	vec4 tex = texture2DRect(tex0, texCoordVarying);
	tex.g = 0;
	tex.b = 0;
	gl_FragColor = tex;
}