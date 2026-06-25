{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];

      perSystem = f: nixpkgs.lib.genAttrs systems (system: f (import nixpkgs { inherit system; }));
    in
    {
      packages = perSystem (pkgs: {
        default = pkgs.callPackage ./default.nix { };
      });
      devShells = perSystem (pkgs: {
        default = pkgs.callPackage ./shell.nix { };
      });
    };
}
