// Prevents additional console window on Windows in release, DO NOT REMOVE!!
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

extern "C" {
    pub fn add(a: ::std::os::raw::c_int, b: ::std::os::raw::c_int) -> ::std::os::raw::c_int;
}

extern "C" {
    pub fn demolib_get_version_str() -> *const ::std::os::raw::c_char;
}

pub fn add_wrapper(a: i32, b: i32) -> i32 {
    unsafe { add(a, b) }
}

pub fn demolib_get_version_str_wrapper() -> String {
    let version = unsafe {
        std::ffi::CStr::from_ptr(demolib_get_version_str())
    };
    let version_str= version.to_str().unwrap().to_string();
    version_str
}

#[tauri::command]
fn get_api_version() -> String {
    format!("{}", demolib_get_version_str_wrapper())
}


fn add_str(a: &str, b: &str) -> i32 {
    let a_int = a.parse::<i32>().unwrap_or(0);
    let b_int = b.parse::<i32>().unwrap_or(0);
    add_wrapper(a_int, b_int)
}

// Learn more about Tauri commands at https://tauri.app/v1/guides/features/command
#[tauri::command]
fn greet(a: &str, b: &str) -> String {
    format!("The result: {}", add_str(a, b))
}


fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![greet, get_api_version])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
