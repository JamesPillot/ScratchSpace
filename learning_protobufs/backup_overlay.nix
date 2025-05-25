{pkgs, fetchurl}:

self: super: {
    "numpy" = super.buildPythonPackage rec {
        pname = "numpy";
        version = "1.26.4";
        src = fetchurl {
            url = "https://files.pythonhosted.org/packages/65/6e/09db70a523a96d25e115e71cc56a6f9031e7b8cd166c1ac8438307c14058/numpy-1.26.4.tar.gz";
            sha256 = "2a02aba9ed12e4ac4eb3ea9421c420301a0c6460d9830d74a9df87efa4912010";
        };

        buildInputs = [];
        checkInputs = [];
        doCheck = false;
        nativeBuildInputs = [];
        propagatedBuildInputs = [];
    };

    "pandas" = super.buildPythonPackage rec {
        pname = "pandas";
        version = "1.2.0";
        src = fetchurl {
            url = "https://files.pythonhosted.org/packages/75/bc/abf2e8cc6a9d918008774b958613cfdbd3a8c135cffb0757f78fabd8268f/pandas-1.2.0.tar.gz";
            sha256 = "e03386615b970b8b41da6a68afe717626741bb2431cec993640685614c0680e4";
        };

        buildInputs = [];
        checkInputs = [];
        doCheck = false;
        nativeBuildInputs = [];
        propagatedBuildInputs = [];
    };

    "scipy" = super.buildPythonPackage rec {
    pname = "scipy";
    version = "1.5.4";
    src = fetchurl {
      url = "https://files.pythonhosted.org/packages/aa/d5/dd06fe0e274e579e1dff21aa021219c039df40e39709fabe559faed072a5/scipy-1.5.4.tar.gz";
      sha256 = "0nqmzadgkh8qihibvif9cgyhnmhp7ypl1pwfsgjn5pl9arg3siaa";
    };
    format = "setuptools";
    doCheck = false;
    buildInputs = [];
    checkInputs = [];
    nativeBuildInputs = [];
    propagatedBuildInputs = [
      self."numpy"
    ];
  };
}
