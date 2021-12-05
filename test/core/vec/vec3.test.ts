import { Vec3 } from '../../../index'

describe('[core] Vec3', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Vec3(9, 8, 7)

      expect(point.x).toStrictEqual(9)
      expect(point.y).toStrictEqual(8)
      expect(point.z).toStrictEqual(7)
    })
  })
})
