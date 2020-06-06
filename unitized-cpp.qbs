import qbs 1.0

Project {
    name: "unitized"

    DynamicLibrary {
        name: "unitized"

        Depends { name: "cpp" }
        Depends { name: "bundle" }
//        property string rpath: buildDirectory

        Export {
            Depends { name: "cpp" }
            cpp.includePaths: ["src"]
//            cpp.rpaths: [product.rpath]
            cpp.cxxFlags: {
                if(qbs.toolchain.contains("gcc")) {
                    return ["-Wno-attributes"] //Ignore-around to a g++ bug, https://gcc.gnu.org/bugzilla/show_bug.cgi?id=43407
                }
                return []
            }
        }

        Group {
            fileTagsFilter: ["dynamiclibrary"]
            condition: qbs.buildVariant == "release"
            qbs.install: qbs.targetOS.contains("windows")
        }

        Group {
            fileTagsFilter: ["bundle.content"]
            qbs.install: bundle.isBundle
            qbs.installSourceBase: product.buildDirectory
            qbs.installDir: "lib"
            qbs.installPrefix: ""
        }

        cpp.includePaths: ["src"]
//        cpp.rpaths: [Qt.core.libPath]
        cpp.cxxLanguageVersion: "c++11"
        cpp.treatWarningsAsErrors: false

        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: ["UNITIZED_LIB"]
        }

        Properties {
            condition: qbs.targetOS.contains("macos")
            cpp.sonamePrefix: qbs.installRoot + "/lib"
            cpp.cxxFlags: {
                var flags = [];

                if(qbs.buildVariant == "debug") {
                    flags.push("-fsanitize=address");
                    flags.push("-fno-omit-frame-pointer")
                }

                return flags;
            }

            cpp.driverFlags: {
                var flags = [];
                if(qbs.buildVariant == "debug") {
                    flags.push("-fsanitize=address")
                }
                return flags;
            }
        }

        Properties {
            condition: qbs.targetOS.contains("linux")
            cpp.cxxFlags: {
                var flags = []
                if(qbs.toolchain.contains("gcc")) {
                    flags.push("-Wno-attributes") //Ignore-around to a g++ bug, https://gcc.gnu.org/bugzilla/show_bug.cgi?id=43407
                }
                return flags
            }
        }

        files: [
            "src/*.cpp",
            "src/*.h",
        ]
    }

    CppApplication {
        name: "unitized-test"
        consoleApplication: true
        type: "application"

        Depends { name: "cpp" }
        Depends { name: "unitized" }

        cpp.includePaths: ["src", "lib"]
        cpp.cxxLanguageVersion: "c++11"
//        cpp.treatWarningsAsErrors: true

        files: [
            "test/*.cpp",
            "test/*.h",
        ]
    }
}
