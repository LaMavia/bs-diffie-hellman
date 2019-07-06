type diffieHellman;
type generator = string;

type prime_encoding = [ | `hex | `base64 | `latin1];

let prime_encodingToJs = enc =>
  switch (enc) {
  | `hex => "hex"
  | `latin1 => "latin1"
  | `base64 => "base64"
  };

let prime_encodingToJs_rev = enc =>
  switch (enc) {
  // ReasonML for some reason switches `hex -> `latin1 and vice versa in some functions
  | `hex => "hex"
  | `latin1 => "hex"
  | `base64 => "hex"
  };

// -------- Aliases for self-doc -------- //
type key_encoding = prime_encoding;
type input_encoding = prime_encoding;
type output_encoding = prime_encoding;
type generator_encoding = prime_encoding;
type other_public = string;
type key = string;

[@bs.module "diffie-hellman"]
external createDiffieHellman1: int => diffieHellman = "createDiffieHellman";

let createDiffieHellman1 = (~prime_length: int) =>
  createDiffieHellman1(prime_length);

[@bs.module "diffie-hellman"]
external createDiffieHellman2: (string, string) => diffieHellman =
  "createDiffieHellman";

[@bs.module "diffie-hellman"]
external createDiffieHellman4:
  (string, string, generator, string) => diffieHellman =
  "createDiffieHellman";

let createDiffieHellman4 =
    (
      ~prime: string,
      ~prime_encoding: prime_encoding,
      ~generator: generator,
      ~generator_encoding: generator_encoding,
    ) => {
  createDiffieHellman4(
    prime,
    prime_encoding->prime_encodingToJs,
    generator,
    generator_encoding->prime_encodingToJs,
  );
};

// -------- Getters -------- //
[@bs.send]
external getGenerator: (diffieHellman, string) => string = "getGenerator";

let getGenerator = (instance, prime_encoding) =>
  instance->getGenerator(prime_encoding->prime_encodingToJs);

[@bs.send] external getPrime: (diffieHellman, string) => string = "getPrime";

let getPrime = (inst, prime_encoding) =>
  inst->getPrime(prime_encoding->prime_encodingToJs);

[@bs.send]
external generateKeys: (diffieHellman, string) => string = "generateKeys";

let generateKeys = (inst, prime_encoding) => {
  let enc = prime_encoding->prime_encodingToJs;
  inst->generateKeys(enc);
};

[@bs.send]
external getPrivateKey: (diffieHellman, string) => string = "getPrivateKey";

let getPrivateKey = (inst, prime_encoding) =>
  inst->getPrivateKey(prime_encoding->prime_encodingToJs);

[@bs.send]
external getPublicKey: (diffieHellman, string) => string = "getPublicKey";

let getPublicKey = (inst, prime_encoding) =>
  inst->getPublicKey(prime_encoding->prime_encodingToJs);

// -------- /Getters -------- //

// -------- Setters -------- //

[@bs.send]
external setPrivateKey: (diffieHellman, key, prime_encoding) => unit =
  "setPrivateKey";

[@bs.send]
external setPublicKey: (diffieHellman, key, prime_encoding) => unit =
  "setPublicKey";

// -------- /Setters -------- //

[@bs.send]
external computeSecret: (diffieHellman, other_public, string, string) => string =
  "computeSecret";

let computeSecret = (inst, other_public, input_encoding, output_encoding) =>
  computeSecret(
    inst,
    other_public,
    input_encoding |> prime_encodingToJs,
    output_encoding |> prime_encodingToJs,
  );