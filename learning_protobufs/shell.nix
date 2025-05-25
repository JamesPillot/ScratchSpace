let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-24.05";
  
  # Import the overlay from a separate file
  pythonOverlay = import ./overlay.nix;
  
  pkgs = import nixpkgs { 
    config = {}; 
    overlays = [ pythonOverlay ]; 
  };
in

pkgs.mkShell {
  packages = with pkgs; [
    (python310.withPackages (ps: [
      ps.numpy
      ps.pandas
    ]))
  ];
}