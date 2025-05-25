final: prev: {
  python310 = prev.python310.override {
    packageOverrides = pyFinal: pyPrev: {
      numpy = pyPrev.numpy.overridePythonAttrs (old: {
        version = "1.26.4";
        src = prev.fetchPypi {
          pname = "numpy";
          version = "1.26.4";
          sha256 = "2a02aba9ed12e4ac4eb3ea9421c420301a0c6460d9830d74a9df87efa4912010";
        };
      });

      pandas = pyPrev.pandas.overridePythonAttrs (old: {
        version = "2.2.1";
        src = prev.fetchPypi {
          pname = "pandas";
          version = "2.2.1";
          sha256 = "0ab90f87093c13f3e8fa45b48ba9f39181046e8f3317d3aadb2fffbb1b978572";
        };
      });
    };
  };
}