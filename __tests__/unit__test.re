open Jest;
open Expect;
open DiffieHellman;

// let p = "98b5884ff6a2db0e2c3e331ecfe08a1bc87252750f7285dc61a4faaca14f33121267af70e4181eda3de783ff41c82101dfab5128408bd3406f7e290b685d771b";
// let g = "02";
let enc: prime_encoding = `hex;
let do_logging = false;

let try_me = (name, inst) => {
  describe(
    name,
    () => {
      test("generateKeys", () => {
        let r = inst->generateKeys(enc);
        if (do_logging) {
          {j|generateKeys: $(r)|j}->Js.Console.log;
        };
        r |> expect |> not_ |> toEqual("");
      });

      test("getGenerator", () => {
        let g = inst->getGenerator(enc);
        if (do_logging) {
          {j|getGenerator: $(g)|j}->Js.Console.log;
        };
        g |> expect |> not_ |> toEqual("");
      });

      test("getPrime", () => {
        let p = inst->getPrime(enc);
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
        let p = inst->getPublicKey(enc);
        if (do_logging) {
          {j|Public A: $(p)|j}->Js.Console.log;
        };
        p |> expect |> not_ |> toEqual("");
      });
    },
  );
};

let a = createDiffieHellman1(~prime_length=512);
let b =
  createDiffieHellman4(
    ~prime=a->getPrime(enc),
    ~prime_encoding=enc,
    ~generator=a->getGenerator(enc),
    ~generator_encoding=enc,
  );

let instances = [|
  ("createDiffieHellman1", a),
  ("createDiffieHellman4", b),
|];

instances->Belt.Array.forEach(((n, i)) => try_me(n, i));

let sa = ref("");
let sb = ref("");

describe("computeSecret", () => {
  test("A", () => {
    let r = a->computeSecret(b->getPublicKey(enc), enc, enc);
    sa := r;
    if (do_logging) {
      {j|Secret A: $(r)|j}->Js.Console.log;
    };
    r |> expect |> not_ |> toEqual("");
  });

  test("B", () => {
    let r = b->computeSecret(a->getPublicKey(enc), enc, enc);
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