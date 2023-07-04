fn main() {

  println!("cargo:rustc-link-search=all={}", "../cppdemolib/cmake-build-debug");
  println!(r"cargo:rustc-link-arg=-Wl,-rpath,../cppdemolib/cmake-build-debug");
  println!("cargo:rustc-link-lib=dylib=cppdemolib");
  
  tauri_build::build()
}
