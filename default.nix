{
  lib,
  stdenv,
  fetchFromGitHub,
  nix-update-script,
}:
stdenv.mkDerivation (finalAttrs: {
  pname = "corganizer";
  version = "1.0.0";
  __structuredAttrs = true;
  strictDeps = true;

  src = fetchFromGitHub {
    owner = "zedxihan";
    repo = "corganizer";
    tag = "v${finalAttrs.version}";
    hash = "sha256-7ug66i+lGGy8N82EFyzUOUz0aYUftd7Ulx9z0OFb4Bs=";
  };

  installPhase = ''
    runHook preInstall

    install -Dm755 corganizer $out/bin/corganizer

    runHook postInstall
  '';

  passthru.updateScript = nix-update-script { };

  meta = {
    description = "A blazing fast, memory-safe CLI tool to automatically organize your cluttered files";
    homepage = "https://github.com/zedxihan/corganizer";
    changelog = "https://github.com/zedxihan/corganizer/releases/tag/${finalAttrs.src.tag}";
    license = lib.licenses.mit;
    mainProgram = "corganizer";
    platforms = lib.platforms.all;
  };
})
