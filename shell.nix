{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  name = "corganizer";
  buildInputs = with pkgs; [
    gnumake
  ];
}
