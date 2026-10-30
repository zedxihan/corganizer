{
  lib,
  stdenv,
  fetchFromGitHub,
  nix-update-script,
}:
stdenv.mkDerivation (finalAttrs: {
  pname = "corganizer";
  version = "2.0.0";
  __structuredAttrs = true;
  strictDeps = true;

  src = fetchFromGitHub {
    owner = "zedxihan";
    repo = "corganizer";
    tag = "v${finalAttrs.version}";
    hash = lib.fakeHash;
  };

  installPhase = ''
    runHook preInstall

    install -Dm755 corganizer $out/bin/corganizer

    runHook postInstall
  '';

  passthru.updateScript = nix-update-script { };

  meta = {
    description = "A blazing fast CLI tool to automatically organize your cluttered files";
    homepage = "https://github.com/zedxihan/corganizer";
    changelog = "https://github.com/zedxihan/corganizer/releases/tag/${finalAttrs.src.tag}";
    license = lib.licenses.mit;
    mainProgram = "corganizer";
    platforms = lib.platforms.linux;
  };
})
