import dh from 'diffie-hellman'

const alice = dh.createDiffieHellman(512)
const aliceKey = alice.generateKeys('hex')

// Generate Bob's keys...
const bob = dh.createDiffieHellman(
  alice.getPrime('hex'),
  'hex',
  alice.getGenerator('hex'),
  'hex'
)
const bobKey = bob.generateKeys('hex')

// Exchange and generate the secret...
const aliceSecret = alice.computeSecret(bobKey, 'hex')
const bobSecret = bob.computeSecret(aliceKey, 'hex')

const p = alice.getPrime('hex')
const g = alice.getGenerator('hex')

const a = aliceKey
const b = bobKey

console.dir([p, g, a, b], { colors: true })
