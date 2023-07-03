fn main() {

  println!("cargo:rustc-link-search=all={}", r"E:\projects\forgithub\tauri-cpp-demo\cppdemolib\cmake-build-debug");
  println!(r"cargo:rustc-link-arg=-Wl,-rpath,E:\projects\forgithub\tauri-cpp-demo\cppdemolib\cmake-build-debug");
  println!("cargo:rustc-link-lib=dylib=cppdemolib");
  
  tauri_build::build()
}
