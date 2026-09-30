
set_project("xvt")
set_version("0.0.0")
set_xmakever("3.1.1")




add_rules("mode.debug", "mode.release")
set_languages("cxx26")
set_toolchains("clang")
set_policy("build.c++.modules.gcc.fallbackscanner", true)




local packages =
{
    "raylib"
}

add_requires(packages)




set_warnings("all", "extra", "pedantic", "error")

add_cxxflags(
    "-Wshadow",
    "-Wconversion",
    "-Wformat=2",
    "-Wcast-align",
    "-Wimplicit-fallthrough",
    "-fno-exceptions",
    "-fno-rtti",
    "-Wno-c23-extensions",
    "-Wno-error=deprecated-declarations",
    {force = true}
)

if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
    set_strip("none")

    add_cxxflags(
        "-O0",
        "-g3",
        "-fno-omit-frame-pointer",
        { force = true }
    )
elseif is_mode("release") then
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")

    set_policy("build.optimization.lto", true)

    add_cxxflags(
        "-O3",
        "-march=native",
        "-DNDEBUG",
        { force = true }
    )
end




target("xvt")
    set_default(true)
    set_kind("static")

    add_files("src/**.cppm")


target("example-1")
    set_default(true)
    set_kind("binary")
    add_deps("xvt")

    add_files("examples/example-1/**.cpp")
    add_files("examples/example-1/**.cppm")

    add_headerfiles("examples/example-1/**.h")
    add_headerfiles("examples/example-1/**.hpp")

    add_packages(packages)



