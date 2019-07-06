type diffieHellman;
type generator = string;

type prime_encoding = [ | `hex | `base64 | `latin1];

let prime_encoding_to_js = enc =>
  switch (enc) {
  | `hex => "hex"
  | `latin1 => "latin1"
  | `base64 => "base64"
  };

// -------- Aliases for self-doc -------- //
type input_encoding = prime_encoding;
type output_encoding = prime_encoding;
type generator_encoding = prime_encoding;
type key_encoding = prime_encoding;
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
    prime_encoding->prime_encoding_to_js,
    generator,
    generator_encoding->prime_encoding_to_js,
  );
};

// -------- Getters -------- //
[@bs.send]
external getGenerator: (diffieHellman, string) => string = "getGenerator";

let getGenerator = (instance, prime_encoding) =>
  instance->getGenerator(prime_encoding->prime_encoding_to_js);

[@bs.send] external getPrime: (diffieHellman, string) => string = "getPrime";

let getPrime = (inst, prime_encoding) =>
  inst->getPrime(prime_encoding->prime_encoding_to_js);

[@bs.send]
external generateKeys: (diffieHellman, string) => string = "generateKeys";

let generateKeys = (inst, prime_encoding) => {
  let enc = prime_encoding->prime_encoding_to_js;
  inst->generateKeys(enc);
};

[@bs.send]
external getPrivateKey: (diffieHellman, string) => string = "getPrivateKey";

let getPrivateKey = (inst, prime_encoding) =>
  inst->getPrivateKey(prime_encoding->prime_encoding_to_js);

[@bs.send]
external getPublicKey: (diffieHellman, string) => string = "getPublicKey";

let getPublicKey = (inst, prime_encoding) =>
  inst->getPublicKey(prime_encoding->prime_encoding_to_js);

// -------- /Getters -------- //

// -------- Setters -------- //

[@bs.send]
external setPrivateKey: (diffieHellman, key, string) => unit = "setPrivateKey";

let setPrivateKey = (inst, key, key_encoding) =>
  setPrivateKey(inst, key, key_encoding->prime_encoding_to_js);

[@bs.send]
external setPublicKey: (diffieHellman, key, string) => unit = "setPublicKey";

let setPublicKey = (inst, key, key_encoding) =>
  setPublicKey(inst, key, key_encoding->prime_encoding_to_js);

// -------- /Setters -------- //

[@bs.send]
external computeSecret: (diffieHellman, other_public, string, string) => string =
  "computeSecret";

let computeSecret = (inst, other_public, input_encoding, output_encoding) =>
  computeSecret(
    inst,
    other_public,
    input_encoding |> prime_encoding_to_js,
    output_encoding |> prime_encoding_to_js,
  );