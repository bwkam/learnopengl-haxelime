package;

import haxe.io.Bytes;
import lime.utils.AssetBundle;
import lime.utils.AssetLibrary;
import lime.utils.AssetManifest;
import lime.utils.Assets;

#if sys
import sys.FileSystem;
#end

#if disable_preloader_assets
@:dox(hide) class ManifestResources {
	public static var preloadLibraries:Array<Dynamic>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;

	public static function init (config:Dynamic):Void {
		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();
	}
}
#else
@:access(lime.utils.Assets)


@:keep @:dox(hide) class ManifestResources {


	public static var preloadLibraries:Array<AssetLibrary>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;


	public static function init (config:Dynamic):Void {

		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();

		rootPath = null;

		if (config != null && Reflect.hasField (config, "rootPath")) {

			rootPath = Reflect.field (config, "rootPath");

			if(!StringTools.endsWith (rootPath, "/")) {

				rootPath += "/";

			}

		}

		if (rootPath == null) {

			#if (ios || tvos || emscripten)
			rootPath = "assets/";
			#elseif android
			rootPath = "";
			#elseif console
			rootPath = lime.system.System.applicationDirectory;
			#else
			rootPath = "./";
			#end

		}

		#if (openfl && !flash && !display)
		
		#end

		var data, manifest, library, bundle;

		#if kha

		null
		library = AssetLibrary.fromManifest (manifest);
		Assets.registerLibrary ("null", library);

		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("null");

		#else

		data = '{"name":null,"assets":"aoy4:pathy24:assets%2Fawesomeface.pngy4:sizei59277y4:typey5:IMAGEy2:idR1y7:preloadtgoR0y21:assets%2Fspecular.pngR2i144081R3R4R5R7R6tgoR0y22:assets%2Fcontainer.jpgR2i184939R3R4R5R8R6tgoR0y28:assets%2Fshaders%2Fcube.vertR2i185R3y4:TEXTR5R9R6tgoR0y28:assets%2Fshaders%2Fcube.fragR2i120R3R10R5R11R6tgoR0y24:assets%2Fhack_ascii.jsonR2i1231R3R10R5R12R6tgoR0y23:assets%2Fhack_ascii.pngR2i12425R3R4R5R13R6tgoR0y23:assets%2Fcontainer2.pngR2i467893R3R4R5R14R6tgh","rootPath":null,"version":2,"libraryArgs":[],"libraryType":null}';
		manifest = AssetManifest.parse (data, rootPath);
		library = AssetLibrary.fromManifest (manifest);
		Assets.registerLibrary ("default", library);
		

		library = Assets.getLibrary ("default");
		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("default");
		

		#end

	}


}


#if kha

null

#else

#if !display
#if flash

@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_awesomeface_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_specular_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_container_jpg extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_cube_vert extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_shaders_cube_frag extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_hack_ascii_json extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_hack_ascii_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_container2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__manifest_default_json extends null { }


#elseif (desktop || cpp)

@:keep @:image("Assets/awesomeface.png") @:noCompletion #if display private #end class __ASSET__assets_awesomeface_png extends lime.graphics.Image {}
@:keep @:image("Assets/specular.png") @:noCompletion #if display private #end class __ASSET__assets_specular_png extends lime.graphics.Image {}
@:keep @:image("Assets/container.jpg") @:noCompletion #if display private #end class __ASSET__assets_container_jpg extends lime.graphics.Image {}
@:keep @:file("Assets/shaders/cube.vert") @:noCompletion #if display private #end class __ASSET__assets_shaders_cube_vert extends haxe.io.Bytes {}
@:keep @:file("Assets/shaders/cube.frag") @:noCompletion #if display private #end class __ASSET__assets_shaders_cube_frag extends haxe.io.Bytes {}
@:keep @:file("Assets/hack_ascii.json") @:noCompletion #if display private #end class __ASSET__assets_hack_ascii_json extends haxe.io.Bytes {}
@:keep @:image("Assets/hack_ascii.png") @:noCompletion #if display private #end class __ASSET__assets_hack_ascii_png extends lime.graphics.Image {}
@:keep @:image("Assets/container2.png") @:noCompletion #if display private #end class __ASSET__assets_container2_png extends lime.graphics.Image {}
@:keep @:file("") @:noCompletion #if display private #end class __ASSET__manifest_default_json extends haxe.io.Bytes {}



#else



#end

#if (openfl && !flash)

#if html5

#else

#end

#end
#end

#end

#end