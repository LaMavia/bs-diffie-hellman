open Jest;
open Expect;
open DiffieHellman;

// let p = "98b5884ff6a2db0e2c3e331ecfe08a1bc87252750f7285dc61a4faaca14f33121267af70e4181eda3de783ff41c82101dfab5128408bd3406f7e290b685d771b";
// let g = "02";
let enc: prime_encoding = `hex;
let do_logging = false;

let try_me = (name, inst) => {
  test("generateKeys", () => {
    let r = inst -> generateKeys(enc);
    if (do_logging) {
      {j|generateKeys: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getGenerator", () => {
    let g = inst -> getGenerator(enc);
    if (do_logging) {
      {j|getGenerator: $(g)|j}->Js.Console.log;
    };
    g |> expect |> not_ |> toEqual("");
  });

  test("getPrime", () => {
    let p = inst -> getPrime(enc)
    if (do_logging) {
      {j|getPrime: $(p)|j}->Js.Console.log;
    };
    p |> expect |> not_ |> toEqual("");
  });

  test("getPrivateKey", () => {
    let r = inst->getPrivateKey(enc);

    if (do_logging) {
      {j|getPrivateKey: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getPublicKey", () => {
    let p = inst -> getPublicKey(enc);
    if (do_logging) {
      {j|Public A: $(p)|j}->Js.Console.log;
    };
    p |> expect |> not_ |> toEqual("");
  });
}

// -------- createDiffieHellman1 -------- //
let a = createDiffieHellman1(~prime_length=512);
let inst = a;
let p = a->getPrime(enc);
let g = a->getGenerator(enc);
let ka = inst->generateKeys(enc);
let public_a = inst->getPublicKey(enc);

describe("DiffieHellman1", () => {
  test("generateKeys", () => {
    if (do_logging) {
      {j|generateKeys: $(ka)|j}->Js.Console.log;
    };
    ka |> expect |> not_ |> toEqual("");
  });

  test("getGenerator", () => {
    if (do_logging) {
      {j|getGenerator: $(g)|j}->Js.Console.log;
    };
    g |> expect |> not_ |> toEqual("");
  });

  test("getPrime", () => {
    if (do_logging) {
      {j|getPrime: $(p)|j}->Js.Console.log;
    };
    p |> expect |> not_ |> toEqual("");
  });

  test("getPrivateKey", () => {
    let r = inst->getPrivateKey(enc);

    if (do_logging) {
      {j|getPrivateKey: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getPublicKey", () => {
    if (do_logging) {
      {j|Public A: $(public_a)|j}->Js.Console.log;
    };
    public_a |> expect |> not_ |> toEqual("");
  });
});
//
//
//
// -------- createDiffieHellman4 -------- //

let b =
  createDiffieHellman4(
    ~prime=p,
    ~prime_encoding=enc,
    ~generator=g,
    ~generator_encoding=enc,
  );
let inst = b;
let kb = inst->generateKeys(enc);
let public_b = inst->getPublicKey(enc);
describe("DiffieHellman4", () => {
  test("generateKeys", () => {
    if (do_logging) {
      {j|generateKeys: $(kb)|j}->Js.Console.log;
    };
    kb |> expect |> not_ |> toEqual("");
  });
  test("getGenerator", () => {
    let r = inst->getGenerator(enc);

    if (do_logging) {
      {j|getGenerator: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getPrime", () => {
    let r = inst->getPrime(enc);

    if (do_logging) {
      {j|getPrime: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getPrivateKey", () => {
    let r = inst->getPrivateKey(enc);

    if (do_logging) {
      {j|getPrivateKey: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("getPublicKey", () => {
    if (do_logging) {
      {j|getPublicKey: $(public_b)|j}->Js.Console.log;
    };
    public_b |> expect |> not_ |> toEqual("");
  });
});

let sa = ref("");
let sb = ref("");

describe("computeSecret", () => {
  test("A", () => {
    let r = a->computeSecret(public_b, enc, enc);
    sa := r;
    if (do_logging) {
      {j|Secret A: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("B", () => {
    let r = b->computeSecret(public_a, enc, enc);
    sb := r;
    if (do_logging) {
      {j|Secret B: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("Equality", () =>
    sa |> expect |> toEqual(sb)
  );
});