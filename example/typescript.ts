import dh from 'diffie-hellman'
import assert from 'assert'

const alice = dh.createDiffieHellman(2048)
const aliceKey = alice.generateKeys('hex')

// Generate Bob's keys...
const bob = dh.createDiffieHellman(
  alice.getPrime('hex'),
  'hex',
  alice.getGenerator('hex'),
  'hex'
)
const bobKey = bob.generateKeys('hex')

const aliceSecret = alice.computeSecret(bobKey, 'hex')
const bobSecret = bob.computeSecret(aliceKey, 'hex')

console.log(assert(aliceSecret === bobSecret))
