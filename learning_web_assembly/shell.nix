{ pkgs ? import (builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/refs/tags/23.05.tar.gz";
    sha256 = "10wn0l08j9lgqcw8177nh2ljrnxdrpri7bp0g7nvrsn9rkawvlbf";
  }) {}
}:
pkgs.mkShell {
  EM_CONFIG = pkgs.writeText ".emscripten" ''
    EMSCRIPTEN_ROOT = '${pkgs.emscripten}/share/emscripten'
    LLVM_ROOT = '${pkgs.emscripten.llvmEnv}/bin'
    BINARYEN_ROOT = '${pkgs.binaryen}'
    NODE_JS = '${pkgs.nodejs-18_x}/bin/node'
    CACHE = '${toString ./.cache}'
  '';
  buildInputs = [
    pkgs.emscripten
  ];
}