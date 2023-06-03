// Generated by Haxe 5.0.0-alpha.1+2f4b99d
#include <hxcpp.h>

#ifndef INCLUDED_Program
#include <Program.h>
#endif
#ifndef INCLUDED_SimpleCubeProgram
#include <SimpleCubeProgram.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics__WebGLRenderContext_WebGLRenderContext_Impl_
#include <lime/graphics/_WebGLRenderContext/WebGLRenderContext_Impl_.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_utils_ArrayBufferView
#include <lime/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_lime_utils__DataPointer_DataPointer_Impl_
#include <lime/utils/_DataPointer/DataPointer_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_caffec7864cf5c0d_49_new,"SimpleCubeProgram","new",0x4b81fe4f,"SimpleCubeProgram.new","SimpleCubeProgram.hx",49,0x50b28001)
HX_LOCAL_STACK_FRAME(_hx_pos_caffec7864cf5c0d_135_getShaderVarLocations,"SimpleCubeProgram","getShaderVarLocations",0xf70ef361,"SimpleCubeProgram.getShaderVarLocations","SimpleCubeProgram.hx",135,0x50b28001)
HX_LOCAL_STACK_FRAME(_hx_pos_caffec7864cf5c0d_185_render,"SimpleCubeProgram","render",0xc74f5cc7,"SimpleCubeProgram.render","SimpleCubeProgram.hx",185,0x50b28001)

void SimpleCubeProgram_obj::__construct( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl){
            	HX_STACKFRAME(&_hx_pos_caffec7864cf5c0d_49_new)
HXLINE(  50)		::String vertexSource = HX_("#version 300 es\n\t\t\t\tlayout (location = 0) in vec3 aPos;\n\t\t\t\tlayout (location = 1) in vec3 aNormal;\n\t\t\t\tlayout (location = 2) in vec2 aTexCoords;\t\n\nout vec3 FragPos;\nout vec3 Normal;\nout vec2 TexCoords;\n\nuniform mat4 model;\nuniform mat4 view;\nuniform mat4 proj;\n\nvoid main()\n{\n    FragPos = vec3(model * vec4(aPos, 1.0));\n    Normal = mat3(transpose(inverse(model))) * aNormal;  \n    \n    gl_Position = proj * view * vec4(FragPos, 1.0);\n\tTexCoords = aTexCoords;\n}\n",c5,76,c1,e1);
HXLINE(  73)		::String fragmentSource = HX_("#version 300 es\n\t\t\t\tprecision mediump float;\nout vec4 FragColor;\n\nin vec3 Normal;  \nin vec3 FragPos;  \nin vec2 TexCoords;\n  \nuniform vec3 lightPos; \nuniform vec3 viewPos; \nuniform vec3 lightColor;\nuniform vec3 objectColor;\n\nstruct Material {\n    sampler2D diffuse;\n    sampler2D specular;\n    float     shininess;\n};  \n\nstruct Light {\n    vec3 position;\n  \n    vec3 ambient;\n    vec3 diffuse;\n    vec3 specular;\n};\n\nuniform Light light;  \nuniform Material material;\n\nvoid main()\n{\n    // ambient\n    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;\n  \t\n    // diffuse \n    vec3 norm = normalize(Normal);\n    vec3 lightDir = normalize(light.position - FragPos);\n    float diff = max(dot(norm, lightDir), 0.0);\n    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;  \n    \n    // specular\n    vec3 viewDir = normalize(viewPos - FragPos);\n    vec3 reflectDir = reflect(-lightDir, norm);  \n    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);\n    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;  \n        \n    vec3 result = ambient + diffuse + specular;\n    FragColor = vec4(result, 1.0);\n} \n",d6,60,72,21);
HXLINE( 125)		super::__construct(gl);
HXLINE( 126)		this->createGLSLProgram(vertexSource,fragmentSource);
HXLINE( 127)		this->getShaderVarLocations();
            	}

Dynamic SimpleCubeProgram_obj::__CreateEmpty() { return new SimpleCubeProgram_obj; }

void *SimpleCubeProgram_obj::_hx_vtable = 0;

Dynamic SimpleCubeProgram_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< SimpleCubeProgram_obj > _hx_result = new SimpleCubeProgram_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool SimpleCubeProgram_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x12dc3730) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x12dc3730;
	} else {
		return inClassId==(int)0x1ef5e01d;
	}
}

void SimpleCubeProgram_obj::getShaderVarLocations(){
            	HX_STACKFRAME(&_hx_pos_caffec7864cf5c0d_135_getShaderVarLocations)
HXLINE( 137)		this->_programVertexAttribute = this->_gl->getAttribLocation(this->_glProgram,HX_("aPos",b3,c7,5a,40));
HXLINE( 138)		this->_gl->enableVertexAttribArray(this->_programVertexAttribute);
HXLINE( 140)		this->_programNormalVecAttribute = this->_gl->getAttribLocation(this->_glProgram,HX_("aNormal",68,e5,9f,26));
HXLINE( 141)		this->_gl->enableVertexAttribArray(this->_programNormalVecAttribute);
HXLINE( 143)		this->_programTextureAttribute = this->_gl->getAttribLocation(this->_glProgram,HX_("aTexCoords",c4,a8,7d,1f));
HXLINE( 144)		this->_gl->enableVertexAttribArray(this->_programTextureAttribute);
HXLINE( 147)		this->_programModelUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("model",a9,23,58,0c));
HXLINE( 148)		this->_programViewUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("view",65,32,4f,4e));
HXLINE( 149)		this->_programProjectionUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("proj",9d,c7,5e,4a));
HXLINE( 152)		this->_programObjectColorUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("objectColor",24,8e,8b,b9));
HXLINE( 153)		this->_programLightColorUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("lightColor",ad,88,62,cb));
HXLINE( 156)		this->_programLightPosUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("lightPos",5e,2e,ee,8c));
HXLINE( 159)		this->_programMaterialDiffuseUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("material.diffuse",9b,be,6c,7a));
HXLINE( 160)		this->_programMaterialSpecularUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("material.specular",6a,8b,30,01));
HXLINE( 161)		this->_programMaterialShininessUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("material.shininess",ff,34,7f,64));
HXLINE( 164)		this->_programLightAmbientUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("light.ambient",80,70,6c,42));
HXLINE( 165)		this->_programLightDiffuseUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("light.diffuse",ca,39,6a,71));
HXLINE( 166)		this->_programLightSpecularUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("light.specular",5b,d9,fe,27));
HXLINE( 169)		this->_programViewPosUniform = this->_gl->getUniformLocation(this->_glProgram,HX_("viewPos",2f,b0,bb,9c));
            	}


HX_DEFINE_DYNAMIC_FUNC0(SimpleCubeProgram_obj,getShaderVarLocations,(void))

void SimpleCubeProgram_obj::render( ::Dynamic params){
            	HX_STACKFRAME(&_hx_pos_caffec7864cf5c0d_185_render)
HXLINE( 187)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::uniformMatrix4fv(this->_gl,this->_programViewUniform,false,( ( ::lime::utils::ArrayBufferView)(params->__Field(HX_("viewMatrix",86,36,15,fd),::hx::paccDynamic)) ));
HXLINE( 189)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::uniformMatrix4fv(this->_gl,this->_programProjectionUniform,false,( ( ::lime::utils::ArrayBufferView)(params->__Field(HX_("projectionMatrix",30,88,bb,d0),::hx::paccDynamic)) ));
HXLINE( 191)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::uniformMatrix4fv(this->_gl,this->_programModelUniform,false,( ( ::lime::utils::ArrayBufferView)(params->__Field(HX_("modelMatrix",ca,72,9c,b1),::hx::paccDynamic)) ));
HXLINE( 194)		this->_gl->uniform3f(this->_programObjectColorUniform,( (Float)( ::Dynamic(params->__Field(HX_("objectColor",24,8e,8b,b9),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic(params->__Field(HX_("objectColor",24,8e,8b,b9),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic(params->__Field(HX_("objectColor",24,8e,8b,b9),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 195)		this->_gl->uniform3f(this->_programLightColorUniform,( (Float)( ::Dynamic(params->__Field(HX_("lightColor",ad,88,62,cb),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic(params->__Field(HX_("lightColor",ad,88,62,cb),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic(params->__Field(HX_("lightColor",ad,88,62,cb),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 198)		this->_gl->uniform3f(this->_programLightPosUniform,( (Float)( ::Dynamic(params->__Field(HX_("lightPos",5e,2e,ee,8c),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic(params->__Field(HX_("lightPos",5e,2e,ee,8c),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic(params->__Field(HX_("lightPos",5e,2e,ee,8c),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 201)		this->_gl->uniform3f(this->_programMaterialSpecularUniform,( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("material",a7,5c,a5,f0),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("material",a7,5c,a5,f0),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("material",a7,5c,a5,f0),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 202)		this->_gl->uniform1f(this->_programMaterialShininessUniform,( (Float)( ::Dynamic(params->__Field(HX_("material",a7,5c,a5,f0),::hx::paccDynamic))->__Field(HX_("shininess",86,57,95,c6),::hx::paccDynamic)) ));
HXLINE( 205)		this->_gl->uniform3f(this->_programLightAmbientUniform,( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("ambient",18,98,81,09),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("ambient",18,98,81,09),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("ambient",18,98,81,09),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 206)		this->_gl->uniform3f(this->_programLightDiffuseUniform,( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("diffuse",62,61,7f,38),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("diffuse",62,61,7f,38),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("diffuse",62,61,7f,38),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 207)		this->_gl->uniform3f(this->_programLightSpecularUniform,( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic( ::Dynamic(params->__Field(HX_("light",d6,90,fc,74),::hx::paccDynamic))->__Field(HX_("specular",c3,56,6c,93),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 210)		this->_gl->uniform3f(this->_programViewPosUniform,( (Float)( ::Dynamic(params->__Field(HX_("viewPos",2f,b0,bb,9c),::hx::paccDynamic))->__GetItem(0)) ),( (Float)( ::Dynamic(params->__Field(HX_("viewPos",2f,b0,bb,9c),::hx::paccDynamic))->__GetItem(1)) ),( (Float)( ::Dynamic(params->__Field(HX_("viewPos",2f,b0,bb,9c),::hx::paccDynamic))->__GetItem(2)) ));
HXLINE( 213)		this->_gl->bindBuffer(this->_gl->ARRAY_BUFFER,( ( ::lime::graphics::opengl::GLObject)(params->__Field(HX_("vbo",c3,df,59,00),::hx::paccDynamic)) ));
HXLINE( 216)		this->_gl->activeTexture(this->_gl->TEXTURE0);
HXLINE( 217)		this->_gl->bindTexture(this->_gl->TEXTURE_2D,( ( ::lime::graphics::opengl::GLObject)(params->__Field(HX_("diffuseMap",5a,ea,94,3f),::hx::paccDynamic)) ));
HXLINE( 220)		this->_gl->activeTexture(this->_gl->TEXTURE1);
HXLINE( 221)		this->_gl->bindTexture(this->_gl->TEXTURE_2D,( ( ::lime::graphics::opengl::GLObject)(params->__Field(HX_("specularMap",99,c7,8c,b1),::hx::paccDynamic)) ));
HXLINE( 224)		int stride = 32;
HXLINE( 227)		{
HXLINE( 227)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this1 = this->_gl;
HXDLIN( 227)			int indx = this->_programVertexAttribute;
HXDLIN( 227)			int type = this->_gl->FLOAT;
HXDLIN( 227)			this1->vertexAttribPointer(indx,3,type,false,stride,::lime::utils::_DataPointer::DataPointer_Impl__obj::fromInt(0));
            		}
HXLINE( 228)		this->_gl->enableVertexAttribArray(0);
HXLINE( 231)		{
HXLINE( 231)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this2 = this->_gl;
HXDLIN( 231)			int indx1 = this->_programNormalVecAttribute;
HXDLIN( 231)			int type1 = this->_gl->FLOAT;
HXDLIN( 231)			this2->vertexAttribPointer(indx1,3,type1,false,stride,::lime::utils::_DataPointer::DataPointer_Impl__obj::fromInt(12));
            		}
HXLINE( 232)		this->_gl->enableVertexAttribArray(1);
HXLINE( 235)		{
HXLINE( 235)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this3 = this->_gl;
HXDLIN( 235)			int indx2 = this->_programTextureAttribute;
HXDLIN( 235)			int type2 = this->_gl->FLOAT;
HXDLIN( 235)			this3->vertexAttribPointer(indx2,2,type2,false,stride,::lime::utils::_DataPointer::DataPointer_Impl__obj::fromInt(24));
            		}
HXLINE( 236)		this->_gl->enableVertexAttribArray(2);
HXLINE( 239)		this->_gl->drawArrays(this->_gl->TRIANGLES,0,36);
            	}


HX_DEFINE_DYNAMIC_FUNC1(SimpleCubeProgram_obj,render,(void))


::hx::ObjectPtr< SimpleCubeProgram_obj > SimpleCubeProgram_obj::__new( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl) {
	::hx::ObjectPtr< SimpleCubeProgram_obj > __this = new SimpleCubeProgram_obj();
	__this->__construct(gl);
	return __this;
}

::hx::ObjectPtr< SimpleCubeProgram_obj > SimpleCubeProgram_obj::__alloc(::hx::Ctx *_hx_ctx, ::lime::_internal::backend::native::NativeOpenGLRenderContext gl) {
	SimpleCubeProgram_obj *__this = (SimpleCubeProgram_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SimpleCubeProgram_obj), true, "SimpleCubeProgram"));
	*(void **)__this = SimpleCubeProgram_obj::_hx_vtable;
	__this->__construct(gl);
	return __this;
}

SimpleCubeProgram_obj::SimpleCubeProgram_obj()
{
}

::hx::Val SimpleCubeProgram_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return ::hx::Val( render_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_programViewUniform") ) { return ::hx::Val( _programViewUniform ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_programModelUniform") ) { return ::hx::Val( _programModelUniform ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getShaderVarLocations") ) { return ::hx::Val( getShaderVarLocations_dyn() ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_programViewPosUniform") ) { return ::hx::Val( _programViewPosUniform ); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_programLightPosUniform") ) { return ::hx::Val( _programLightPosUniform ); }
		if (HX_FIELD_EQ(inName,"_programVertexAttribute") ) { return ::hx::Val( _programVertexAttribute ); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_programTextureAttribute") ) { return ::hx::Val( _programTextureAttribute ); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_programProjectionUniform") ) { return ::hx::Val( _programProjectionUniform ); }
		if (HX_FIELD_EQ(inName,"_programLightColorUniform") ) { return ::hx::Val( _programLightColorUniform ); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_programObjectColorUniform") ) { return ::hx::Val( _programObjectColorUniform ); }
		if (HX_FIELD_EQ(inName,"_programNormalVecAttribute") ) { return ::hx::Val( _programNormalVecAttribute ); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_programLightAmbientUniform") ) { return ::hx::Val( _programLightAmbientUniform ); }
		if (HX_FIELD_EQ(inName,"_programLightDiffuseUniform") ) { return ::hx::Val( _programLightDiffuseUniform ); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_programLightSpecularUniform") ) { return ::hx::Val( _programLightSpecularUniform ); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"_programMaterialDiffuseUniform") ) { return ::hx::Val( _programMaterialDiffuseUniform ); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_programMaterialSpecularUniform") ) { return ::hx::Val( _programMaterialSpecularUniform ); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_programMaterialShininessUniform") ) { return ::hx::Val( _programMaterialShininessUniform ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val SimpleCubeProgram_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"_programViewUniform") ) { _programViewUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_programModelUniform") ) { _programModelUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_programViewPosUniform") ) { _programViewPosUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_programLightPosUniform") ) { _programLightPosUniform=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_programVertexAttribute") ) { _programVertexAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_programTextureAttribute") ) { _programTextureAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_programProjectionUniform") ) { _programProjectionUniform=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_programLightColorUniform") ) { _programLightColorUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_programObjectColorUniform") ) { _programObjectColorUniform=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_programNormalVecAttribute") ) { _programNormalVecAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_programLightAmbientUniform") ) { _programLightAmbientUniform=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_programLightDiffuseUniform") ) { _programLightDiffuseUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_programLightSpecularUniform") ) { _programLightSpecularUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"_programMaterialDiffuseUniform") ) { _programMaterialDiffuseUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_programMaterialSpecularUniform") ) { _programMaterialSpecularUniform=inValue.Cast< int >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_programMaterialShininessUniform") ) { _programMaterialShininessUniform=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleCubeProgram_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_programViewUniform",4a,15,90,24));
	outFields->push(HX_("_programProjectionUniform",a0,e6,07,53));
	outFields->push(HX_("_programModelUniform",30,60,b1,c1));
	outFields->push(HX_("_programObjectColorUniform",d5,d4,9d,82));
	outFields->push(HX_("_programLightColorUniform",42,46,fa,98));
	outFields->push(HX_("_programLightPosUniform",f1,93,d2,a0));
	outFields->push(HX_("_programViewPosUniform",aa,03,1b,19));
	outFields->push(HX_("_programMaterialDiffuseUniform",de,42,2e,54));
	outFields->push(HX_("_programMaterialSpecularUniform",45,e4,1f,e8));
	outFields->push(HX_("_programMaterialShininessUniform",3a,ac,1c,af));
	outFields->push(HX_("_programLightAmbientUniform",6d,be,10,7d));
	outFields->push(HX_("_programLightDiffuseUniform",63,12,e3,fb));
	outFields->push(HX_("_programLightSpecularUniform",20,a9,a0,fe));
	outFields->push(HX_("_programTextureAttribute",e6,ad,35,0a));
	outFields->push(HX_("_programVertexAttribute",93,99,82,ec));
	outFields->push(HX_("_programNormalVecAttribute",54,8d,6c,85));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo SimpleCubeProgram_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programViewUniform),HX_("_programViewUniform",4a,15,90,24)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programProjectionUniform),HX_("_programProjectionUniform",a0,e6,07,53)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programModelUniform),HX_("_programModelUniform",30,60,b1,c1)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programObjectColorUniform),HX_("_programObjectColorUniform",d5,d4,9d,82)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programLightColorUniform),HX_("_programLightColorUniform",42,46,fa,98)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programLightPosUniform),HX_("_programLightPosUniform",f1,93,d2,a0)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programViewPosUniform),HX_("_programViewPosUniform",aa,03,1b,19)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programMaterialDiffuseUniform),HX_("_programMaterialDiffuseUniform",de,42,2e,54)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programMaterialSpecularUniform),HX_("_programMaterialSpecularUniform",45,e4,1f,e8)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programMaterialShininessUniform),HX_("_programMaterialShininessUniform",3a,ac,1c,af)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programLightAmbientUniform),HX_("_programLightAmbientUniform",6d,be,10,7d)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programLightDiffuseUniform),HX_("_programLightDiffuseUniform",63,12,e3,fb)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programLightSpecularUniform),HX_("_programLightSpecularUniform",20,a9,a0,fe)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programTextureAttribute),HX_("_programTextureAttribute",e6,ad,35,0a)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programVertexAttribute),HX_("_programVertexAttribute",93,99,82,ec)},
	{::hx::fsInt,(int)offsetof(SimpleCubeProgram_obj,_programNormalVecAttribute),HX_("_programNormalVecAttribute",54,8d,6c,85)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *SimpleCubeProgram_obj_sStaticStorageInfo = 0;
#endif

static ::String SimpleCubeProgram_obj_sMemberFields[] = {
	HX_("_programViewUniform",4a,15,90,24),
	HX_("_programProjectionUniform",a0,e6,07,53),
	HX_("_programModelUniform",30,60,b1,c1),
	HX_("_programObjectColorUniform",d5,d4,9d,82),
	HX_("_programLightColorUniform",42,46,fa,98),
	HX_("_programLightPosUniform",f1,93,d2,a0),
	HX_("_programViewPosUniform",aa,03,1b,19),
	HX_("_programMaterialDiffuseUniform",de,42,2e,54),
	HX_("_programMaterialSpecularUniform",45,e4,1f,e8),
	HX_("_programMaterialShininessUniform",3a,ac,1c,af),
	HX_("_programLightAmbientUniform",6d,be,10,7d),
	HX_("_programLightDiffuseUniform",63,12,e3,fb),
	HX_("_programLightSpecularUniform",20,a9,a0,fe),
	HX_("_programTextureAttribute",e6,ad,35,0a),
	HX_("_programVertexAttribute",93,99,82,ec),
	HX_("_programNormalVecAttribute",54,8d,6c,85),
	HX_("getShaderVarLocations",b2,9d,9b,44),
	HX_("render",56,6b,29,05),
	::String(null()) };

::hx::Class SimpleCubeProgram_obj::__mClass;

void SimpleCubeProgram_obj::__register()
{
	SimpleCubeProgram_obj _hx_dummy;
	SimpleCubeProgram_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("SimpleCubeProgram",dd,2a,5b,cf);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(SimpleCubeProgram_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< SimpleCubeProgram_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = SimpleCubeProgram_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = SimpleCubeProgram_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

