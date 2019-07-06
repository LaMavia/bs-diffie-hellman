open DiffieHellman;
let alice = createDiffieHellman1(~prime_length=2048);
let aliceKey = alice->generateKeys(`hex);

let bob =
  createDiffieHellman4(
    ~prime=alice->getPrime(`hex),
    ~prime_encoding=`hex,
    ~generator=alice->getGenerator(`hex),
    ~generator_encoding=`hex,
  );
let bobKey = bob->generateKeys(`hex);

let aliceSecret = alice->computeSecret(bobKey, `hex, `hex);
let bobSecret = bob->computeSecret(aliceKey, `hex, `hex);

Js.Console.log(assert(aliceSecret === bobSecret));