# bs-diffie-hellman

Binding of [diffie-hellman](https://github.com/crypto-browserify/diffie-hellman) for ReasonML.

## installation
Install the npm package
```shell
$ npm i bs-diffie-hellman
```
Add it to the dependencies in your `bsconfig.json`
```json 
"bs-dependencies": ["bs-diffie-hellman"]
```
Don't forget to build your app
```shell
$ bsb -make-world
```
## Design decisions
1. string enums -> polymorphic variants
1. labeled arguments in constructors

## Example
In the [example](https://github.com/DerivedMate/bs-diffie-hellman/tree/master/example) folder you can find an example in ReasonML, which practically **directly translates to typescript / javascript** :ok_hand: (example from [node docs](https://nodejs.org/api/crypto.html#crypto_class_diffiehellman))

## Contribution
Any contribution is welcome. Especially because I'm still learning Reason and I might have missed some good practises :sweat_smile:
Thank you in advance :wink:
